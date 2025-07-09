#include "menu.h"
#include <iostream>

using namespace std;

void menu(){
    system("cls");
    cout << "-----------------------" << endl;
    cout << "       EMBAUCADO  " << endl;
    cout << "-----------------------" << endl;
    cout << "     1 - JUGAR  " << endl;
    cout << "     2 - ESTADISTICAS " << endl;
    cout << "     3 - CREDITOS          " << endl;
    cout << "     4 - REGLAS          " << endl;
    cout << "-----------------------" << endl;
    cout << "      9 - SALIR        " << endl;
    cout << "-----------------------" << endl;
    cout << "   Elija una opcion: "<< endl;
    cout << "-----------------------" << endl;

}

void menusalida(){
    cout << "SI DESEA VOLVER AL MENU PRESIONE 1"<<endl;
    cout << "INGRESE NUEVAMENTE UN 0 PARA SALIR"<<endl;
    }

void menucreditos(){
    system("cls");
    cout << "<              EMBAUCADO               >" << endl;
    cout << "---------------------------------------" << endl;
    cout << "        Hecho por:         " << endl;
    cout << "    Joaquin Rodriguez   " << endl;
    cout << "---------------------------------------" << endl;
}

void reglas(){
    system("cls");
    cout << "---------------------------------------" << endl;
    cout << "         < REGLAS DEL EMBAUCADO >      "<<endl;
    cout << "---------------------------------------" << endl;
    cout << "                                       " << endl;
    cout << "Al iniciar la ronda cada jugador recibira" << endl;
    cout << "una mano de 5 cartas aleatorias 4 palos" << endl;
    cout << "                                       " << endl;
    cout << "---------------------------------------" << endl;
    cout << "                < PALOS >              " << endl;
    cout << "---------------------------------------" << endl;
    cout << "                - Picas                " << endl;
    cout << "                - Trebol               " << endl;
    cout << "                - Diamantes            " << endl;
    cout << "                - Corazon              " << endl;
    cout << "---------------------------------------" << endl;
    cout << "               < VALORES >             " << endl;
    cout << "---------------------------------------" << endl;
    cout << " Del 1 - 10 Equivalen su valor tal cual" << endl;
    cout << "             J - Equivale a 11         " << endl;
    cout << "             Q - Equivale a 12         " << endl;
    cout << "             K - Equivale a 13         " << endl;
    cout << "---------------------------------------" << endl;



}

void volvermenu(){
    cout << "inserte 0 para volver al menu"<<endl;
}

void estadisticas(){
    cout << " EMBAUCADO  " << endl;
    cout << "---------------------------------------" << endl;

}
