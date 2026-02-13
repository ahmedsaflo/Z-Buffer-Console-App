/**
* @SekilDugumu.hpp
* @Tek yönlü bağlı listede kullanılan şekil verisi tutan düğüm yapısı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#ifndef SEKILDUGUMU_HPP
#define SEKILDUGUMU_HPP

#include "Sekil.hpp"
#include <iostream>

using namespace std;

class SekilDugumu {
public:
    Sekil* veri;
    SekilDugumu* sonraki;

    SekilDugumu(Sekil* _veri) {
        veri = _veri;
        sonraki = nullptr;
    }

    ~SekilDugumu() {
        if (veri != nullptr) {
            delete veri;
        }
    }
};

#endif