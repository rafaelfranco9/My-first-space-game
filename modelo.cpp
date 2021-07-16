#include "modelo.h"
#include <iostream>
using namespace std;

//class falcon definitions

    //constructor
    falcon9::falcon9(){

        falcon9::condicionNave.bueno = 1;
        falcon9::condicionNave.medio = 0;
        falcon9::condicionNave.malo = 0;

    }

    //Getter
    Estados falcon9::getEstados(){
    return falcon9::condicionNave;
    }

    //Setter
    void falcon9::setEstado(Estados x){

    }


    //Functions
    void falcon9::accelerar(){

    }

    void falcon9::explotar(){

    }

    void falcon9::prenderMotores(){

    }





//class barra definitions

    barra::barra(){
        barra::tamano.x1 = 0;
        barra::tamano.y1 = 0;
        barra::tamano.x2 = 0;
        barra::tamano.y2 = 0;
    }



