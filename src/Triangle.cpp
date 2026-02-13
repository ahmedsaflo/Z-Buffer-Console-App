/**
* @Triangle.cpp
* @Üçgen sınıfının çizim ve kayıt işlemlerinin uygulaması
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#include "Triangle.hpp"

Triangle::Triangle(int _x, int _y, int _z, int _h, char _krktr)
    : Sekil(_x, _y, _z, _krktr), yukseklik(_h) {}

void Triangle::sekilCiz(char ekranMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK], int derinlikMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK]) {
    for (int i = 0; i < yukseklik; ++i) {
        for (int j = -i; j <= i; ++j) {
            int ciz_Y = y + i;
            int ciz_X = x + j;

            if (ciz_X >= 0 && ciz_X < EKRAN_GENISLIK && ciz_Y >= 0 && ciz_Y < EKRAN_YUKSEKLIK) {
                if (z >= derinlikMatrisi[ciz_Y][ciz_X]) {
                    ekranMatrisi[ciz_Y][ciz_X] = karakter;
                    derinlikMatrisi[ciz_Y][ciz_X] = z;
                }
            }
        }
    }
}

void Triangle::kaydet(ofstream& dosya) {
    dosya << "T " << x << " " << y << " " << z << " " << karakter << " " << yukseklik << endl;
}