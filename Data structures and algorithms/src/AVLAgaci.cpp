/** 
* @file AVLAgaci.cpp
* @description  AVL Ağacı ile ilgili işlemlerin bulunduğu AVLAgaci sınıfı
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#include "AVLAgaci.hpp"
using namespace std;

AVLAgaci::AVLAgaci() {
    kok = nullptr;
}

AVLAgaci::~AVLAgaci() {
    Temizle();
}

bool AVLAgaci::bosMu() {
    return kok == nullptr;
}

void AVLAgaci::Temizle() {
    while (!bosMu()) {
        DugumSil(kok);
    }
}

bool AVLAgaci::Ara(int veri) {
    return Ara(kok, veri);
}

int AVLAgaci::Yukseklik() {
    return Yukseklik(kok);
}

void AVLAgaci::postorder() {
    yapraklar(kok);
}

bool AVLAgaci::bosMu() const {
    return kok == nullptr;
}

void AVLAgaci::Ekle(int veri) {
    kok = AraVeEkle(kok, veri);
}

int AVLAgaci::yapraklarToplam() {
    return yapraklarToplam(kok);
}

char AVLAgaci::AVLToplamDugumDeger(int sum) {
    int ascii = sum % (90 - 65 + 1) + 65;
    return static_cast<char>(ascii);
}

void AVLAgaci::YapraklariYiginaEkle(Yigin* yigin) {
    if (kok == nullptr) {
        yigin->temizle();
        return;
    }
    YapraklariYiginaEkle(kok, yigin);
}

int AVLAgaci::toplamDugumDegerleri() {
    return toplamDugumDegerleri(kok);
}

void AVLAgaci::yapraklar(Dugum* subNode) const {
    if (subNode == nullptr) return;

    if (subNode->sol == nullptr && subNode->sag == nullptr) {
        cout << subNode->veri << " ";
        return;
    }

    yapraklar(subNode->sol);
    yapraklar(subNode->sag);
}

Dugum* AVLAgaci::AraVeEkle(Dugum* subNode, int eklenecekVeri) {
    if (subNode == nullptr) subNode = new Dugum(eklenecekVeri);
    else if (eklenecekVeri < subNode->veri) {
        subNode->sol = AraVeEkle(subNode->sol, eklenecekVeri);

        if (Yukseklik(subNode->sol) == Yukseklik(subNode->sag) + 2) {
            if (eklenecekVeri < subNode->sol->veri)
                subNode = SolCocuklaDegistir(subNode);
            else {
                subNode->sol = SagCocuklaDegistir(subNode->sol);
                subNode = SolCocuklaDegistir(subNode);
            }
        }
    }
    else if (eklenecekVeri > subNode->veri) {
        subNode->sag = AraVeEkle(subNode->sag, eklenecekVeri);

        if (Yukseklik(subNode->sag) == Yukseklik(subNode->sol) + 2) {
            if (eklenecekVeri > subNode->sag->veri)
                subNode = SagCocuklaDegistir(subNode);
            else {
                subNode->sag = SolCocuklaDegistir(subNode->sag);
                subNode = SagCocuklaDegistir(subNode);
            }
        }
    }
    else;

    subNode->yukseklik = Yukseklik(subNode);
    return subNode;
}

Dugum* AVLAgaci::SolCocuklaDegistir(Dugum* subNode) {
    Dugum* tmp = subNode->sol;
    subNode->sol = tmp->sag;
    tmp->sag = subNode;

    subNode->yukseklik = Yukseklik(subNode);
    tmp->yukseklik = 1 + max(Yukseklik(tmp->sol), subNode->yukseklik);

    return tmp;
}

Dugum* AVLAgaci::SagCocuklaDegistir(Dugum* subNode) {
    Dugum* tmp = subNode->sag;
    subNode->sag = tmp->sol;
    tmp->sol = subNode;

    subNode->yukseklik = Yukseklik(subNode);
    tmp->yukseklik = 1 + max(Yukseklik(tmp->sag), subNode->yukseklik);

    return tmp;
}

void AVLAgaci::YapraklariYiginaEkle(Dugum* subNode, Yigin* yigin) {
    if (subNode == nullptr) return;

    if (subNode->sol == nullptr && subNode->sag == nullptr) {
        yigin->ekle(subNode->veri);
        return;
    }

    YapraklariYiginaEkle(subNode->sol, yigin);
    YapraklariYiginaEkle(subNode->sag, yigin);
}

bool AVLAgaci::Ara(Dugum* subNode, int arananVeri) {
    if (subNode == nullptr) return false;
    if (subNode->veri == arananVeri) return true;
    if (arananVeri < subNode->veri) return Ara(subNode->sol, arananVeri);
    else return Ara(subNode->sag, arananVeri);
}

bool AVLAgaci::DugumSil(Dugum*& subNode) {
    Dugum* delNode = subNode;

    if (subNode->sag == NULL) subNode = subNode->sol;
    else if (subNode->sol == NULL) subNode = subNode->sag;
    else {
        delNode = subNode->sol;
        Dugum* parentNode = subNode;
        while (delNode->sag != NULL) {
            parentNode = delNode;
            delNode = delNode->sag;
        }
        subNode->veri = delNode->veri;
        if (parentNode == subNode) subNode->sol = delNode->sol;
        else parentNode->sag = delNode->sol;
    }
    delete delNode;
    return true;
}

int AVLAgaci::yapraklarToplam(Dugum* subNode) {
    if (subNode == nullptr)
        return 0;

    if (subNode->sol == nullptr && subNode->sag == nullptr)
        return subNode->veri;

    return yapraklarToplam(subNode->sol) + yapraklarToplam(subNode->sag);
}

void AVLAgaci::postorder(Dugum* subNode) {
    if (subNode != nullptr) {
        postorder(subNode->sol);
        postorder(subNode->sag);
        cout << subNode->veri << " ";
    }
}

int AVLAgaci::toplamDugumDegerleri(Dugum* subNode) {
    if (subNode == nullptr) return 0;

    if (subNode->sol == nullptr && subNode->sag == nullptr) {
        return 0; 
    }

    return subNode->veri + toplamDugumDegerleri(subNode->sol) + toplamDugumDegerleri(subNode->sag);
}

int AVLAgaci::Yukseklik(Dugum* subNode) {
    if (subNode == nullptr) return -1;
    return 1 + max(Yukseklik(subNode->sol), Yukseklik(subNode->sag));
}
