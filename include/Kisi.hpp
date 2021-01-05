/**
* @Kisi.hpp
* @Kisi başlık dosyası
* @Veri Yapıları
* @Final
* @02.09.2020
* @Şule Akçay
*/
#ifndef KISI_HPP
#define KISI_HPP
#include "stack.hpp"
#include <iostream>
using namespace std;

class Kisi{
public:
    string isim;
    int dogum_yili;
    int kilo;
    int yas;
    Kisi(string , int, int);
};

#endif