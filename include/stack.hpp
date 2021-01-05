/**
* @stack.hpp
* @stack başlık dosyası
* @Veri Yapıları
* @Final
* @02.09.2020
* @Şule Akçay
*/


#ifndef STACK_HPP
#define STACK_HPP
using namespace std;
#include <iostream>

class Stack{
public:
    char* elemanlar;
    int stackBasi;
    int elemanSayisi;
    int kapasite;
    char pop();
    const char& top()const;
    bool dolumu();
    void yerAc(int);
    Stack();
    bool isEmpty()const;
    void push(const char&);

};
#endif