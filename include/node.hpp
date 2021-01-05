/**
* @node.cpp
* @node kaynak dosyası
* @Veri Yapıları
* @Final
* @02.09.2020
* @Şule Akçay
*/

#ifndef NODE_HPP
#define NODE_HPP
#include "Kisi.hpp"
#include "stack.hpp"
using namespace std;

class Node{
public:
    Kisi* data;
    Node* left;
    Node* right;
    int height;
    Stack stack;
    Node(Kisi* dt, Node* lt=NULL, Node* rt=NULL){
        data = dt;
        left = lt;
        right = rt;
        height = 0; // Eklenen her yeni node ilk önce yaprak olarak eklenir.
        stack.push('O');
    }
};

#endif