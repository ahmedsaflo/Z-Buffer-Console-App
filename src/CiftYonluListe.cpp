/**
* @CiftYonluListe.cpp
* @Çift yönlü liste işlemlerinin kodlandığı dosya
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/
#include "CiftYonluListe.hpp"

CiftYonluListe::CiftYonluListe() {
    ilk = nullptr;
}

CiftYonluListe::~CiftYonluListe() {
    ListeDugumu* gecici = ilk;
    while (gecici != nullptr) {
        ListeDugumu* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}

void CiftYonluListe::ekle(TekYonluListe* liste) {

}

void CiftYonluListe::yeniDugumEkle() {
    ListeDugumu* yeni = new ListeDugumu();
    if (ilk == nullptr) {
        ilk = yeni;
        return;
    }
    ListeDugumu* gecici = ilk;
    while (gecici->sonraki != nullptr) {
        gecici = gecici->sonraki;
    }
    gecici->sonraki = yeni;
    yeni->onceki = gecici;
}

void CiftYonluListe::dugumSil(ListeDugumu* silinecek) {
    if (silinecek == nullptr || ilk == nullptr) return;

    if (silinecek == ilk) {
        ilk = ilk->sonraki;
        if (ilk != nullptr) {
            ilk->onceki = nullptr;
        }
    } else {
        if (silinecek->onceki != nullptr) {
            silinecek->onceki->sonraki = silinecek->sonraki;
        }
        if (silinecek->sonraki != nullptr) {
            silinecek->sonraki->onceki = silinecek->onceki;
        }
    }
    delete silinecek;
}

ListeDugumu* CiftYonluListe::getIlk() const {
    return ilk;
}

void CiftYonluListe::dosyaYazdir(string dosyaAdi) {
    ofstream dosya(dosyaAdi); 
    if (!dosya.is_open()) return;

    int dugumSayisi = 0;
    ListeDugumu* sayac = ilk;
    while(sayac != nullptr) { dugumSayisi++; sayac = sayac->sonraki; }
    
    dosya << dugumSayisi << endl;

    ListeDugumu* gezen = ilk;
    while (gezen != nullptr) {
        gezen->veri->dosyaYazdir(dosya);
        gezen = gezen->sonraki;
    }
    
    dosya.close();
}