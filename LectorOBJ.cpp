#include <iostream>
#include "LectorOBJ.h"
#include "Objeto.h"
#include "Cara.h"
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
    obtenAristas(); //Une vez que se tiene los objetos se determinan las aristas de cada uno
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

//imprime vertices, caras y aristas de un objeto
void Lector::imprimeDatos(){
    //Recorrer la lista de objetos
    vector<Objeto*>::iterator it = objeto.begin();
    
    while (it != objeto.end()){ //recorrer los objetos        
        cout << "o   " << (*it)->getNombre() << endl;      
        //Impresion de los vertices del objeto                                                                
        for (int i = 0; i < (*it)->getVertices().size(); i++){                           
            cout << "v   " << ((*it)->getVertices())[i]->getX()  << "   " 
                           << ((*it)->getVertices())[i]->getY()  << "   " 
                           << ((*it)->getVertices())[i]->getZ()  << endl;                                              
        }
                
        //Impresion de las caras de los objetos
        for (int i = 0; i < (*it)->getCaras().size(); i++ ){ //recorremos cada vertice            
            cout << "f   ";                       
            vector <string> vs =  ((*it)->getCaras())[i]->getVertice();  //vector de strings
            for (int j = 0; j < vs.size() ; j++ )
                cout << vs[j] << "   ";              
            cout << endl; 
           
        }
        
        //Impresion de las aristas del objeto
        
        for (int i=0; i< (*it)->getAristas().size(); i++)     
            cout<<"e"<< ((*it)->getAristas())[i]->getId() <<"   "<<"{"<<  ((*it)->getAristas())[i]->getV1()->getId() << ", " <<  ((*it)->getAristas())[i]->getV2()->getId() << "}"<< endl;
        
        
        cout << endl << endl << endl;
        it++ ;
        //Fin del objeto
    }
}
//Funcion encargada de deducir las aristas de un objetoa partir de la lista de caras 
void Lector::obtenAristas(){
    //Recorremos la lista de objetos
    for (int i=0; i<objeto.size(); i++){        
        int id_arista = 0;
        
        //Recorremos la lista de caras de cada objeto para formar las aristas        
        for (int j=0; j<objeto[i]->getCaras().size(); j++){
            
          
            Cara* cara = (objeto[i]->getCaras())[j]; //Cara
            //Recorremos la lista de vertices de la cara
            
            for (int k=0; k<cara->getVertice().size()-1; k++){   
                
                
                //hacemos los enlacas de los vertices                
                if (k==0){
                    //Se crea una arista desde el primer vertice de la lista con el ultimo                                             
                    if (!(objeto[i]->yaExisteLaArista(vertice[cara->getVertiCara(k)-1],  vertice[cara->getVertiCara(cara->getVertice().size()-1)-1]))){//Verificar que no exista la arista
                        Arista* arista2 = new Arista (vertice[cara->getVertiCara(k)-1],  vertice[cara->getVertiCara(cara->getVertice().size()-1)-1]);                                        

                        arista2->setId(++id_arista); //Se le agrega un identificador a la arista                   
                        //Agregar las aristas a la lista de arista del objeto
                        objeto[i]->setArista(arista2);
                    }
                    
                }
                if (!(objeto[i]->yaExisteLaArista(vertice[cara->getVertiCara(k)-1], vertice[cara->getVertiCara(k+1)-1]))){//Verificar que no exista la arista                    
                    Arista* arista1 = new Arista (vertice[cara->getVertiCara(k)-1], vertice[cara->getVertiCara(k+1)-1]);
                    arista1->setId(++id_arista);
                    //Agregar las aristas a la lista de arista del objeto
                    objeto[i]->setArista(arista1);                
                }
                
            }
            
        }                
    }
}