#include <iostream>
#include <allegro.h>
#include "iniciaAllegro.h"
#include "myObjects.h"

using namespace std;



//Prototipos de funciones de controlador
//void mover_nave(double &cx,double &cy,double &vx, double &vy);
void aceleracion(double &vx,double &vy);



//Declaracion para el Timer
volatile int timer;
void incrementaTimer(){
timer++;
}
END_OF_FUNCTION(incrementaTimer);




int main(){


    //Iniciar Allegro
    inicia_allegro(700,600);

    //Cargar imagenes y bitmap principal
    BITMAP *sky = load_bitmap("imagenes/Sky2.bmp",NULL);
    BITMAP *space = load_bitmap("imagenes/Space.bmp",NULL);
    BITMAP *logo = load_bitmap("imagenes/spacex_logo.bmp",NULL);
    BITMAP *bala = load_bitmap("imagenes/bala.bmp",NULL);
    BITMAP *buffer = create_bitmap(700,600);

    //Timer
    timer = 0;
    LOCK_FUNCTION(incrementaTimer);
    LOCK_VARIABLE(timer);
    install_int_ex(incrementaTimer,SECS_TO_TIMER(1));


    //Declaracion de variables
    int tiempo_entre_disparos;
    double cx,cy,vx,vy,bx,by,vx2,vy2,velocidadFondo,velocidadAux,i,cx2,cy2;
    bool ambiente_inicial,fondoSky,mover_izquierda_barra,juego_iniciado;

    //posicion inicial de la nave
    cx = 0;//350;
    cy = 0;//500;
    cx2 = 0;
    cy2 = 0;

    //velocidad inicial

        //velocidad nave
        vx = 0;
        vx2 = 0;
        vy = 0;
        vy2 = 0;

        //velocidad fondo
        velocidadFondo = 0;
        velocidadAux = 0;


    //flag indicadores
    fondoSky = true;
    mover_izquierda_barra = true;
    ambiente_inicial = true;
    juego_iniciado = false;

    //tiempo entre los disparos
    tiempo_entre_disparos = 0;

    //Eje Y del fondo
    i = 1700; //2300 - 600 = 1700


    //Crear objectos
    falcon9 nave(cx,cy);
    falcon9 nave2(cx2,cy2);
    cx+=100;
    cx2-=100;
    barra b1(bx,by);



    //Ciclo general del juego

    while(!key[KEY_ESC]){


        if(ambiente_inicial){

        //Fondo estatico
        blit(sky,buffer,0,i,0,0,buffer->w,buffer->h);
        nave.pintarNave(cx,cy,buffer,logo,1);
        nave.pintarAlas(cx,cy,buffer);
        nave2.pintarNave(cx2,cy2,buffer,logo,2);
        nave2.pintarAlas(cx2,cy2,buffer);

        textprintf_centre_ex(buffer,font,350,350,0x1a1f1c,-1,"%s","Toca la letra \"A\" para empezar");
        textprintf_centre_ex(buffer,font,350,380,0x1a1f1c,-1,"%s","Toca ESPACIO para disparar");
        }



        //Empezar el juego
        if(key[KEY_A] || juego_iniciado){


            //Para que no se ejecute el fondo estatico
            ambiente_inicial = false;


            //Periodo donde la nave esta arrancando
            if(cy>=350){

                if(key[KEY_LEFT]){
                    cx-=5;
                }
                if(key[KEY_RIGHT]){
                    cx+=5;
                }

                if(key[KEY_W]){
                    cx2-=5;
                }
                if(key[KEY_R]){
                    cx2+=5;
                }

                blit(sky,buffer,0,i,0,0,700,600);
                nave.pintarNave(cx,cy,buffer,logo,1);
                nave2.pintarNave(cx2,cy2,buffer,logo,2);
                nave.pintarAlas(cx,cy,buffer);
                nave2.pintarAlas(cx2,cy2,buffer);
                nave.pintarFuego(cx,cy,buffer);
                nave2.pintarFuego(cx2,cy2,buffer);
                nave.acelerar(cy,vy);
                nave2.acelerar(cy2,vy2);



            //periodo donde la nave llego al eje Y maximo y el fondo empieza a moverse
            }else{

                    //Mientras el fondo no llegue
                    if(i>=0 && fondoSky == true){

                        //pintar fondo sky (azul) y disminuir su eje Y
                        blit(sky,buffer,0,i,0,0,buffer->w,buffer->h);

                        //Controlar velocidades para que dure mas el fondo azul
                        if((i>=0 && i<=300) && timer < 20){
                        velocidadAux = 0.2;
                        }else{
                        velocidadAux = 1;
                        }

                    //Cuando el fondo Sky llega a 0 empezar a mostrar el fondo Space
                    }else{

                        //inicializar de vuelta la variable i en 1700 para el fondo Space
                        if(fondoSky){
                            i=1700;
                            fondoSky = false;
                        }else if(i<=20 && i>=-20){
                            i=1700;
                        }

                        //pintar fondo Space y disminuir su eje Y
                        blit(space,buffer,0,i,0,0,buffer->w,buffer->h);
                    }


                //Regular las velocidades dependiendo del fondo en el que este
                if(fondoSky==true){
                velocidadFondo+=0.05;
                }else{
                velocidadFondo+=0.02;
                }


                //Disminuir eje Y de los fondos
                i-=velocidadFondo*velocidadAux;;

                //Mover la nave a los lados
                if(key[KEY_LEFT]){
                    cx-=5;
                }
                if(key[KEY_RIGHT]){
                    cx+=5;
                }

                if(key[KEY_W]){
                    cx2-=5;
                }
                if(key[KEY_R]){
                    cx2+=5;
                }

                //Pintar nave y fuego
                //nave.pintarNave(cx,cy,buffer,logo);
                nave.reaccionar(cx,cy,buffer,logo,1);
                nave2.reaccionar(cx2,cy2,buffer,logo,2);
                //nave.pintarFuego(cx,cy,buffer);


            }


            if(key[KEY_SPACE]){

                if (nave.numero_disparos <= max_balas){
                    nave.numero_disparos++;

                    //asignarle las cordenadas a cada vala y su movimiento
                    nave.balas[nave.numero_disparos-1].x = cx - 2;
                    nave.balas[nave.numero_disparos-1].y = cy - 100;
                    nave.balas[nave.numero_disparos-1].dx = 0;
                    nave.balas[nave.numero_disparos-1].dy = -10; //velocidad

                }

            }

            if(key[KEY_ENTER]){

                if (nave2.numero_disparos <= max_balas){
                    nave2.numero_disparos++;

                    //asignarle las cordenadas a cada vala y su movimiento
                    nave2.balas[nave2.numero_disparos-1].x = cx2 - 2;
                    nave2.balas[nave2.numero_disparos-1].y = cy2 - 100;
                    nave2.balas[nave2.numero_disparos-1].dx = 0;
                    nave2.balas[nave2.numero_disparos-1].dy = -10; //velocidad

                }

            }







            nave.mover_bala(buffer,bala,bx,by);
            nave2.mover_bala(buffer,bala,bx,by);
            b1.moverBarra(mover_izquierda_barra,bx,by,timer);
            juego_iniciado = true;
        }




        //timer
        if(!juego_iniciado){
            timer = 0;
        }

       dibujarTextos(buffer,timer);
       imprimir_puntos(buffer,nave,1);
       imprimir_puntos(buffer,nave2,2);
       b1.dibujarBarra(bx,by,buffer);
       blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
       //cout<<vy<<" --- "<<cy<<" --- "<<i<<endl;
       rest(20);


    }//final del ciclo del juego



    //Destruir los bitmaps
    destroy_bitmap(buffer);
    destroy_bitmap(sky);



    return 0;
}
END_OF_MAIN();




void aceleracion(double &vx,double &vy){

double ax,ay;
ax = 0;
ay = -0.01;

vx+=ax;
vy+=ay;


}

















//
//void mover_nave(double &cx,double &cy,double &vx, double &vy){
//
//  //aceleracion
////  double ax,ay;
////  ax = 0;
////  ay = 0.05;
////
////  //velocidad
////  vx+=ax;
////  vy+=ay; //t1 0.05//t2 0.10//t3 0.15//t4 0.20
//
//  //movimiento
//  cx+=vx;
//  cy+=vy; //t1 0.05 //t2 0.15//t3 0.30//t4 0.50
//
//
//}




