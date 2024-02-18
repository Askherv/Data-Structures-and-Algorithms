/** 
* @file YDugum.cpp
* @description  Yığının düğümlerini oluştururken kullandığım YDüğüm sınıfı
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#include "YDugum.hpp"

YDugum::YDugum(int veri, YDugum* sonraki) {
    this->veri = veri;
    this->sonraki = sonraki;
}