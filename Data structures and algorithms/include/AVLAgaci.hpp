/** 
* @file AVLAgaci.hpp
* @description  AVLAgaci sınıfında bulunan fonksiyonları tanımladığım hpp dosyası
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#ifndef AVL_AGACI_HPP
#define AVL_AGACI_HPP

#include <iostream>
#include "Dugum.hpp" 
#include "Yigin.hpp"

class AVLAgaci {
public:
    AVLAgaci();
    ~AVLAgaci();

    bool bosMu();
    void Temizle();
    bool Ara(int veri);
    int Yukseklik();
    void postorder();
    bool bosMu() const;
    void Ekle(int veri);
    int yapraklarToplam();
    char AVLToplamDugumDeger(int sum);
    void YapraklariYiginaEkle(Yigin* yigin);
    int toplamDugumDegerleri();

private:
    Dugum* kok;
    void yapraklar(Dugum* subNode) const;
    Dugum* AraVeEkle(Dugum* subNode, int eklenecekVeri);
    Dugum* SolCocuklaDegistir(Dugum* subNode);
    Dugum* SagCocuklaDegistir(Dugum* subNode);
    void YapraklariYiginaEkle(Dugum* subNode, Yigin* yigin);
    bool Ara(Dugum* subNode, int arananVeri);
    bool DugumSil(Dugum*& subNode);
    int yapraklarToplam(Dugum* subNode);
    void postorder(Dugum* subNode);
    int toplamDugumDegerleri(Dugum* subNode);
    int Yukseklik(Dugum* subNode);
};

#endif 
