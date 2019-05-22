#include <vector>
#include "Cara.h"
#include "Vertice.h"
#
#ifndef OBJETO_H
#define OBJETO_H

using namespace std;
class Objeto{
    private:
        string s;
        string nombre; //identifacor del objeto
        vector<Vertice*> vertice; //vertices de la fgura
        vector<Cara*> cara; //caras de la figura
    public:
        Objeto(string nombre);
        string getNombre();
        void setS(string s);
        string getS();
        
        void setVertice (Vertice* v){
            vertice.push_back(v);
        }
        void setCara(Cara* c){
            cara.push_back(c);
        }
        
        vector<Vertice*> getVertices();
        vector<Cara*> getCaras();
};
#endif /* OBJETO_H */

