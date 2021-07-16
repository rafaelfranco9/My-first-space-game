#include "myObjects.h"
#include <iostream>
using namespace std;

//class falcon definitions

    //constructor
    falcon9::falcon9(double &cx, double &cy){

        cx = 350;
        cy = 500;
        falcon9::condicion_nave.bueno = 0;
        falcon9::condicion_nave.medio = 0;
        falcon9::condicion_nave.malo = 0;
        numero_disparos = 0;

    }


    //Functions
    void falcon9::acelerar(double &cy,double &vy){

    vy+=falcon9::aceleracion;
    cy+=vy;

    }

    void falcon9::reaccionar(double cx, double cy,BITMAP *buffer,BITMAP *logo,int numeroNave){

        static double caida_y;
        static double caida_nave;
        double alas_x = cx;
        double alas_y = cy;
        double nave_x = cx;
        double nave_y = cy;


        if(falcon9::condicion_nave.medio > 5){

            if(alas_y+caida_y<600){
                caida_y+=2;
                alas_y+=caida_y;
                falcon9::pintarAlas(alas_x,alas_y,buffer);
                textprintf_centre_ex(buffer,font,150,380,0x1ced11,-1,"%s","La nave esta empeorando!");
                textprintf_centre_ex(buffer,font,150,350,0x1ced11,-1,"%s","Las alas se estan cayendo!");
            }

        }else{

            if(caida_y==0){
            falcon9::pintarAlas(cx,cy,buffer);
            }

        }

        if(falcon9::condicion_nave.malo > 2 || falcon9::condicion_nave.medio > 8){

            if(caida_y<252){

                if(alas_y+caida_y<600){
                    caida_y+=2;
                    alas_y+=caida_y;
                    falcon9::pintarAlas(alas_x,alas_y,buffer);
                }

            }


            if(nave_y+caida_nave<800){
                caida_nave+=2;
                nave_y+=caida_nave;
                if(numeroNave==1){
                falcon9::pintarNave(nave_x,nave_y,buffer,logo,1);
                }else{
                falcon9::pintarNave(nave_x,nave_y,buffer,logo,2);
                }

                falcon9::numero_disparos--;
                textprintf_centre_ex(buffer,font,150,380,0x1ced11,-1,"%s","La nave dejo de funcionar!");


            }else{
                //exit(0);
            }

        }else{

        if(numeroNave==1){
        falcon9::pintarNave(cx,cy,buffer,logo,1);
        }else{
        falcon9::pintarNave(cx,cy,buffer,logo,2);
        }

        falcon9::pintarFuego(cx,cy,buffer);

        }

        cout<<caida_y<<endl;



    }



    void falcon9::mover_bala(BITMAP * buffer,BITMAP *bala,double &barra_x,double &barra_y){

     if(falcon9::numero_disparos > 0){

            for(int i=0; i < falcon9::numero_disparos;i++){

                //mover cada bala de las disparadas su eje X y Y
                falcon9::balas[i].x+=falcon9::balas[i].dx;
                falcon9::balas[i].y+=falcon9::balas[i].dy;
                blit(bala,buffer,0,0,falcon9::balas[i].x,falcon9::balas[i].y,6,6);


                //si llega a donde esta la barra
                if(((int)falcon9::balas[i].y - barra_y+10) < 10 && ((int)falcon9::balas[i].y - barra_y+10) > 0 ){

                   //cout<<"entro"<<endl;
                   falcon9::manejo_de_puntos(barra_x,falcon9::balas[i].x);


                }



                //Si salio de la pantalla por arriba
                if(falcon9::balas[i].y < 0){

                    falcon9::balas[i] = falcon9::balas[falcon9::numero_disparos-1];
                    falcon9::numero_disparos--;
                    if(falcon9::numero_disparos < 0){
                        falcon9::numero_disparos = 0;
                    }
                }



            }//termina el FOR

    }


    }




    void falcon9::manejo_de_puntos(double barra_x,double bala_x){


        //Evaluar donde impacto la bala
        if(bala_x >= barra_x-200 && bala_x < barra_x-80 || bala_x <= barra_x+200 && bala_x > barra_x+80){
            falcon9::condicion_nave.malo++;
            cout<<"MALO";
        }else if(bala_x >= barra_x-80 && bala_x < barra_x-20 || bala_x <= barra_x+80 && bala_x > barra_x+20){
            falcon9::condicion_nave.medio++;
            cout<<"MEDIO";
        }else if(bala_x >= barra_x-20 && bala_x <= barra_x+20){
            falcon9::condicion_nave.bueno++;
            cout<<"BUENO";
        }


    }








/*----------------------------------------------------------*/

//Posicion inicial de la barra
barra::barra(double &bx,double &by){

    bx = barra::origenX;
    by = barra::origenY;

}


void barra::moverBarra(bool &flag,double &bx, double &by,volatile int timer){

double velocidad;

//Aumentar velocidad dependiendo del tiempo
if(timer<8){
    velocidad = 1;
}else if(timer<15){
    velocidad = 2.5;
}else if(timer< 20){
    velocidad = 4;
}else if(timer < 35){
    velocidad = 5.5;
}else if(timer < 40){
    velocidad = 5.9;
}else{
    velocidad = 6.5;
}


//Cambiar direccion dependiendo del eje X
if(flag){

    bx-=velocidad;

    if(bx<=250){
        flag=false;
    }

}else{

    bx+=velocidad;

    if(bx>=450){
        flag=true;
    }

}



}
















