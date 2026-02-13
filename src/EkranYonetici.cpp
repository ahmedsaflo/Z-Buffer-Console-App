/**
* @EkranYonetici.cpp
* @Ekran tamponuna şekillerin işlenmesi ve yazdırma işlemleri
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @22.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/
#include "EkranYonetici.hpp"
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

EkranYonetici::EkranYonetici() {
    temizle();
}

void EkranYonetici::imleciBasaAl() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void EkranYonetici::temizle() {
    for (int i = 0; i < EKRAN_YUKSEKLIK; ++i) {
        for (int j = 0; j < EKRAN_GENISLIK; ++j) {
            ekranTamponu[i][j] = ' ';
            zTamponu[i][j] = -1;
        }
    }
}

void EkranYonetici::sekilleriTamponaYukle(TekYonluListe* liste) {
    if (liste == nullptr) return;

    SekilDugumu* gezen = liste->getIlk();
    while (gezen != nullptr) {
        if (gezen->veri != nullptr) {
            gezen->veri->sekilCiz(ekranTamponu, zTamponu);
        }
        gezen = gezen->sonraki;
    }
}

void EkranYonetici::ekranaCiz(CiftYonluListe* anaListe, ListeDugumu* seciliDugum, int aktifMod) {
    imleciBasaAl();

    int seciliIndis = 0;
    ListeDugumu* temp = anaListe->getIlk();
    while (temp != nullptr) {
        if (temp == seciliDugum) break;
        temp = temp->sonraki;
        seciliIndis++;
    }
    int sayfaBaslangic = (seciliIndis / 6) * 6;

    for (int i = 0; i < EKRAN_YUKSEKLIK; ++i) {
        
        int kutuSiraNo = i / 4; 
        int kutuIciSatir = i % 4;
        int hedefIndis = sayfaBaslangic + kutuSiraNo;

        ListeDugumu* cizilecekDugum = anaListe->getIlk();
        int sayac = 0;
        bool dugumVar = false;
        
        while(cizilecekDugum != nullptr) {
            if (sayac == hedefIndis) {
                dugumVar = true;
                break;
            }
            cizilecekDugum = cizilecekDugum->sonraki;
            sayac++;
        }

        if (kutuSiraNo < 6 && dugumVar) {
            bool seciliMi = (cizilecekDugum == seciliDugum);
            
            if (kutuIciSatir == 0) { 
                if(seciliMi) cout << " ************* "; 
                else         cout << " +-----------+ ";
            } 
            else if (kutuIciSatir == 1) { 
                if(seciliMi && aktifMod == 1) cout << "->| ";
                else if(seciliMi && aktifMod == 2) cout << " *| ";
                else cout << "  | ";
                
                cout << cizilecekDugum << " | "; 
                cout << "\r"; 
                if(seciliMi && aktifMod==1) cout << ">";
                else cout << " ";
                
                cout << "|" << setw(6) << cizilecekDugum->veri->elemanSayisi() << "     | " ; 
            } 
            else if (kutuIciSatir == 2) { 
                if(seciliMi) cout << " ************* ";
                else         cout << " +-----------+ ";
            } 
            else { 
                cout << "               "; 
            }
        } else {
            cout << "               ";
        }

        cout << " || ";
        for (int j = 0; j < EKRAN_GENISLIK; ++j) {
            cout << ekranTamponu[i][j];
        }
        cout << endl;
    }

    cout << string(120, '=') << endl;
    cout << "Dugum: " << seciliIndis + 1 << " / " << "Sayfa: " << (seciliIndis/6)+1 << endl;
    if(aktifMod == 1) 
        cout << "MOD 1: [W/S] Gezin | [F] Iceri Gir | [C] Sil | [ESC] Cikis";
    else 
        cout << "MOD 2: [W/A/S/D] Tasi | [Q/E] Sekil Sec | [C] Sekil Sil | [G] Geri Don";
    cout << endl;
}