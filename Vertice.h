#include <fstream>
#include <iostream>
#include <list>
#ifndef VERTICE_H
#define VERTICE_H
using namespace std;

class Vertice{
    private:
        int idVertice;
        string x, y, z;
    public:    
        
        Vertice(int id, string x, string y, string z);
        float getX();
        float getY();
        float getZ();
        
        void setX(string x);
        void setY(string y);
        void setZ(string z);
        
};



#endif /* VERTICE_H */

