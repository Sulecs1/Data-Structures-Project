/**
* @avltree.cpp
* @avltree kaynak dosyası
* @Veri Yapıları
* @Final
* @02.09.2020
* @Şule Akçay
*/

#include "avltree.hpp"
#include "node.hpp"
#include <cmath>
#include <iostream>
#include "stack.hpp"
#include "Kisi.hpp"
using namespace std;

Node* AVLTree::AraveEkle(Node* sub_Node, Kisi* new_one){
    int ilk_yukseklik = Yukseklik(sub_Node);
    
    if(sub_Node == NULL){
        sub_Node = new Node(new_one);
    }
    else if(new_one->yas <= sub_Node->data->yas){
        sub_Node->left = AraveEkle(sub_Node->left, new_one);
        if(Yukseklik(sub_Node->left) - Yukseklik(sub_Node->right) == 2){
            if(new_one->yas < sub_Node->left->data->yas){
                sub_Node = SolCocukIleDegistir(sub_Node);
                sub_Node->stack.push('Y');
            }
            else{
                sub_Node->left = SagCocukIleDegistir(sub_Node->left);
                sub_Node = SolCocukIleDegistir(sub_Node);
                sub_Node->stack.push('Y');
            }
        }
    }
    else if(new_one->yas > sub_Node->data->yas){
        sub_Node->right = AraveEkle(sub_Node->right, new_one);
        if(Yukseklik(sub_Node->right) - Yukseklik(sub_Node->left) == 2){
            if(new_one->yas > sub_Node->right->data->yas){
                sub_Node = SagCocukIleDegistir(sub_Node);
                sub_Node->stack.push('Y');
            }
            else{
                // Sol Sag Durumu 
                sub_Node->right = SolCocukIleDegistir(sub_Node->right);
                sub_Node = SagCocukIleDegistir(sub_Node);
                sub_Node->stack.push('Y');
            }
        }
    }
    else;
    if(sub_Node->height == Yukseklik(sub_Node)) sub_Node->stack.push('D');
    sub_Node->height = Yukseklik(sub_Node);

    return sub_Node;
}

Node* AVLTree::SolCocukIleDegistir(Node* sub_Node){

    Node* tmp = sub_Node->left;
    sub_Node->left = tmp->right;
    tmp->right = sub_Node;

    // Yukseklikleri Guncelle
    sub_Node->height = Yukseklik(sub_Node);
    tmp->height = max(Yukseklik(tmp->left), sub_Node->height) + 1;
    sub_Node->stack.push('A');
    return tmp;
}

Node* AVLTree::SagCocukIleDegistir(Node* sub_Node){

    Node* tmp = sub_Node->right;
    sub_Node->right = tmp->left;
    tmp->left = sub_Node;

    sub_Node->height = Yukseklik(sub_Node);
    tmp->height = max(Yukseklik(tmp->right), sub_Node->height)+1;
    sub_Node->stack.push('A');
    return tmp;
}

void AVLTree::Postorder(Node* sub_Node){
    if(sub_Node != NULL){
        Postorder(sub_Node->left);
        Postorder(sub_Node->right);
        cout<<sub_Node->data->isim<<", "<<sub_Node->data->dogum_yili<<", "<<sub_Node->data->kilo<<"  Yigit: "<< sub_Node->stack.pop()<<endl;
    }
}

void AVLTree::SeviyeyiYazdir(Node* sub_Node, int seviye){
    if(sub_Node == NULL) return;
    if(seviye == 0) cout<<sub_Node->data<<" ";
    else{
        SeviyeyiYazdir(sub_Node->left, seviye-1);
        SeviyeyiYazdir(sub_Node->right, seviye-1);
    }
}

int AVLTree::Yukseklik(Node* sub_Node){
    if(sub_Node == NULL) return -1;
    return 1+max(Yukseklik(sub_Node->left), Yukseklik(sub_Node->right));
}

AVLTree::AVLTree(){
    root = NULL;
}

bool AVLTree::Bosmu(){
    return root == NULL;
}

void AVLTree::Ekle(Kisi* yeni){
    root = AraveEkle(root, yeni);
}

void AVLTree::Postorder(){
    Postorder(root);
}

int AVLTree::Yukseklik(){
    return Yukseklik(root);
}