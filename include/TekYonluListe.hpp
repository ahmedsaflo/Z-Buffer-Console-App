/**
* @TekYonluListe.hpp
* @Şekil nesnelerini saklayan tek yönlü bağlı liste yapısının sınıf tanımı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/
#ifndef TEKYONLULISTE_HPP
#define TEKYONLULISTE_HPP

#include "SekilDugumu.hpp"

using namespace std;

class TekYonluListe {
private:
    SekilDugumu* ilk; 

public:
    TekYonluListe();
    ~TekYonluListe();

    void ekle(Sekil* sekil);         
    void sil(int indis);             
    Sekil* getSekil(int indis);      
    int elemanSayisi() const;        
    SekilDugumu* getIlk() const;     
    void yazdir();                   
    void dosyaYazdir(ofstream& dosya);
};

#endif