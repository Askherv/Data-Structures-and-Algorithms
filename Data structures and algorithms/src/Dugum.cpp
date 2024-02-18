/** 
* @file Dugum.cpp
* @description  AVL Ağacının düğümlerini oluştururken kullandığım Düğüm sınıfı
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

Dugum::Dugum(int veri, Dugum* sl, Dugum* sg) {
    this->veri = veri;
    sol = sl;
    sag = sg;
    yukseklik = 0;
}