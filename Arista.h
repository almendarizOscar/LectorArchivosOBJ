#include "Vertice.h"
#ifndef ARISTA_H
#define ARISTA_H
class Arista {
    private:
        int id; //Identificador de la arista
        Vertice* v1; 
        Vertice* v2;
    public:
        Arista (Vertice* v1, Vertice* v2);
        Vertice* getV1 (){return v1;}
        Vertice* getV2 (){return v2;}
        void setId (int i){ id=i; }
        int getId() { return id;}
};
#endif /* ARISTA_H */

