/**
* @stack.cpp
* @stack kaynak dosyası
* @Veri Yapıları
* @Final
* @02.09.2020
* @Şule Akçay
*/

using namespace std;

#include "stack.hpp"
#include "node.hpp"
#include <iostream>

bool Stack::dolumu(){
    return elemanSayisi == kapasite;
}

void Stack::yerAc(int boyut){
    char* tmp = new char[boyut];
    for(int j=0; j<elemanSayisi; j++) tmp[j] = elemanlar[j];
    if(elemanlar != NULL) delete [] elemanlar;
    elemanlar = tmp;
    kapasite = boyut;
}
const char& Stack::top()const{
    return elemanlar[stackBasi];
}

bool Stack::isEmpty()const{
    return stackBasi == -1;
}

Stack::Stack(){
    elemanlar = NULL;
    stackBasi = -1;
    elemanSayisi = 0;
    kapasite = 0;
}

void Stack::push(const char& eleman){
    if(dolumu()){
        yerAc(max(1, 2*kapasite));
    }
    stackBasi++;
    elemanlar[stackBasi] = eleman;
    elemanSayisi++;
}

char Stack::pop(){
    char elemanim;
    while (true)
    {
        elemanim = top();
        stackBasi--;
        elemanSayisi--;
        if(elemanSayisi == 0) break;
        cout<<elemanim<<" ";
    }
    return elemanim;
}


