
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
//regresa true si la arista pasada por parametro ya existe en la lista
bool Objeto::yaExisteLaArista (Vertice* v1, Vertice* v2){
    //Buscar la arista en el vector
    for (int i=0; i<arista.size(); i++){        
        
        if (v1->getId() == arista[i]->getV1()->getId() && v2->getId() == arista[i]->getV2()->getId())
            return true;
        else if (v1->getId() == arista[i]->getV2()->getId() && v2->getId() == arista[i]->getV1()->getId() )
            return true;               
    }
    return false;
}
