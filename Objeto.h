#include <vector>
#include "Cara.h"
#include "Vertice.h"
#include "Arista.h"
#ifndef OBJETO_H
#define OBJETO_H

using namespace std;
class Objeto{
    private:
        string s;
        string nombre; //identifacor del objeto
        
        vector<Vertice*> vertice; //vertices de la fgura
        vector<Cara*> cara; //caras de la figura
        vector<Arista*> arista; //aristas de la figura
        
    public:
        Objeto(string nombre);
        string getNombre();
        void setS(string s);
        string getS();        
        
        void setVertice (Vertice* v){ vertice.push_back(v);}       
        void setCara(Cara* c){   cara.push_back(c); }
        void setArista (Arista* aris){ arista.push_back(aris);}
        vector<Vertice*> getVertices();
        vector<Cara*> getCaras();
        vector<Arista*> getAristas(){ return arista;}
        
        bool yaExisteLaArista (Vertice* v1, Vertice* v2);
};
#endif /* OBJETO_H */

