#include <iostream>
#include <list>
#include "Vertice.h"
#include <sstream> 
using namespace std;

Vertice::Vertice (int id, string x, string y, string z){
    idVertice = id;
    this->x=x;
    this->y=y;
    this->z=z;
}

float Vertice::getX(){
    stringstream geek(x); 
    float n;
    geek >> n;
    return n;
}
float Vertice::getY(){
    stringstream geek(y); 
    float n;
    geek >> n;
    return n;
}
float Vertice::getZ(){
    stringstream geek(z); 
    float n;
    geek >> n;
    return n;
}
void Vertice::setX(string x){
    this->x = x;
}
void Vertice::setY(string y){
    this->y = y;
}
void Vertice::setZ(string z){
    this->z = z;
}

