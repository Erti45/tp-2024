#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include "funciones.h"
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <random>
#include <vector>
#include <ctime>
using namespace std;

///generador de mano
int generarmano1 (int v[], int tam);
int generarmano2 (int v[],int tam);

///generador de carta embaucada
void cembaucadora(int vcemb[], int tameb);

std::string embaucada (int vcemb[], int pos);



/// VALORIZAR LAS CARTAS
std::string palocartas (int v[], int pos);

///numero de cartas
std::string numcarta (int v[], int pos);

/// DEFINIR GANADOR
string funcGanador(int p1, int p2, string n1, string n2);
int ganadorPartida(int acumuladorFinalJ1, int acumuladorFinalJ2);

/// SACAR PUNTOS
///int sacarPuntos(string nrocarta, string palo, string PaloEmbaucador);
int sacarPuntacos(string ValoresMano[], string PalosMano[], string PaloEmbaucador);

///verificar mano
bool verificarVector(string vectorMano[]);
int contarNumeros(string vectorMano[], string comparacion);
int contarMano(string vectorMano1[], string comparacion2);
bool verificarManos(string vectorMano1[], string vectorMano2[]);

///IMPRIMIR
void imprimirMano(string vectorMano[], string nombre, int puntos);
void imprimirRondaj(int j);
string imprimirSuma(string nrocarta, string palo, string PaloEmbaucador);
void imprimirPuntos(int puntosj1, int puntosj2, string suma1[], string suma2[]);
void imprimirEmbaucadora(string PaloEmbaucador);


#endif // FUNCIONES_H_INCLUDED
