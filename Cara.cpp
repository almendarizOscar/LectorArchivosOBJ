#include <iostream>
#include <vector>
#include "Vertice.h"
#include "Cara.h"
#include <sstream>
using namespace std;

Cara::Cara(){}
int Cara::getVertiCara (int i){
    int n;
    stringstream geek(vertice[i]);    
    geek >> n;
    return n;    
}

//Los vertices estas ordenados en sentido a las manecillas del reloj
void Cara::calculaNormal(Vertice* v1, Vertice* v2, Vertice* v3){
    Vertice* V_21 = new Vertice (-1, v2->getX()-v1->getX(),  v2->getY()-v1->getY(), v2->getZ()-v1->getZ()); //Resultado de V2 -V1
    Vertice* V_31 = new Vertice (-1, v3->getX()-v1->getX(),  v3->getY()-v1->getY(), v3->getZ()-v1->getZ());  //Resultado de V3 - V1
    
    //Realizamos producto crux  (V_21) X (V_31) 
    normal.x = (V_21->getY()*V_31->getZ()) - (V_21->getZ()*V_31->getY());
    normal.y = (V_21->getZ()*V_31->getX()) - (V_21->getX()*V_31->getZ());
    normal.z = (V_21->getX()*V_31->getY()) - (V_21->getY()*V_31->getX());
    
    //Vemos si es visible la cara o no 
    normal.visible = (normal.x<0 || normal.y<0  || normal.z<0 )?true: false;
}
