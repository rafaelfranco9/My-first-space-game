#include <iostream>
#include "myObjects.h"

//Pintar la nave
void falcon9::pintarNave(double cx, double cy, BITMAP *buffer,BITMAP *logo,int numeroNave){

    //colorear nave
    if(numeroNave==1){
    rectfill(buffer,cx-20,cy-60,cx+20,cy+40,falcon9::colores.gris_claro); //7-16 //body
    }else{
    rectfill(buffer,cx-20,cy-60,cx+20,cy+40,falcon9::colores.rojo_fuego); //7-16 //body
    }

    rectfill(buffer,cx-20,cy-70,cx+20,cy-60,falcon9::colores.gris_oscuro); //8-11 //punta

    //triangulos
    triangle(buffer,cx-20,cy-70,cx+20,cy-70,cx,cy-90,falcon9::colores.gris_oscuro);//punta

    //propulsor
    triangle(buffer,cx-15,cy+40,cx-10,cy+50,cx-10,cy+40,falcon9::colores.plomo);
    triangle(buffer,cx+15,cy+40,cx+10,cy+50,cx+10,cy+40,falcon9::colores.plomo);
    rectfill(buffer,cx+10,cy+50,cx-10,cy+40,falcon9::colores.plomo);

   //circulo punta
   circlefill(buffer,cx,cy-90,1.5,falcon9::colores.plomo);

   if(numeroNave==1){
   blit(logo,buffer,0,0,cx-18,cy-55,30,90);
   }

}

void falcon9::pintarAlas(double cx, double cy, BITMAP *buffer){

rectfill(buffer,cx-40,cy+20,cx-20,cy+30,falcon9::colores.gris_oscuro); //5-3 //alas
rectfill(buffer,cx+40,cy+20,cx+20,cy+30,falcon9::colores.gris_oscuro); //13-15 //alas
triangle(buffer,cx-40,cy+20,cx-20,cy,cx-20,cy+20,falcon9::colores.gris_oscuro);
triangle(buffer,cx+40,cy+20,cx+20,cy,cx+20,cy+20,falcon9::colores.gris_oscuro);


}




void falcon9::pintarFuego(double cx, double cy, BITMAP *buffer){


       //rectangulo del fuego
      rectfill(buffer,cx-10,cy+60,cx+10,cy+80,falcon9::colores.rojo_fuego);
      triangle(buffer,cx-10,cy+65,cx,cy+85,cx+10,cy+65,falcon9::colores.rojo_fuego);
      triangle(buffer,cx-10,cy+65,cx-5,cy+75,cx-15,cy+85,falcon9::colores.amarillo_fuego);
      triangle(buffer,cx+10,cy+65,cx+5,cy+75,cx+15,cy+85,falcon9::colores.amarillo_fuego);
      triangle(buffer,cx-10,cy+80,cx-10,cy+95,cx-2.5,cy+80,falcon9::colores.amarillo_fuego);
      triangle(buffer,cx+10,cy+80,cx+10,cy+95,cx+2.5,cy+80,falcon9::colores.amarillo_fuego);

}














//Clase barra

void barra::dibujarBarra(double &cx, double &cy, BITMAP* buffer){

    rectfill(buffer,cx-20,cy-15,cx+20,cy+15,colores.verdeBarra); //green rectangle
    rectfill(buffer,cx-80,cy-15,cx-20,cy+15,colores.naranjaBarra); //orange rectangle
    rectfill(buffer,cx+80,cy-15,cx+20,cy+15,colores.naranjaBarra); //orange rectangle
    rectfill(buffer,cx-200,cy-15,cx-80,cy+15,colores.rojoBarra); //red rectangle
    rectfill(buffer,cx+200,cy-15,cx+80,cy+15,colores.rojoBarra); //red rectangle

}


void dibujarTextos(BITMAP *buffer,volatile int timer){

       //Titulo para los segundos
       textprintf_ex(buffer,font,10,520,makecol(255,255,255),-1,"%s","Segundos");
       textprintf_centre_ex(buffer,font,40,540,makecol(255,255,255),-1,"%d",timer);

}


void imprimir_puntos(BITMAP *buffer,falcon9 &nave,int num){

colores c1;

if(num==1){

//puntos
textprintf_centre_ex(buffer,font,600,500,c1.verdeTexto,-1,"%s","Verde: ");
textprintf_centre_ex(buffer,font,670,500,c1.verdeTexto,-1,"%d",nave.condicion_nave.bueno);
textprintf_centre_ex(buffer,font,600,520,c1.naranjaBarra,-1,"%s","Naranja: ");
textprintf_centre_ex(buffer,font,670,520,c1.naranjaBarra,-1,"%d",nave.condicion_nave.medio);
textprintf_centre_ex(buffer,font,600,540,c1.rojoBarra,-1,"%s","Rojo: ");
textprintf_centre_ex(buffer,font,670,540,c1.rojoBarra,-1,"%d",nave.condicion_nave.malo);

}else{

//puntos
textprintf_centre_ex(buffer,font,600,400,c1.verdeTexto,-1,"%s","Verde: ");
textprintf_centre_ex(buffer,font,670,400,c1.verdeTexto,-1,"%d",nave.condicion_nave.bueno);
textprintf_centre_ex(buffer,font,600,420,c1.naranjaBarra,-1,"%s","Naranja: ");
textprintf_centre_ex(buffer,font,670,420,c1.naranjaBarra,-1,"%d",nave.condicion_nave.medio);
textprintf_centre_ex(buffer,font,600,440,c1.rojoBarra,-1,"%s","Rojo: ");
textprintf_centre_ex(buffer,font,670,440,c1.rojoBarra,-1,"%d",nave.condicion_nave.malo);


}

}



