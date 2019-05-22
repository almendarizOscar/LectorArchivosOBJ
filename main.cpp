//Main del Lector Obj
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include "LectorOBJ.h"
#include "Frame.h"
using namespace std;
//Variable globla que gurda al lector
Lector* lec;

static void drawObjeto (){
    //Primero, recorremos la lista de objetos        
    glRotatef(30, 1.0f, 1.0f, 1.0f); // rotate by angle in degrees
    for (int o = 0; o < lec->getListObjetos().size(); o++){ //recorrer los objetos                         
        //Se recorre la lista de caras        
        Objeto* Obj = (lec->getListObjetos())[o];                        
        for (int i=0; i < Obj->getCaras().size(); i++){            
            Cara* cara = (Obj->getCaras())[i];
            //Recorremos la lista de vertices de esa vertice                                                                        
            
            glBegin (GL_LINE_LOOP);             
            for (int j = 0; j < cara->getVertice().size(); j++){                                                      
                int numVertice = cara->getVertiCara(j);                                                                                                                                               
                glVertex3f ((lec->getListVertices())[numVertice-1]->getX(), 
                            (lec->getListVertices())[numVertice-1]->getY(),
                            (lec->getListVertices())[numVertice-1]->getZ());
                
            }
            glEnd();                    
        }                      
    }    
   
}

static void display(void) {    
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);      
    drawObjeto ();
    glFlush ();
}

static void init (void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);    
}
    
static void muestraVentana(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (700, 700); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Objeto");
    init ();
    glutDisplayFunc(display); 
    glutMainLoop();
    
}

int main(int argc, char** argv) {    
    ifstream arch;    
    arch.open(argv[1]);    
    if (!arch.is_open()){
        cout << "Error al intentar abrir el archivo"<< endl;
        return 1;
    }
    cout << "Nombre del archivo:  " << argv[1] << endl;    
    Lector* lector = new Lector (&arch);
    lector->leerArchivo();   
    arch.close();
    //Mostrar los objetos
    lec = lector;   
    muestraVentana(argc, argv);          
    delete lector;    
    return 0;
}
