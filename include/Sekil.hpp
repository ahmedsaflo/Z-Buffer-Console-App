/**
* @Sekil.hpp
* @Tüm şekillerin türetildiği soyut temel sınıfın tanımı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#ifndef SEKIL_HPP
#define SEKIL_HPP

#include "Sabitler.hpp"
#include <fstream>

using namespace std;

class Sekil {
protected:
    int x, y;       
    int z;          
    char karakter;    

public:
    Sekil(int _x, int _y, int _z, char _karakter) 
        : x(_x), y(_y), z(_z), karakter(_karakter) {}

    virtual ~Sekil() {} 

    void konumDegistir(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }
    virtual void sekilCiz(char ekranMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK], int derinlikMatrisi[EKRAN_YUKSEKLIK][EKRAN_GENISLIK]) = 0;
    virtual void kaydet(ofstream& dosya) = 0;
};

#endif