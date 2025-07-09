#include <iostream>
#include "funciones.h"
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <random>
#include <vector>
#include <ctime>
using namespace std;


///generador mano 1 jugador 1
int cartarandom()
{
    return rand()%20 + 1;
}

int generarmano1 (int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v[i] = cartarandom();
    }
}


///generador mano 1 jugador 2

int generarmano2 (int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v[i] = cartarandom();
    }
}
///generador mano 2 jugador 1
int cartarandom3()
{
    return rand()%20 + 1;
}

int generarmano3 (int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v[i] = cartarandom3();
    }
}


///generador mano 2 jugador 2

int generarmano4(int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v[i] = cartarandom3();
    }
}


///PALO DE LAS CARTAS

string palocartas (int v[], int pos)
{
    int palo = v[pos] % 4;
    switch (palo){
case 0:
    return "corazon";
case 1:
    return "trebol";
case 2:
    return "picas";
case 3:
    return "diamantes";
default:
    return "";
    }

}


///numero de la carta

string numcarta (int v[], int pos){

int numc = v[pos] % 5;
switch (numc){
case 0:
    return " 10  ";
case 1:
    return " J  ";
case 2:
    return " Q  ";
case 3:
    return " K  ";
case 4:
    return " A  ";
default:
    return  "";
}

}

/// GENERAR CARTA EMBAUCADORA

int cartarandom2(){

    return rand()%5 + 1;
}


void cembaucadora (int vcemb[], int tameb)
{
    for (int i = 0; i < tameb; i++)
    {
        vcemb[i] = cartarandom2();

    }

}

/// GENERAR CARTA EMBAUCADORA

string embaucada(int vcemb[], int pos)
{
    string resultado;
    if (vcemb[pos] == 1)
    {
        resultado = "espada";
    }
    else if (vcemb[pos] == 2)
    {
        resultado = "trebol";
    }
    else if (vcemb[pos] == 3)
    {
        resultado = "picas";
    }
    else
    {
        resultado = "corazon";
    }
    return resultado;
}


/// FUNCION QUE DEMUESTRA EN PANTALLA AL GANADOR DE LA RONDA RECIBE NOMBRES Y PUNTOS DE AMBOS JUGADORES

string funcGanador(int p1, int p2, string n1, string n2){
    string ganador;

    if(p1 > p2){
        cout << " GANA JUGADOR 1: "<< n1 << " CON " << p1 << " PUNTOS" <<endl;
        ganador = n1;
        cout << endl;
    }
    else{
        cout << " GANA JUGADOR 2: "<< n2 << " CON " << p2 << " PUNTOS" <<endl;
        ganador = n2;
        cout << endl;
    }
    return ganador;
}

/// FUNCION DE VERIFICACION MANO 1

int contarNumeros(string vectorMano[], string comparacion){
    int contar = 0;
    int i;
    for (i = 0; i < 5; i++){
        if(vectorMano[i]==comparacion){
            contar++;
        }
    }
    return contar;
}

/// FUNCION DE VERIFICACION MANO 2

bool verificarVector(string vectorMano[]){

    int i;
    for(i = 0; i < 5; i++){
        if(contarNumeros(vectorMano, vectorMano[i]) > 1){
            return false;
        }
    }
    return true;
}


/// FUNCION DE VERIFICACION AMBAS MANOS

int contarMano(string vectorMano1[], string comparacion2){
    int contar2 = 0;
    int i;
    for (i = 0; i < 5; i++){
        if(vectorMano1[i]==comparacion2){
            contar2++;
        }
    }
    return contar2;
}

/// FUNCION DE VERIFICACION AMBAS MANOS

bool verificarManos(string vectorMano1[], string vectorMano2[]){
    int i;
    for(i = 0; i < 5; i++){
        if(contarMano(vectorMano2, vectorMano1[i]) >= 1){
            return false;
        }
    }
    return true;
}

/// IMPRIME EN PANTALLA LAS MANOS RECIBE EL VECTOR DE LA MANO

void imprimirMano(string vectorMano[], string nombre, int puntos){

            cout << " JUGADOR : "<< nombre;
            cout << endl;
            cout << endl;
            cout << "----------------------"<<endl;
            cout << "  Naipe      Palo"<<endl;
            cout << "----------------------"<<endl;
            for (int i = 0; i<5; i++)
            {
                cout<<" "<< vectorMano[i] <<  endl;
            }

            cout << "----------------------" << endl;
            cout << " JUGADOR <" << nombre<<">" << " PUNTOS = "<< puntos<< endl;
            cout << "----------------------" << endl;

}

/// IMPRIME EN PANTALLA EL TEXTO DE RONDA

void imprimirRondaj(int j){
            system("cls");
            cout << "-------------------------------------------------------------------"<<endl;
            cout << "                      EMBAUCADO ||  RONDA N"<< j <<"               "<<endl;
            cout << "                        RONDA N "<< j <<"                          "<<endl;
            cout << "-------------------------------------------------------------------"<<endl;

}

/// IMPRIME EN PANTALLA LA CARTA EMBAUCADORA

void imprimirEmbaucadora(string PaloEmbaucador){
            cout << endl;
            cout << "----------------------"<<endl;
            cout << "CARTA EMBAUCADORA: " << PaloEmbaucador << endl;
            cout << "----------------------" << endl;
}

/// SACAR PUNTOS CON EL VECTOR DE LA MANO

int sacarPuntacos(string ValoresMano[], string PalosMano[], string PaloEmbaucador){
    int puntos=0;

    for (int i = 0; i<5; i++){

    if(PalosMano[i] != PaloEmbaucador){
        if(ValoresMano[i] == " 10  "){puntos += 10;}
        else if(ValoresMano[i] == " J  "){puntos += 11;}
        else if(ValoresMano[i] == " Q  "){puntos += 12;}
        else if(ValoresMano[i] == " K  "){puntos += 15;}
        else if(ValoresMano[i] == " A  "){puntos += 20;}
        }
    }

    return puntos;
}


int ganadorPartida(int acumuladorFinalJ1, int acumuladorFinalJ2){
    int maximo = 0;
    if(acumuladorFinalJ1 > acumuladorFinalJ2){
        cout << "-----------------------" << endl;
        cout<<  "    gana jugador 1     "<<endl;
        cout << "-----------------------" << endl;
        maximo = 1;

    }
    else{
            cout << "-----------------------" << endl;
            cout<<  "       gana jugador 2  "<<endl;
            cout << "-----------------------" << endl;
            maximo = 2;}
    return maximo;
}



/*
void imprimirPuntos(int puntosj1, int puntosj2, string suma1[], string suma2[]){
        cout << endl;
        cout << " JUGADOR 1 ";
        for (int i = 0; i<5; i++) {cout << suma1[i];
                                    if(suma1[i] != " "){cout << "+";}
                                    }

        cout << "<->  PUNTOS = " << puntosj1 << endl;

        cout << " JUGADOR 2 ";
       for (int i = 0; i<5; i++) {cout << suma2[i];
                                    if(suma2[i] != " " && suma2[i] != ""){cout << "+";}
                                    }

        cout << "<->  PUNTOS = " << puntosj2 << endl;
        cout << endl;
        }
*/


/*
int sacarPuntos(string nrocarta, string palo, string PaloEmbaucador){
    int puntos=0;

    if(palo != PaloEmbaucador){
        if(nrocarta == " 10  "){puntos += 10;}
        else if(nrocarta == " J  "){puntos += 11;}
        else if(nrocarta == " Q  "){puntos += 12;}
        else if(nrocarta == " K  "){puntos += 15;}
        else if(nrocarta == " A  "){puntos += 20;}
        }

    return puntos;
}

string imprimirSuma(string nrocarta, string palo, string PaloEmbaucador){
    string suma = " ";

    if(palo != PaloEmbaucador){
        if(nrocarta == " 10  "){suma = " 10 " ;}
        else if(nrocarta == " J  "){suma = " 11 " ;}
        else if(nrocarta == " Q  "){suma = " 12 " ;}
        else if(nrocarta == " K  "){suma = " 15 " ;}
        else if(nrocarta == " A  "){suma = " 20 " ;}
        }


        return suma;

}
*/
