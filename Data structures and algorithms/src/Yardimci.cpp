/** 
* @file Yardimci.cpp
* @description Okunacak dosyadaki satır sayısını döndüren, en büyük ve en küçük tepe elemanı içeren yığınların indeksini döndüren fonksiyonların bulunduğu Yardimci sınıfım
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#include "Yardimci.hpp"
using namespace std;

int Yardimci::enKucukTepeElemaniYiginIndex(Yigin** yiginlar, int boyut) {
    int minIndex = -1;
    int minEleman = INT_MAX; 

    for (int i = 0; i < boyut; i++) {
        if (yiginlar[i] != nullptr && !yiginlar[i]->yiginBosMu()) {
            int tepeEleman = yiginlar[i]->tepeElemaniGetir();
            if (tepeEleman < minEleman) { 
                minEleman = tepeEleman;
                minIndex = i;
            }
        }
    }

    return minIndex;
}

int Yardimci::enBuyukTepeElemaniYiginIndex(Yigin** yiginlar, int boyut) {
    int maxIndex = -1;
    int maxEleman = INT_MIN;

    for (int i = 0; i < boyut; i++) {
        if (yiginlar[i] != nullptr && !yiginlar[i]->yiginBosMu()) {
            int tepeEleman = yiginlar[i]->tepeElemaniGetir();
            if (tepeEleman > maxEleman) {
                maxEleman = tepeEleman;
                maxIndex = i;
            }
        }
    }

    return maxIndex;
}

int Yardimci::SatirSayisi() {
    int satirSayisi = 0;
    ifstream dosya("Veri.txt");
    if (dosya.is_open()) {
        string satir;
        while (getline(dosya, satir)) {
            int siradakiSayi;
            stringstream satirOkuyucu(satir);
            while (satirOkuyucu >> siradakiSayi) {
                // İhtiyaç olmadığı için içini boş bıraktım
            }
            satirSayisi++;
        }
    }
    return satirSayisi;
}
