#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Objeto.h"
#include "LectorOBJ.h"
#ifndef FRAME_H
#define FRAME_H

class Frame {
    private:
        Lector* lec;
    public:
        Frame (Lector* lec){
            this->lec = lec;
        }
        static void muestraVentana(int argc, char** argv);
        static void display(void);
        static void init (void);
        static void drawObjeto ();
        
};

#endif /* FRAME_H */

