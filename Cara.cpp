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