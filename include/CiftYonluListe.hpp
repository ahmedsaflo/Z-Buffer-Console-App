/**
* @CiftYonluListe.hpp
* @Tek yönlü listeleri düğüm olarak saklayan çift yönlü bağlı liste yapısının sınıf tanımı
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @20.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/
#ifndef CIFTYONLULISTE_HPP
#define CIFTYONLULISTE_HPP

#include "ListeDugumu.hpp"

class CiftYonluListe {
private:
    ListeDugumu* ilk;

public:
    CiftYonluListe();
    ~CiftYonluListe();

    void ekle(TekYonluListe* liste); 
    void yeniDugumEkle();
    void dugumSil(ListeDugumu* dugum);
    void dosyaYazdir(string dosyaAdi);
    ListeDugumu* getIlk() const;
};

#endif