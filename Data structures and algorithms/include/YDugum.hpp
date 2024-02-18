/** 
* @file YDugum.hpp
* @description  YDugum sınıfında bulunan fonksiyonları tanımladığım hpp dosyası
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#ifndef YDUGUM_HPP
#define YDUGUM_HPP

class YDugum {
public:
    YDugum(int veri, YDugum* sonraki = nullptr);

    int veri;
    YDugum* sonraki;
};

#endif 
