#include "Vertice.h"
#include <vector>
#include <iostream>
#ifndef CARA_H
#define CARA_H

using namespace std;
class Cara{
    private:       
        vector<string> vertice; //lista de index de los vertices que conforman la cara
        
    public:
        Cara();
        void setVertice (string v){ vertice.push_back(v); }
        vector<string> getVertice(){ return vertice;} 
        int getVertiCara (int i);
};

#endif // CARA_H
