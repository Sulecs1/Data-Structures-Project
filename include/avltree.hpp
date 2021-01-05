/**
* @avltree.hpp
* @avltree baslık dosyası
* @Veri Yapıları
* @Final
* @02.09.2020
* @Şule Akçay
*/

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "Kisi.hpp"
#include "node.hpp"
#include "stack.hpp"
#include <iostream>
#include <cmath>
using namespace std;

class AVLTree{
public:
    Node* root;

    Node* AraveEkle(Node* , Kisi*);
    Node* SolCocukIleDegistir(Node*);
    Node* SagCocukIleDegistir(Node*);
    void Postorder(Node*);
    void SeviyeyiYazdir(Node*, int);
    int Yukseklik(Node*);

    AVLTree();
    bool Bosmu();
    void Ekle(Kisi*);
    void Postorder();
    int Yukseklik();
};

#endif