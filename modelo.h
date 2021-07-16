#ifndef MODELO_H_INCLUDED
#define MODELO_H_INCLUDED
#include "allegro.h"

//-----------------NAVES-----------------//
typedef struct{

    int bueno;
    int medio;
    int malo;

}Estados;


class nave {

    protected:
        Estados condicionNave;

    public:
        //nave();
        virtual void pintarNave(double cx, double cy, BITMAP *buffer,BITMAP *logo) = 0;
        virtual void prenderMotores() = 0;
        virtual void accelerar() = 0;
        virtual void explotar() = 0;

};


class falcon9:public nave{

public:
    falcon9();
    void pintarNave(double cx, double cy, BITMAP *buffer,BITMAP *logo);
    void setEstado(Estados x);
    Estados getEstados();
    void prenderMotores();
    void accelerar();
    void explotar();
    void pintarFuego(double cx, double cy, BITMAP *buffer);

};



//-----------------Barra-----------------//


typedef struct{

    int x1;
    int y1;
    int x2;
    int y2;

}rectangulo;



class barra{

public:
    barra();
    rectangulo tamano;

};



class baseCohete {

public:
    //baseCohete();
    void construirBase(BITMAP *buffer);
    void bajarBase(BITMAP *buffer);

};








#endif // MODELO_H_INCLUDED
