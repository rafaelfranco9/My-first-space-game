#ifndef MYOBJECTS_H_INCLUDED
#define MYOBJECTS_H_INCLUDED
#include "allegro.h"
#define max_balas 0


struct colores {

    int
    gris_claro = 0xB7B7B7,
    gris_oscuro = 0x626667,
    plomo = 0x222222,
    rojo_fuego = 0xE3170A,
    amarillo_fuego = 0xFEF667,
    verdeBarra = 0x03fc5a,
    naranjaBarra = 0xfc7b03,
    rojoBarra = 0xfc0303,
    verdeTexto = 0x3e8c2d;

};



/*----------------------------------------------------------------*/

typedef struct{

    int bueno;
    int medio;
    int malo;

}condicion;

typedef struct {

  double x;
  double y;
  double dx;
  double dy;

}bala;




class falcon9{

    private:
    const double aceleracion = -0.01;
    double cx,cy;
    colores colores;

    public:
    condicion condicion_nave;
    int numero_disparos;
    bala balas[max_balas+1]; //numero de balas



    public:
    falcon9(double &cx,double &cy);
    void pintarNave(double cx, double cy, BITMAP *buffer,BITMAP *logo,int numeroNave);
    void pintarAlas(double cx, double cy, BITMAP *buffer);
    void pintarFuego(double cx, double cy, BITMAP *buffer);
    void acelerar(double &cy,double &vy);
    void mover_bala(BITMAP * buffer,BITMAP *bala,double &barra_x,double &barra_y);
    void reaccionar(double cx, double cy,BITMAP *buffer,BITMAP *logo,int numeroNave);
    void manejo_de_puntos(double barra_x,double bala_x);


};



/*----------------------------------------------------------------*/


class barra {

private:
    const double origenX = 350;
    const double origenY = 50;
    colores colores;

public:

    barra(double &bx,double &by);
    void dibujarBarra(double &bx,double &by,BITMAP *buffer);
    void moverBarra(bool &flag,double &bx, double &by,volatile int timer);

};






/*----------------------------------------------------------------*/


//NO-Class functions
void dibujarTextos(BITMAP *buffer,volatile int timer);
void imprimir_puntos(BITMAP *buffer,falcon9 &nave,int num);


#endif // MODELO_H_INCLUDED
