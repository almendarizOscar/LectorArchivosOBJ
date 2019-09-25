#include <iostream>
#include "LectorOBJ.h"
#include "Objeto.h"
#include <vector>
#include <stdlib.h>

Lector::Lector(ifstream* arch){
    this->arch = arch;
}
vector<Objeto*> Lector::getListObjetos (){
    return objeto;
}
vector<Vertice*> Lector::getListVertices (){
    return vertice;
}

void Lector::leerArchivo(){
    char c; //caracter
    string s;           
    *arch >> c;
    do{       
        if (c == '#'){ //si se encuentra un comentario
             do{
                 c = arch->get();
             }while (c != '\n');     
           *arch >> c;
        }else  if (c == 'o'){ //SE ENCONTRO CON UN OBJETO
            int idVert = 1; //identificador del vertice
            Objeto* newObjeto; //objeto en el archivo
                                  
            *arch >> s;            
            newObjeto= new Objeto(s);  //OBJETO DE OBj            
            *arch >> c;                       
                                  
            while(c == 'v'){ //mientras lea vertices                                                                            
                Vertice* vert = leeVertice(&idVert);
                newObjeto->setVertice(vert);                           
                vertice.push_back(vert);
                *arch >> c;
            }        
            
            if (c == 's'){ //lee el parametro 's' del archivo                
                *arch >> s;
                c = arch->get();
                if (c == '\n') c = arch->get();
            }                                
             
            while ( c == 'f' && !arch->eof() && c!= 'o'){                                                            
                newObjeto->setCara(leeCara(&c));                    
            }                                               
            objeto.push_back(newObjeto);                                  
        }                           
        
    }while (!arch->eof()); //mientras no sea el final del archivo    
}

Cara* Lector::leeCara(char* c){   
    string ca;
    Cara* cara = new Cara();
    *arch >> ca;
    while (ca!= "f" && !arch->eof() && ca!= "o" ){                                       
            cara->setVertice(ca);           
            *arch >> ca;           
    }     if (ca == "o") *c = 'o';
    return cara;
}

Vertice* Lector::leeVertice(int* idVert){
    //LEE LOS VERTICES
    string x, y, z;  
            
    *arch >> x;
    *arch >> y;
    *arch >> z; 
    
    Vertice* vertice = new Vertice((*idVert)++, x, y, z);
    return vertice;
}

//imprime los objetos almacenados
void Lector::imprimeDatos(){
    //Recorrer la lista de objetos
    vector<Objeto*>::iterator it = objeto.begin();
    
    while (it != objeto.end()){ //recorrer los objetos        
        cout << "o   " << (*it)->getNombre() << endl;      
        //Recorrer la lista de vertices del objeto                                                         
       
        for (int i = 0; i < (*it)->getVertices().size(); i++){                           
            cout << "v   " << ((*it)->getVertices())[i]->getX()  << "   " 
                           << ((*it)->getVertices())[i]->getY()  << "   " 
                           << ((*it)->getVertices())[i]->getZ()  << endl;                                              
        }
                
        for (int i = 0; i < (*it)->getCaras().size(); i++ ){ //recorremos cada vertice            
            cout << "f   ";                       
            vector <string> vs =  ((*it)->getCaras())[i]->getVertice();  //vector de strings
            for (int j = 0; j < vs.size() ; j++ )
                cout << vs[j] << "   ";              
            cout << endl; 
           
        }
        cout << endl << endl << endl;
        it++ ;
    }
}
