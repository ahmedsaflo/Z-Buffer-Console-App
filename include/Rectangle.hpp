/**
* @Rectangle.hpp
* @Şekil sınıfından türetilen dikdörtgen sınıfının tanımı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Sekil.hpp"
#include <fstream>

using namespace std;

class Rectangle : public Sekil {
private:
    int genislik, yukseklik;

public:
    Rectangle(int _x, int _y, int _z, int _w, int _h, char _krktr);
    void sekilCiz(char ekranMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK], int derinlikMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK]) override;
    void kaydet(ofstream &dosya);
};

#endif