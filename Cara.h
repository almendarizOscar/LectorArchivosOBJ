#include "Vertice.h"
#include <vector>
#include <iostream>
#ifndef CARA_H
#define CARA_H

using namespace std;
typedef struct normal {
    float x, y, z;            
    bool visible;
}Normal; 

class Cara{
    private:       
        vector<string> vertice; //lista de index de los vertices que conforman la cara
        Normal normal; //Vector normal de la cara
        
    public:
        Cara();
        void setVertice (string v){ vertice.push_back(v); }
        vector<string> getVertice(){ return vertice;} 
        int getVertiCara (int i);
        
        void calculaNormal(Vertice* v1, Vertice* v2, Vertice* v3);
        Normal getNormal (){ return normal;}
};

#endif // CARA_H
