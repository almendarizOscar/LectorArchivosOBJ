#include "Vertice.h"
#ifndef ARISTA_H
#define ARISTA_H
class Arista {
    private:
        Vertice* v1;
        Vertice* v2;
    public:
        Arista (Vertice* v1, Vertice* v2);
        Vertice* getV1 (){return v1;}
        Vertice* getV2 (){return v2;}
};
#endif /* ARISTA_H */

