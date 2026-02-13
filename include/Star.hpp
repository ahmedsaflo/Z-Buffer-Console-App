/**
* @Star.hpp
* @Şekil sınıfından türetilen yıldız sınıfının tanımı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#ifndef STAR_HPP
#define STAR_HPP

#include "Sekil.hpp"

using namespace std;

class Star : public Sekil {
private:
    int yukseklik; 
public:
    Star(int _x, int _y, int _z, int _h, char _krktr);
    void sekilCiz(char ekranMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK], int derinlikMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK]) override;
    void kaydet(ofstream &dosya);
};

#endif