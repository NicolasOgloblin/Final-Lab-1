#ifndef JUGABILIDADFUNCIONES_H_INCLUDED
#define JUGABILIDADFUNCIONES_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "menues.h"

void menuPrincipal();
void lanzarPrueba ();

int buscarMaximo (int* vec){

   int maximo=0;

   for(int x=0; x<3;x++){

    if(vec[x]==1){
        maximo=0;
        return maximo;

        }
    }
        for (int i=0; i<3;i++){

            if(vec[i]>maximo){
                    maximo=vec[i];
                }
            }

        return maximo;
}


void mostrarDatosFinales(std::string* nombre, int* puntuacionTotal){

    std::cout << "JUGADOR:  " << *nombre << std::endl<< std::endl;
     std::cout << "Puntuacion total: " << *puntuacionTotal << std::endl;

}

void mostrarPuntuacionTotal(int* puntuacionTotal, int* puntuacionMaximaTotal){

    if(*puntuacionTotal > *puntuacionMaximaTotal){
        *puntuacionMaximaTotal = *puntuacionTotal;
    }

    std::cout << "Puntuacion total: " << *puntuacionMaximaTotal << std::endl;

}

void mostrarPuntuacion(int* puntuacionTotal){


    std::cout << "Puntuacion total: " << *puntuacionTotal << std::endl;

}

void ingresarDatos(std::string* nombre){

    std::cout << "Ingresa tu nombre: ";
    std::getline(std::cin, *nombre);

    rlutil::cls();
}

void mostrarDatos(std::string* nombre){

    std::cout << "JUGADOR:  " << *nombre << std::endl<< std::endl;

}

int puntosJugada (int maximoRepetido, int numeroMaximo, bool ordenados, int*vec){
    int puntuacion=0;

    if(maximoRepetido==6 && numeroMaximo ==6){
        puntuacion=1;


} else if (maximoRepetido==6){
    puntuacion = numeroMaximo*50;
} else if (maximoRepetido <6 && maximoRepetido > 2){
     puntuacion = numeroMaximo*10;

} else if(maximoRepetido <3){
    for(int y=0; y<6; y++){
        puntuacion+=vec[y];
     }
} else if (maximoRepetido == 1 && ordenados==false){

     for(int l=0; l<6; l++){
        puntuacion+=vec[l];
     }
}
        return puntuacion;
}


bool dadosOrdenados (int* vec, int tamanio){

    bool ordenados=true;

    for (int i=0; i<tamanio;i++){

        if(vec[i]>= vec[i+1]){
            ordenados = false;
        }
    }
    return ordenados;
}

void ordenarVector(int* vec, int tamanio) {
    for (int i = 0; i < tamanio - 1; ++i) {
        for (int j = 0; j < tamanio - i - 1; ++j) {
            if (*(vec + j) > *(vec + j + 1)) {

                int temp = *(vec + j);
                *(vec + j) = *(vec + j + 1);
                *(vec + j + 1) = temp;
            }
        }
    }
}


int numerosRepetidos(int* vec, int tamanio, int numero) {
    int contadorNumeros = 0;
    for (int i = 0; i < tamanio; i++) {
        if ( vec[i] == numero) {
            contadorNumeros++;
        }
    }

    return contadorNumeros;
}
/*
void lanzarPrueba (){
    const int tamanio = 6;
    int vecPrueba[6];
    int maximoRepetidoPrueba=0, numeroMaximoPrueba=0;
    bool ordenadosPrueba;
    int vecRepetidosPrueba[6];
    int puntosPrueba=0;

    std::cout << "Ingrese los dados: ";
    std::cout << "" << std::endl;

    for (int i=0; i<tamanio; i++){

        std::cout<< "Dado " << i+1 << " : ";
        std::cin >> vecPrueba[i];
    }

    ordenadosPrueba = dadosOrdenados (vecPrueba, tamanio);
    ordenarVector(vecPrueba, tamanio);

     if(ordenadosPrueba==true){

        std::cout<< "ESCALERA!";
        std::cout<< "Usted gano el juego!";
        rlutil::anykey();
        rlutil::cls();
        menuPrincipal();

    }

     for (int z=0; z<6; z++){

        vecRepetidosPrueba[z]=numerosRepetidos(vecPrueba, tamanio, z+1);
    }

    for (int y=0; y<6;y++){

        if( vecRepetidosPrueba[y]>= maximoRepetidoPrueba){
            maximoRepetidoPrueba = vecRepetidosPrueba[y];
            numeroMaximoPrueba = y+1;
        }
    }



   puntosPrueba= puntosJugada(maximoRepetidoPrueba, numeroMaximoPrueba, ordenadosPrueba, vecPrueba);

   std::cout << "Puntuacion prueba :" << puntosPrueba ;



}
*/
void lanzamiento(int* puntuacionTotal, int* contLanzamiento, int* contRonda, int* puntuacionUno, int* puntuacionDos, int* puntuacionTres, int* puntuacionMayor){


    *contLanzamiento=*contLanzamiento+1;
    if(*contLanzamiento>3){
        *contLanzamiento=1;
        *contRonda=*contRonda+1;
    }


    std::cout << "Ronda Numero      :  " << *contRonda << std::endl<< std::endl;
    std::cout << "Lanzamiento Numero:  " << *contLanzamiento << std::endl<< std::endl;


    int vecDados[6],  vecRepetidos[6], maximoRepetido=0, numeroMaximo=0;
    const int tamanio = 6;
    bool ordenados = false;
    int vecMayorPuntaje[3];



    srand(static_cast<unsigned>(time(nullptr)));

    for (int i=0; i<6;i++){

        vecDados[i]=rand() % 6 + 1;
        vecRepetidos[i]=0;

    }

    std::cout << "Su jugada es: " << std::endl;


    for (int x=0; x<6;x++){

        std::cout << vecDados[x];
        std::cout << " ";
    }

    ordenados = dadosOrdenados(vecDados, tamanio);

    ordenarVector(vecDados, tamanio);
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    if(ordenados==true){

        std::cout<< "ESCALERA!";
        std::cout<< "Usted gano el juego!";

        rlutil::anykey();
        rlutil::cls();
        menuPrincipal();

    }


    for (int z=0; z<6; z++){

        vecRepetidos[z]=numerosRepetidos(vecDados, tamanio, z+1);
    }

    for (int y=0; y<6;y++){

        if( vecRepetidos[y]>= maximoRepetido){
            maximoRepetido = vecRepetidos[y];
            numeroMaximo = y+1;
        }
    }

    switch(*contLanzamiento){

        case 1:
            *puntuacionUno=puntosJugada(maximoRepetido, numeroMaximo, ordenados, vecDados);
        break;
        case 2:
           *puntuacionDos=puntosJugada(maximoRepetido, numeroMaximo, ordenados, vecDados);
            break;
        case 3:
            *puntuacionTres=puntosJugada(maximoRepetido, numeroMaximo, ordenados, vecDados);
            break;

    }


        vecMayorPuntaje[0]=*puntuacionUno;
        vecMayorPuntaje[1]=*puntuacionDos;
        vecMayorPuntaje[2]=*puntuacionTres;

      *puntuacionMayor=buscarMaximo(vecMayorPuntaje);


    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "Su puntuacion del tiro 1 es : " << *puntuacionUno << std::endl;
    std::cout << "Su puntuacion del tiro 2 es : " << *puntuacionDos << std::endl;
    std::cout << "Su puntuacion del tiro 3 es : " << *puntuacionTres << std::endl;
    std::cout << "" << std::endl;

    if(*contLanzamiento==3){
        *puntuacionTotal += *puntuacionMayor;

        *puntuacionUno=0;
        *puntuacionDos=0;
        *puntuacionTres=0;
    }

     mostrarPuntuacion(puntuacionTotal);

    std::cout << "----------------------------" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Pulse una tecla para realizar otro lanzamiento..." << std::endl;



rlutil::anykey();
rlutil::cls();

}
#endif // JUGABILIDADFUNCIONES_H_INCLUDED
