/** 
* @file Yigin.hpp
* @description  Yigin sınıfında bulunan fonksiyonları tanımladığım hpp dosyası
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#ifndef YIGIN_HPP
#define YIGIN_HPP

#include "YDugum.hpp"

class Yigin {
private:
    YDugum *tepe;

public:
    Yigin();
    bool yiginBosMu();
    void ekle(int veri);
    int elemanSayisi();
    void tepeElemaniSil();
    int tepeElemaniGetir();
    void temizle();
    Yigin *kopyalaYigin();
    ~Yigin();
};

#endif 
