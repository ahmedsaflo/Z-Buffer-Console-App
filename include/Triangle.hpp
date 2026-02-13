/**
* @Triangle.hpp
* @Şekil sınıfından türetilen üçgen sınıfının tanımı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Sekil.hpp"

using namespace std;

class Triangle : public Sekil {
private:
    int yukseklik;

public:
    Triangle(int _x, int _y, int _z, int _h, char _krktr);
    void sekilCiz(char ekranMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK], int derinlikMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK]) override;
    void kaydet(ofstream &dosya);
};

#endif