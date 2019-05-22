#include <iostream>
#include "Objeto.h"
#include <list>
#include<vector>

using namespace std;

Objeto::Objeto (string nombre){
    this->nombre = nombre;
}
string Objeto::getNombre(){
    return nombre;
}
vector<Vertice*> Objeto::getVertices(){
    return vertice;
}
vector<Cara*> Objeto::getCaras(){
    return cara;
}

void Objeto::setS(string s){
    this->s = s;
}
string Objeto::getS(){
    return s;
}