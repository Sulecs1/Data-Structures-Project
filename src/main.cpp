/**
* @main.cpp
* @main kaynak dosyası
* @Veri Yapıları
* @Final
* @02.09.2020
* @Şule Akçay
*/

#include <iostream>
#include "avltree.hpp"
#include "Kisi.hpp"
#include "node.hpp"
#include "stack.hpp"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void split(const string& s, char c, vector<string>& v){
    string::size_type i = 0;
    string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);
      
      if (j == string::npos)
        v.push_back(s.substr(i, s.length()));
   }
}

int main(){
	vector<string> linebyline;
    ifstream dict_file("./bin/Kisiler.txt");
    string line;

	while(getline(dict_file, line))
    {
        string new_line;
        new_line = line + "\n";
        linebyline.push_back(new_line);
    }

	stringstream ss;
    AVLTree* agac = new AVLTree();
	for(int i=0; i<linebyline.size(); i++){
        vector<string> liste;
        ss<<i;
        
        string satir = linebyline.at(i);
        split(satir, '#', liste);
		Kisi* kisi = new Kisi(liste.at(0), stoi(liste.at(1)), stoi(liste.at(2)));
		agac->Ekle(kisi);
    }

	agac->Postorder();

	delete agac;
	return 0;
}