/****************************************
 * LECTOR DE ARCHIVOS OBJ
 * Oscar Almendáriz Rodríguez
 ****************************************/

#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>
#include "LectorOBJ.h"
#include "Frame.h"

#define SCREEN_W 1200
#define SCREEN_H 768
using namespace std;
//Variable globla que gurda al lector
vector<Objeto*> objeto; //lista de objetos contenidos en el archivo       
vector<Vertice*> vertice; // todos los vertices del archivo

//Función para dibujar el objeto cargado
static void drawObjeto (){
    //Primero, recorremos la lista de objetos            
    for (int o = 0; o < objeto.size(); o++){ //recorrer los objetos                         
        //Se recorre la lista de caras        
        Objeto* Obj = objeto[o];                        
        for (int i=0; i < Obj->getCaras().size(); i++){            
            Cara* cara = (Obj->getCaras())[i];
            //Recorremos la lista de vertices de esa vertice                                                                        
            
            glBegin (GL_LINE_LOOP);             
            for (int j = 0; j < cara->getVertice().size(); j++){                                                      
                int numVertice = cara->getVertiCara(j);                                                                                                                                               
                glVertex3f (vertice[numVertice-1]->getX(), 
                            vertice[numVertice-1]->getY(),
                            vertice[numVertice-1]->getZ());
                
            }
            glEnd();                    
        }                      
    }    
   
}

/*  El "lector" nos servirá para extraer los objetos que estan en el archivo obj
 *  Además, nos proporciona la lista de vertices.
 *  Una ves que obtenemos todo lo anterio, el lector será liberado de la memoria
 */
int main(int argc, char** argv) {    
    GLFWwindow* window; //Ventana para dibujar el objeto
    ifstream arch; //Archivo obj 
    Lector* lec; //Lector de archivos obj
    
    //Abrir el archivo obj
    arch.open(argv[1]);    
    if (!arch.is_open()){
        cout << "Error al intentar abrir el archivo"<< endl;
        return 1;
    }    
    /*Lectura del archivo obj***********************************/
    cout << "Nombre del archivo:  " << argv[1] << endl;    
    Lector* lector = new Lector (&arch); //Se crea un lector obj
    lector->leerArchivo();
    lector->imprimeDatos(); //Imprime los datos leidos del archivo
    //Obtenemos las lista de objetos y la lista de vertices                
    objeto = lector->getListObjetos();
    vertice = lector->getListVertices();    
    
    
    arch.close(); //cerramos el archivo obj
    delete lector;  //Liberamos el lector de la memoria
    /***********************************************************/
    
    
    if( !glfwInit() ){
        fprintf( stderr, "Fallo al inicializar GLFW\n" );
        getchar();
        return 1;
    }

    window = glfwCreateWindow(1200, 768, "Lector de Archivo obj", NULL, NULL); //Creamo una nueva ventana 
    if( window == NULL ) {
        fprintf( stderr, "Fallo al abrir la ventana de GLFW.\n" );
        getchar();
        glfwTerminate();
        return 1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);     
    glLoadIdentity();
    do {
        glClear( GL_COLOR_BUFFER_BIT );
        glColor3f(1.0, 1.0, 1.0);             
        drawObjeto(); //Dibujar objeto
        glfwSwapBuffers(window);
        glfwPollEvents();

    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&  glfwWindowShouldClose(window) == 0 );

    glfwTerminate();

    return 0;
    
}


