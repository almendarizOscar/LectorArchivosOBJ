#include "Vertice.h"
#include <vector>
#include <iostream>
#ifndef CARA_H
#define CARA_H

using namespace std;
class Cara{
    private:       
        vector<string> vertice;
                
    public:
        Cara();
        void setVertice (string v){
            vertice.push_back(v);           
        }
        vector<string> getVertice();
        
        int getVertiCara (int i);
};


#endif // CARA_H
