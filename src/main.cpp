/**
* @main.cpp
* @Programın giriş noktası, menü, dosya işlemleri ve ana döngü
* @Veri Yapıları 2. Öğretim B grubu
* @1. Ödev
* @21.11.2025
* @AHMAD SAFLO - ahmad.saflo@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Sabitler.hpp"
#include "Sekil.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Star.hpp"
#include "CiftYonluListe.hpp"
#include "EkranYonetici.hpp"

using namespace std;

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

const string KAYIT_DOSYASI = "veri.txt";
void dosyadanOku(CiftYonluListe* anaListe) {
    ifstream dosya(KAYIT_DOSYASI);
    if (!dosya.is_open()) {
        cout << "Kayitli dosya bulunamadi! Yeni olusturuluyor..." << endl;
        return;
    }

    int dllDugumSayisi;
    dosya >> dllDugumSayisi; 

    for (int i = 0; i < dllDugumSayisi; ++i) {
        anaListe->yeniDugumEkle(); 
        
        ListeDugumu* sonDugum = anaListe->getIlk();
        while(sonDugum->sonraki != nullptr) sonDugum = sonDugum->sonraki;

        int sllSekilSayisi;
        dosya >> sllSekilSayisi; 

        for (int j = 0; j < sllSekilSayisi; ++j) {
            char tur;
            int x, y, z;
            char sembol;
            
            dosya >> tur >> x >> y >> z >> sembol;

            Sekil* yeniSekil = nullptr;

            if (tur == 'R') {
                int w, h;
                dosya >> w >> h;
                yeniSekil = new Rectangle(x, y, z, w, h, sembol);
            } 
            else if (tur == 'T') {
                int h;
                dosya >> h;
                yeniSekil = new Triangle(x, y, z, h, sembol);
            } 
            else if (tur == 'S') {
                int h;
                dosya >> h;
                yeniSekil = new Star(x, y, z, h, sembol);
            }

            if (yeniSekil != nullptr) {
                sonDugum->veri->ekle(yeniSekil);
            }
        }
    }
    dosya.close();
    cout << "Veriler dosyadan basariyla yuklendi!" << endl;
}

Sekil* rastgeleSekilUret() {
    const char semboller[] = "@%&?$#+o";
    char rastgeleSembol = semboller[rand() % 8];

    int tur = rand() % 3; 
    int x = rand() % (EKRAN_GENISLIK - 10);
    int y = rand() % (EKRAN_YUKSEKLIK - 5);
    int z = rand() % 10; 
    
    if (tur == 0) { 
        int w = 3 + rand() % 6; 
        int h = 3 + rand() % 4; 
        return new Rectangle(x, y, z, w, h, rastgeleSembol);
    } else if (tur == 1) { 
        int h = 3 + rand() % 5; 
        return new Triangle(x, y, z, h, rastgeleSembol);
    } else { 
        int h = 3 + rand() % 4;
        return new Star(x, y, z, h, rastgeleSembol);
    }
}
void rastgeleDoldur(CiftYonluListe* anaListe) {
    for (int i = 0; i < 20; ++i) {
        anaListe->yeniDugumEkle(); 
        
        ListeDugumu* sonEklenen = anaListe->getIlk();
        while(sonEklenen->sonraki != nullptr) {
            sonEklenen = sonEklenen->sonraki;
        }

        int sekilSayisi = 2 + rand() % 6; 
        for (int j = 0; j < sekilSayisi; ++j) {
            sonEklenen->veri->ekle(rastgeleSekilUret());
        }
    }
}

int main() {
    srand(time(0)); 

    CiftYonluListe* anaListe = new CiftYonluListe();
    EkranYonetici ekran;

    cout << "Veri Yapilari Projesi - Sekil Yonetim Sistemi" << endl;
    cout << "1. Rastgele Olustur" << endl;
    cout << "2. Dosyadan Oku (" << KAYIT_DOSYASI << ")" << endl;
    cout << "Seciminiz: ";
    int secim;
    cin >> secim;

    if (secim == 1) {
        rastgeleDoldur(anaListe);
    } else if (secim == 2) {
        dosyadanOku(anaListe);
        if (anaListe->getIlk() == nullptr) {
             cout << "Dosya bos veya okunamadi, rastgele olusturuluyor..." << endl;
             rastgeleDoldur(anaListe);
        }
    } else {
        rastgeleDoldur(anaListe);
    }

    ListeDugumu* seciliListeDugumu = anaListe->getIlk(); 
    int seciliSekilIndis = 0; 
    int aktifMod = 1; 
    bool devam = true;

    while (devam) {
        ekran.temizle();

        if (seciliListeDugumu != nullptr) {
            ekran.sekilleriTamponaYukle(seciliListeDugumu->veri);
            
        } else {
             if(anaListe->getIlk() != nullptr) {
                 seciliListeDugumu = anaListe->getIlk();
             }
        }

        ekran.ekranaCiz(anaListe, seciliListeDugumu, aktifMod);

        char islem = getch();

        if (aktifMod == 1) {
            if (islem == 'w' || islem == 'W') { 
                if (seciliListeDugumu && seciliListeDugumu->onceki)
                    seciliListeDugumu = seciliListeDugumu->onceki;
            }
            else if (islem == 's' || islem == 'S') { 
                if (seciliListeDugumu && seciliListeDugumu->sonraki)
                    seciliListeDugumu = seciliListeDugumu->sonraki;
            }
            else if (islem == 'f' || islem == 'F') { 
                if (seciliListeDugumu && seciliListeDugumu->veri->elemanSayisi() > 0) {
                    aktifMod = 2;
                    seciliSekilIndis = 0; 
                }
            }
            else if (islem == 'c' || islem == 'C') { 
                if (seciliListeDugumu) {
                    ListeDugumu* silinecek = seciliListeDugumu;
                    if (silinecek->sonraki) seciliListeDugumu = silinecek->sonraki;
                    else seciliListeDugumu = silinecek->onceki;
                    
                    anaListe->dugumSil(silinecek);
                    
                    if (anaListe->getIlk() == nullptr) {
                        cout << "\nTüm liste silindi! Programdan cikiliyor..." << endl;
                        devam = false;
                    }
                }
            }
            else if (islem == 27) { 
                devam = false;
            }
        }
        else if (aktifMod == 2) {
            if (seciliListeDugumu == nullptr) {
                aktifMod = 1;
                continue;
            }

            Sekil* aktifSekil = seciliListeDugumu->veri->getSekil(seciliSekilIndis);
            
            if (aktifSekil == nullptr) {
                aktifMod = 1; 
                continue; 
            }

            if (islem == 'a' || islem == 'A') aktifSekil->konumDegistir(-1, 0); 
            else if (islem == 'd' || islem == 'D') aktifSekil->konumDegistir(1, 0); 
            else if (islem == 'w' || islem == 'W') aktifSekil->konumDegistir(0, -1);
            else if (islem == 's' || islem == 'S') aktifSekil->konumDegistir(0, 1); 
            
            else if (islem == 'q' || islem == 'Q') { 
                if (seciliSekilIndis > 0) seciliSekilIndis--;
            }
            else if (islem == 'e' || islem == 'E') { 
                if (seciliSekilIndis < seciliListeDugumu->veri->elemanSayisi() - 1) 
                    seciliSekilIndis++;
            }
            
            else if (islem == 'g' || islem == 'G') {
                aktifMod = 1;
            }
            
            else if (islem == 'c' || islem == 'C') {
                seciliListeDugumu->veri->sil(seciliSekilIndis);
                
                if (seciliListeDugumu->veri->elemanSayisi() == 0) {
                    ListeDugumu* silinecek = seciliListeDugumu;
                    if (silinecek->sonraki) seciliListeDugumu = silinecek->sonraki;
                    else seciliListeDugumu = silinecek->onceki;
                    
                    anaListe->dugumSil(silinecek);
                    aktifMod = 1; 
                } else {
                    if (seciliSekilIndis >= seciliListeDugumu->veri->elemanSayisi()) {
                        seciliSekilIndis = seciliListeDugumu->veri->elemanSayisi() - 1;
                    }
                }
            }
        }
    }

    cout << "Program kapatiliyor ve veriler kaydediliyor..." << endl;
    anaListe->dosyaYazdir(KAYIT_DOSYASI);
    
    delete anaListe;
    return 0;
}