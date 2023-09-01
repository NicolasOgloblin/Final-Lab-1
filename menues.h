#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "jugabilidadFunciones.h"


void menuPrincipal();
void mostrarTexto (const char* , int , int, bool);
void mostrarTextoUnJugador (const char* , int , int , bool);
void mostrarReglamento ();
void mostrarTextoReglas (const char* , int, int);
int menuUnJugador();


void menuPrincipal (){

   int puntuacionTotalUnJugador =0;
   int puntuacionMaximaTotal=0;

    bool op = true;
    int y=0;


	rlutil::hidecursor();

	while(op) {


        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();

         mostrarTexto (" Un jugador   ", 40, 10, y==0);
         mostrarTexto (" Dos jugadores", 40, 11, y==1);
         mostrarTexto (" Reglamento   ", 40, 12, y==2);
         mostrarTexto (" Ver Puntuacion maxima", 40, 13, y==3);
         mostrarTexto ("              ", 40, 14, y==4);
         mostrarTexto ("   Salir      ", 40, 15, y==5);


        rlutil::locate(38, 10+y);

        if (y!=4) std::cout<< (char)175 <<std::endl;

        switch (rlutil::getkey()){

        case 14:

            rlutil::locate(38, 10+y);
            std::cout<< " " <<std::endl;
            y--;
            if(y<0) y=0;

            break;

        case 15:

            rlutil::locate(38, 10+y);
            std::cout<< " " <<std::endl;
            y++;
            if(y>5) y=5;

            break;


        case 1:
            switch(y){

            case 0:
                puntuacionTotalUnJugador = menuUnJugador();
                rlutil::cls();
                break;

            case 1:

                rlutil::cls();
                std::cout << "No esta hecho";
                rlutil::anykey();
                rlutil::cls();
                break;

            case 2:
                rlutil::cls();
                mostrarReglamento ();
                break;

            case 3:
               rlutil::cls();
               mostrarPuntuacionTotal(&puntuacionTotalUnJugador, &puntuacionMaximaTotal);
               rlutil::anykey();
                rlutil::cls();

                break;

            case 5:
                rlutil::cls();
                op=false;

            default:
                    break;

                }

            break;

        default:
            break;

        }


	}

}



void mostrarTexto (const char* texto, int posx, int posy, bool seleccionado){



     if (seleccionado && posy!=14){
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);

     } else {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
     }


     rlutil::locate(posx, posy);
     std::cout<< texto <<std::endl;

     rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

}


void mostrarTextoUnJugador (const char* texto, int posx, int posy, bool seleccionado){



     if (seleccionado && posy!=12 ){
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);

     }
    else {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
     }


     rlutil::locate(posx, posy);
     std::cout<< texto <<std::endl;

     rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

}




void mostrarReglamento (){

	rlutil::hidecursor();

        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();

        mostrarTextoReglas ("Reglamento del juego", 40, 10);
        mostrarTextoReglas ("El objetivo del juego es obtener al menos 500 puntos en la menor cantidad ", 18, 13);
        mostrarTextoReglas ("posible de rondas, o sacar una escalera en un lanzamiento.", 18, 14);
        mostrarTextoReglas ("Una ronda esta compuesta por 3 lanzamientos. Un lanzamiento consiste en ", 18, 16);
        mostrarTextoReglas ("tirar seis dados y evaluar sus valores para determinar el puntaje.", 18, 17);
        mostrarTextoReglas ("El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran", 18, 19);
        mostrarTextoReglas ("en la seccion Combinaciones ganadoras.", 18, 20);
        mostrarTextoReglas ("El puntaje final de la ronda sera el valor maximo obtenido entre los 3 lanzamientos,", 18, 22);
        mostrarTextoReglas ("con las siguientes excepciones:", 18, 23);
        mostrarTextoReglas ("- Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento.", 18, 25);
        mostrarTextoReglas ("- Si en un lanzamiento se obtiene una combinacion de 6 dados con valor 6, el puntaje", 18, 26);
        mostrarTextoReglas ("de la ronda entera sera 0. ", 18, 27);
        mostrarTextoReglas ("Para el caso de la opcion para 2 jugadores, los jugadores debe completar una ronda", 18, 29);
        mostrarTextoReglas ("(3 lanzamientos) alternativamente. ", 18, 30);
        mostrarTextoReglas ("COMBINACIONES GANADORAS:           ", 18, 34);
        mostrarTextoReglas ("1) Menos de 3 dados con valores iguales (cualquier combinacion). Puntaje : suma de los dados.          ", 18, 36);
        mostrarTextoReglas ("2) 3 dados con valores iguales (hasta 5 dados).Puntaje : X*10 puntos (Ej: para el 5 seria: 5*10=50 pts)", 18, 38);
        mostrarTextoReglas ("3) 6 dados iguales (menos para el número 6). Puntaje : X*50 puntos. ", 18, 40);
        mostrarTextoReglas ("4) Escalera (1,2,3,4,5,6). Puntaje : Gana el juego ! ", 18, 42);
        mostrarTextoReglas ("5) Sexteto de seis (6,6,6,6,6,6). Puntaje : Pierde todos los puntos de la ronda. ", 18, 44);
        mostrarTextoReglas ("Presione cualquier tecla para regresar al menu principal... ", 18, 50);



 rlutil::anykey();
 rlutil::cls();


}


void mostrarTextoReglas (const char* texto, int posx, int posy){

     rlutil::locate(posx, posy);
     std::cout<< texto <<std::endl;

     rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

}



int menuUnJugador(){

    bool op = true;
    int y=0;

    int puntuacionTotal=0;
    int contLanzamiento=0;
    int contRonda=1;
    int  puntuacionUno=0, puntuacionDos=0, puntuacionTres=0;
    int puntuacionMayor=0;

    std::string nombre;

	rlutil::hidecursor();


	while(op) {


        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();

         mostrarTextoUnJugador (" Hacer un lanzamiento         ", 40, 10, y==0);
         mostrarTextoUnJugador (" Ver Puntuacion               ", 40, 11, y==1);
         mostrarTextoUnJugador ("                              ", 40, 12, y==2);
         mostrarTextoUnJugador (" Volver al menu principal     ", 40, 13, y==3);
         mostrarTextoUnJugador ("                              ", 40, 14, y==4);


        rlutil::locate(38, 10+y);

        if (y!=2) std::cout<< (char)175 <<std::endl;

        switch (rlutil::getkey()){

        case 14:

            rlutil::locate(38, 10+y);
            std::cout<< " " <<std::endl;
            y--;
            if(y<0) y =0;

            break;

        case 15:

            rlutil::locate(38, 10+y);
            std::cout<< " " <<std::endl;
            y++;
            if(y>3) y =3;

            break;


        case 1:
            switch(y){

            case 0:

                rlutil::cls();
                ingresarDatos(&nombre);
                while(puntuacionTotal<100){
                    mostrarDatos(&nombre);
                    lanzamiento(&puntuacionTotal, &contLanzamiento, &contRonda, &puntuacionUno, &puntuacionDos, &puntuacionTres, &puntuacionMayor);

                }
                mostrarDatosFinales(&nombre, &puntuacionTotal);
                //lanzarPrueba();
                rlutil::anykey();
                rlutil::cls();

                break;

            case 1:
                rlutil::cls();
                mostrarDatosFinales(&nombre, &puntuacionTotal);
                rlutil::anykey();
                rlutil::cls();

                break;

            case 2:
                rlutil::cls();
                break;

            case 3:
                rlutil::cls();
                op=false;

            default:
                break;

                }

            break;

        default:
            break;

        }


	}
            return puntuacionTotal;
}


#endif // MENUES_H_INCLUDED
