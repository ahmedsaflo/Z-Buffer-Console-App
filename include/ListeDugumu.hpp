/**
* @ListeDugumu.hpp
* @Çift yönlü bağlı listede kullanılan liste verisi tutan düğüm yapısı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/
#ifndef LISTEDUGUMU_HPP
#define LISTEDUGUMU_HPP

#include "TekYonluListe.hpp"

using namespace std;

class ListeDugumu {
public:
    TekYonluListe* veri;    
    ListeDugumu* sonraki;   
    ListeDugumu* onceki;    

    ListeDugumu() {
        veri = new TekYonluListe(); 
        sonraki = nullptr;
        onceki = nullptr;
    }

    ~ListeDugumu() {
        if (veri != nullptr) {
            delete veri; 
        }
    }
};

#endif