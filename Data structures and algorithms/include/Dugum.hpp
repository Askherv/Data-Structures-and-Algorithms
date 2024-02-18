/** 
* @file Dugum.hpp
* @description  Dugum sınıfında bulunan fonksiyonları tanımladığım hpp dosyası
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum {
public:
    Dugum(int veri, Dugum* sl = nullptr, Dugum* sg = nullptr);

    int veri;
    Dugum* sol;
    Dugum* sag;
    int yukseklik;
};

#endif 
