/** 
* @file main.cpp
* @description Main fonksiyonu, dosya okuma işlemleri, yığın ve ağaç üzerindeki işlemlerin gerçekleştiği dosya
* @course 1.Ogretim A gubu
* @assignment 2.Ödev
* @date 23.12.2023
* @author Nihad Asgarov , nihad.asgarov@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include <iomanip>
#include "AVLAgaci.hpp"
#include "Yardimci.hpp"
#include "Yigin.hpp"

using namespace std;

int main(){
	int dosyadakiSatirSayisi=Yardimci::SatirSayisi();
	
	ifstream dosya("Veri.txt");
	if(dosya.is_open()){
		
		string satir;
		AVLAgaci* *agaclar=new AVLAgaci*[dosyadakiSatirSayisi];
		int agacSayisi=0;
		
		while(std::getline(dosya,satir)){
			
			int siradakiSayi;
			stringstream satirOkuyucu(satir);
			agaclar[agacSayisi]=new AVLAgaci();
			
			while(satirOkuyucu>>siradakiSayi){	
				agaclar[agacSayisi]->Ekle(siradakiSayi);	
			}
			agacSayisi++;	
		}
		
		for(int i=0;i<dosyadakiSatirSayisi;i++){
		cout<<agaclar[i]->AVLToplamDugumDeger(agaclar[i]->toplamDugumDegerleri());	
		}	
		system("CLS");
		
			
		Yigin* *yiginlar=new Yigin*[agacSayisi];
		int yiginSayisi=0;
		for(int i=0;i<agacSayisi;i++){
			yiginlar[i]=new Yigin();
			agaclar[i]->YapraklariYiginaEkle(yiginlar[i]);
			yiginSayisi++;		
		}
			
		Yigin** originalYiginlar = new Yigin*[agacSayisi];
		int kopyaYiginSayisi=yiginSayisi;
		for (int i = 0; i < agacSayisi;i++) {
			if (yiginlar[i] != nullptr) {
				originalYiginlar[i] = yiginlar[i]->kopyalaYigin();
			} else {
				originalYiginlar[i] = nullptr;
			}
		}
			
	while(true){
        while(kopyaYiginSayisi>1){
			
			int minIndex = Yardimci::enKucukTepeElemaniYiginIndex(originalYiginlar, agacSayisi);
			if (minIndex != -1) {
				originalYiginlar[minIndex]->tepeElemaniSil();	
			}
		 
			if(originalYiginlar[minIndex]->yiginBosMu()){
				delete yiginlar[minIndex];
				yiginlar[minIndex]=nullptr;
				kopyaYiginSayisi--;
				
				for (int i = 0; i < agacSayisi; i++) {
					if (yiginlar[i] != nullptr) {
						originalYiginlar[i] = yiginlar[i]->kopyalaYigin();
					} 
				} 		
				delete agaclar[minIndex];
				agaclar[minIndex]=nullptr;
				delete originalYiginlar[minIndex];
				originalYiginlar[minIndex]=nullptr;
				for(int k=0;k<agacSayisi;k++){
					if(agaclar[k] != nullptr){
						cout<<agaclar[k]->AVLToplamDugumDeger(agaclar[k]->toplamDugumDegerleri());					
					}
					
				}
				system("CLS");								    
			    break;
			}
         
			int maxIndex = Yardimci::enBuyukTepeElemaniYiginIndex(originalYiginlar, agacSayisi);
		
			if (maxIndex != -1) {
			    originalYiginlar[maxIndex]->tepeElemaniSil();
			}
			if(originalYiginlar[maxIndex]->yiginBosMu()){
				delete yiginlar[maxIndex];
				yiginlar[maxIndex]=nullptr;
				kopyaYiginSayisi--;
			
				for (int i = 0; i < agacSayisi; i++) {
					if (yiginlar[i] != nullptr) {
					originalYiginlar[i] = yiginlar[i]->kopyalaYigin();
				} 

				delete agaclar[maxIndex];
				agaclar[maxIndex]=nullptr;
                delete originalYiginlar[maxIndex];
                originalYiginlar[maxIndex] = nullptr;
				for(int k=0;k<agacSayisi;k++){
					if(agaclar[k] != nullptr){
					cout<<agaclar[k]->AVLToplamDugumDeger(agaclar[k]->toplamDugumDegerleri());	
					}
					
				}	
				system("CLS");			
				if(kopyaYiginSayisi==1) break;
              
            }
			
          
			}
       
      
        }
		
		if(kopyaYiginSayisi==1){
			break;
		}
    }
	
	int sonIndex=0;	
	for(int i=0;i<agacSayisi;i++){
		if(agaclar[i]!=nullptr){
		sonIndex=i;
		
		}
	}
	cout<<endl;
	cout<<setw(2);
	for(int i=0;i<32;i++){
		cout<<"=";
	}
	cout<<endl;
	cout<<" |                              |"<<endl;
	cout<<" |                              |"<<endl;
	cout<<" |"<<setw(19)<<"Son Karakter: "<<agaclar[sonIndex]->AVLToplamDugumDeger(agaclar[sonIndex]->toplamDugumDegerleri())<<setw(11)<<"|"<<endl;
	cout<<" |"<<setw(13)<<setprecision(6)<<"AVL NO"<<setw(6)<<": "<<sonIndex+1<<setw(11)<<"|"<<endl;
	cout<<" |                              |"<<endl;
	cout<<" |                              |"<<endl;	
	cout<<setw(2);
	for(int i=0;i<32;i++){
		cout<<"=";
	}
	
	delete agaclar[sonIndex];
	agaclar[sonIndex]=nullptr;
	delete agaclar[sonIndex];
	agaclar[sonIndex]=nullptr;
	delete agaclar[sonIndex];
	agaclar[sonIndex]=nullptr;
	delete[] yiginlar; 
	delete[] agaclar;
	delete[] originalYiginlar;
			
		
		
	}
	return 0;
}