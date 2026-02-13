/**
* @Star.cpp
* @Yıldız sınıfının çizim ve kayıt işlemlerinin uygulaması
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#include "Star.hpp"

Star::Star(int _x, int _y, int _z, int _h, char _krktr)
    : Sekil(_x, _y, _z, _krktr), yukseklik(_h) {}

void Star::sekilCiz(char ekranMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK], int derinlikMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK]) {
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

    int baslaY = y + yukseklik; 
    for (int i = yukseklik - 2; i >= 0; --i) { 
        for (int j = -i; j <= i; ++j) {
            int ciz_Y = baslaY + (yukseklik - 2 - i); 
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

void Star::kaydet(ofstream& dosya) {
    dosya << "S " << x << " " << y << " " << z << " " << karakter << " " << yukseklik << endl;
}