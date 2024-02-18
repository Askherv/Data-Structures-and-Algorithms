/** 
* @file Yigin.cpp
* @description  Yığın işlemlerinin ve ilgili fonksiyonların bulunduğu Yigin sınıfı
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#include "yigin.hpp"

Yigin::Yigin() {
    tepe = nullptr;
}

bool Yigin::yiginBosMu() {
    return tepe == nullptr;
}

void Yigin::ekle(int veri) {
    tepe = new YDugum(veri, tepe);
}

int Yigin::elemanSayisi() {
    int sayac = 0;
    YDugum *iter = tepe;
    while (iter != nullptr) {
        sayac++;
        iter = iter->sonraki;
    }
    return sayac;
}

void Yigin::tepeElemaniSil() {
    if (yiginBosMu()) throw "Stack bos";
    YDugum *tmp = tepe;
    tepe = tepe->sonraki;
    delete tmp;
}

int Yigin::tepeElemaniGetir() {
    if (yiginBosMu()) throw "Stack bos";
    return tepe->veri;
}

void Yigin::temizle() {
    while (!yiginBosMu()) tepeElemaniSil();
}

Yigin *Yigin::kopyalaYigin() {
    if (this->yiginBosMu()) {
        return new Yigin();
    }

    Yigin *yeniYigin = new Yigin();

    YDugum *iter = this->tepe;
    YDugum *kopyaTepe = nullptr;
    YDugum *kopyaIter = nullptr;

    while (iter != nullptr) {
        if (kopyaTepe == nullptr) {
            kopyaTepe = new YDugum(iter->veri);
            kopyaIter = kopyaTepe;
        } else {
            kopyaIter->sonraki = new YDugum(iter->veri);
            kopyaIter = kopyaIter->sonraki;
        }
        iter = iter->sonraki;
    }

    yeniYigin->tepe = kopyaTepe;
    return yeniYigin;
}

Yigin::~Yigin() {
    temizle();
}
