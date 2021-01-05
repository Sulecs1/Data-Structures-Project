/**
* @Kisi.cpp
* @Kisi kaynak dosyası
* @Veri Yapıları
* @Final
* @02.09.2020
* @Şule Akçay
*/

#include "Kisi.hpp"
#include <iostream>
#include "node.hpp"
using namespace std;

Kisi::Kisi(string ism = NULL, int dy = NULL, int kl = NULL){
    isim = ism;
    dogum_yili = dy;
    kilo = kl;
    yas = 2020 - dy;
}
