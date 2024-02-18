/** 
* @file Yardimci.hpp
* @description  Yardimci sınıfında bulunan fonksiyonları tanımladığım hpp dosyası
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#ifndef YARDIMCI_HPP
#define YARDIMCI_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include "Yigin.hpp"

class Yardimci {
public:
    static int enKucukTepeElemaniYiginIndex(Yigin** yiginlar, int boyut);
    static int enBuyukTepeElemaniYiginIndex(Yigin** yiginlar, int boyut);
    static int SatirSayisi();
};

#endif 