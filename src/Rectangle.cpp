/**
* @Rectangle.cpp
* @Dikdörtgen sınıfının çizim ve kayıt işlemlerinin uygulaması
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @20.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#include "Rectangle.hpp"
#include <fstream>

using namespace std;

Rectangle::Rectangle(int _x, int _y, int _z, int _w, int _h, char _sym)
    : Sekil(_x, _y, _z, _sym), genislik(_w), yukseklik(_h) {}

void Rectangle::sekilCiz(char ekranMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK], int derinlikMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK]) {
    for (int i = 0; i < yukseklik; ++i) {
        for (int j = 0; j < genislik; ++j) {
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

void Rectangle::kaydet(ofstream& dosya) {
    dosya << "R " << x << " " << y << " " << z << " " << karakter << " " << genislik << " " << yukseklik << endl;
}