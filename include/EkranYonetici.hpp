/**
* @EkranYonetici.hpp
* @Terminal ekranına çizim ve tampon yönetimi yapan sınıfın tanımı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @22.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#ifndef EKRANYONETICI_HPP
#define EKRANYONETICI_HPP

#include <iostream>
#include <iomanip> 
#include "Sabitler.hpp"
#include "CiftYonluListe.hpp"
#include "SekilDugumu.hpp"

using namespace std;

class EkranYonetici {
private:
    char ekranTamponu[EKRAN_YUKSEKLIK][EKRAN_GENISLIK]; 
    int zTamponu[EKRAN_YUKSEKLIK][EKRAN_GENISLIK];     
    void imleciBasaAl() const;

public:
    EkranYonetici();
    void temizle();
    void sekilleriTamponaYukle(TekYonluListe* liste);
    void ekranaCiz(CiftYonluListe* anaListe, ListeDugumu* seciliDugum, int aktifMod);
};

#endif