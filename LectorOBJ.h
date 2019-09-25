#include <fstream>
#include <vector>
#include "Objeto.h"
#include "Vertice.h"
#ifndef LECTOR_H
#define LECTOR_H

using namespace std;
class Lector{
    private:
        ifstream* arch; 
        vector<Objeto*> objeto; //lista de objetos contenidos en el archivo       
        vector<Vertice*> vertice; // todos los vertices del archivo
        
        
    public:
        Lector(ifstream* arch);
        void imprimeDatos(); //Muestra los datos en pantalla
        void leerArchivo(); //Lee el archivo obj y extrae todos los objetos
        Vertice* leeVertice (int* idVert);        
        Cara* leeCara (char* c);
        vector<Objeto*> getListObjetos ();
        vector<Vertice*> getListVertices ();
        void obtenAristas (); //deduciar las aristas a partir de las caras
};
#endif // LECTOR_H
