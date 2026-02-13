/**
* @TekYonluListe.cpp
* @Tek yönlü liste işlemlerinin kodlandığı dosya
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#include "TekYonluListe.hpp"

TekYonluListe::TekYonluListe() {
    ilk = nullptr;
}

TekYonluListe::~TekYonluListe() {
    SekilDugumu* gecici = ilk;
    while (gecici != nullptr) {
        SekilDugumu* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek; 
    }
}

void TekYonluListe::ekle(Sekil* sekil) {
    SekilDugumu* yeni = new SekilDugumu(sekil);
    if (ilk == nullptr) {
        ilk = yeni;
        return;
    }
    SekilDugumu* gecici = ilk;
    while (gecici->sonraki != nullptr) {
        gecici = gecici->sonraki;
    }
    gecici->sonraki = yeni;
}

void TekYonluListe::sil(int indis) {
    if (ilk == nullptr) return;

    if (indis == 0) {
        SekilDugumu* silinecek = ilk;
        ilk = ilk->sonraki;
        delete silinecek;
        return;
    }

    SekilDugumu* gecici = ilk;
    int sayac = 0;
    while (gecici != nullptr && sayac < indis - 1) {
        gecici = gecici->sonraki;
        sayac++;
    }

    if (gecici == nullptr || gecici->sonraki == nullptr) return;

    SekilDugumu* silinecek = gecici->sonraki;
    gecici->sonraki = silinecek->sonraki;
    delete silinecek;
}

Sekil* TekYonluListe::getSekil(int indis) {
    SekilDugumu* gecici = ilk;
    int sayac = 0;
    while (gecici != nullptr) {
        if (sayac == indis) return gecici->veri;
        gecici = gecici->sonraki;
        sayac++;
    }
    return nullptr;
}

int TekYonluListe::elemanSayisi() const {
    int sayac = 0;
    SekilDugumu* gecici = ilk;
    while (gecici != nullptr) {
        sayac++;
        gecici = gecici->sonraki;
    }
    return sayac;
}

SekilDugumu* TekYonluListe::getIlk() const {
    return ilk;
}

void TekYonluListe::dosyaYazdir(ofstream& dosya) {
    dosya << elemanSayisi() << endl;
    
    SekilDugumu* gezen = ilk;
    while (gezen != nullptr) {
        if (gezen->veri != nullptr) {
            gezen->veri->kaydet(dosya);
        }
        gezen = gezen->sonraki;
    }
}