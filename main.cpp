#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
#include <ctime>
#include "funciones.h"
#include "menu.h"
using namespace std;

int main()
{
    int puntosj1 = 0, puntosj2 = 0;
    int maximopuntaje, maxh;
    int opcion = 0, salida = 1;
    int y = 0;
    int o = 0;
    bool salir = false;
    bool banderaError = 0;
    string nombrej1, nombrej2, palo, nrocarta, cartaYpalo, maxj;
    string vectorMano1[5];
    string vectorMano2[5];
    void reglas();

    /// VECTORES DE LAS MANOS

    string ValoresManoJ1[5];
    string ValoresManoJ2[5];
    string PalosManoJ1[5];
    string PalosManoJ2[5];

    /// NOMBRES

    bool nombresIngresados = false;
    bool vv1 = false;
    bool vv2 = false;

    /// VECTOR DE LETRAS (J, Q , K)

    int vecPuntosMano1Jugador1[5];
    int vecPuntosMano1Jugador2[5];

    /// ACUMULADOR JUGADOR 1 DE LAS 3 RONDAS.

    int acumuladorJ1R1 = 0;
    int acumuladorJ1R2 = 0;
    int acumuladorJ1R3 = 0;
    int acumuladorFinalJ1 = 0;

    int acumuladorJ2R1 = 0;
    int acumuladorJ2R2 = 0;
    int acumuladorJ2R3 = 0;
    int acumuladorFinalJ2 = 0;

    char s;

    do
    {
        if (banderaError == 0){
            menu();
            cin >> opcion;
        }
        else if (banderaError == 1){
            menu();
            cout << "Valor ingresado no valido porfavor vuelva a ingresar un nuevo valor" << endl;
            cin >>opcion;
        }

        /*
        Explicación:
        cin.fail(): Comprueba si la entrada no es un número.
        cin.clear(): Restaura cin a un estado válido después de un error.
        cin.ignore(): Descarta la entrada incorrecta (letras u otros caracteres no numéricos) hasta el final de la línea.
        Con esto, si el usuario ingresa letras u otros caracteres inválidos, el programa no se rompe y sigue funcionando correctamente.

        */
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, ingrese un número.\n";
            banderaError = 1;
            continue;
        }

        switch(opcion)
        {

///   OPCION JUGAR (1)

/// INGRESAR NOMBRES
        case 1:
        {
            if (!nombresIngresados)
            {
                system("cls");
                cout << "Ingrese el nombre del jugador numero 1: ";
                cin >> nombrej1;
                cout << "Ingrese el nombre del jugador numero 2: ";
                cin >> nombrej2;
                nombresIngresados = true;
            }


///semilla
            srand (time (0));


///vector de cartas
            const int tamc = 20;
            int v[tamc];


            const int tam = 5;

/// FOR SISTEMA DE RONDAS


int j=0;



/// generar carta embaucadora

                int vcemb[tam];
                string PaloEmbaucador, ganadorRonda1, suma1[5], suma2[5];
                cembaucadora(vcemb, tam);
                PaloEmbaucador = embaucada(vcemb, 0);

                acumuladorJ1R1=0, acumuladorJ1R2=0, acumuladorJ1R3=0, acumuladorFinalJ1=0;
                acumuladorJ2R1=0, acumuladorJ2R2=0, acumuladorJ2R3=0, acumuladorFinalJ2=0;


/// GENERAR MANOS
                int camino = 1;

                do
                {

                    switch(camino)
                    {
                    ///         CASE 1 VERIFICAR QUE NO SE REPITA MANO 1  ///  SI SE REPITE ENTONCES VUELVE A GENERAR UNA MANO /// SI NO SE REPITE ENTONCES AVANZA

                    case 1:
                    {
                        generarmano1(v,tam);
                        puntosj1=0;
                        for (int i = 0; i<tam; i++)
                        {
                            nrocarta = numcarta(v,i);
                            palo = palocartas(v,i);
                            ValoresManoJ1[i] = nrocarta;
                            PalosManoJ1[i] = palo;
                            vectorMano1[i] = ValoresManoJ1[i] + PalosManoJ1[i];
                        }
                        puntosj1 += sacarPuntacos(ValoresManoJ1, PalosManoJ1, PaloEmbaucador);

                        vv1 = verificarVector(vectorMano1);
                        if(vv1 == true)
                        {
                            camino=2;
                        }
                        else
                        {
                            camino=1;
                        }
                        break;
                    }

///         CASE 2 VERIFICAR QUE NO SE REPITA MANO 2 ///  SI SE REPITE ENTONCES VUELVE ///  NO SE REPITE ENTONCES AVANZA
                    case 2:
                    {
                        generarmano1 (v,tam);
                        puntosj2=0;

                        for (int i = 0; i<tam; i++)
                        {
                            nrocarta = numcarta(v,i);
                            palo = palocartas(v,i);
                            ValoresManoJ2[i] = nrocarta;
                            PalosManoJ2[i] = palo;
                            vectorMano2[i] = ValoresManoJ2[i] + PalosManoJ2[i];
                        }
                        puntosj2 += sacarPuntacos(ValoresManoJ2, PalosManoJ2, PaloEmbaucador);

                        vv2 = verificarVector(vectorMano2);
                        if (vv2 == true)
                        {
                            camino=3;
                        }
                        else
                        {
                            camino=2;
                        }
                        break;
                    }

/// VERIFICAR QUE NO SE REPITAN ENTRE SI LAS DOS MANOS (CASE 3) ///  SI SE REPITE ENTONCES VUELVE TODO PARA ATRAS AL CASE 1 /// NO SE REPITE ENTONCES AVANZA

                    case 3:
                    {
                        if(verificarManos(vectorMano1, vectorMano2)== true)
                        {
                            camino = 4;
                        }
                        else
                        {
                            camino =1;
                        }
                        break;
                    }

/// UNA VEZ VERIFICADAS LAS DOS MANOS EMPIEZA LA RONDA 1 (SE IMPRIME EN PANTALLA) (CASE 4)

                    case 4:
                    {
                        j++;

                        if(j ==1){
                        imprimirRondaj(j);
                        imprimirMano(vectorMano1, nombrej1, puntosj1);
                        imprimirMano(vectorMano2, nombrej2, puntosj2);
                        imprimirEmbaucadora(PaloEmbaucador);
                        ganadorRonda1 = funcGanador(puntosj1, puntosj2, nombrej1, nombrej2);
                        acumuladorJ1R1 += puntosj1;
                        acumuladorJ2R1 += puntosj2;
                        system("pause");
                        camino=1;
                        }
                                                                    /// ACA TERMINA RONDA 1

                        if(j==2){camino=5;}
                        if(j==3){camino=6;}
                        break;
                    }


                    case 5:
                    {

                        imprimirRondaj(j);
                        imprimirMano(vectorMano1, nombrej1, puntosj1);
                        imprimirMano(vectorMano2, nombrej2, puntosj2);
                        imprimirEmbaucadora(PaloEmbaucador);

                        if (acumuladorJ1R1 >= 20)
                        {
                            cout << "Jugador 1, desea cambiar la carta embaucadora"<<endl;
                            cout << "ingrese S/N"<<endl;
                            cin >> s;
                            if (s == 's' || s == 'S' )
                            {
                                system("cls");
                                puntosj1 = 0;
                                puntosj2 = 0;

                                cembaucadora(vcemb, tam);
                                PaloEmbaucador = embaucada(vcemb, 0);

                                puntosj1 += sacarPuntacos(ValoresManoJ1, PalosManoJ1, PaloEmbaucador);
                                puntosj2 += sacarPuntacos(ValoresManoJ2, PalosManoJ2, PaloEmbaucador);
                                puntosj1 - 20;

                                imprimirRondaj(j);
                                imprimirMano(vectorMano1, nombrej1, puntosj1);
                                imprimirMano(vectorMano2, nombrej2, puntosj2);
                                imprimirEmbaucadora(PaloEmbaucador);
                                ganadorRonda1 = funcGanador(puntosj1, puntosj2, nombrej1, nombrej2);
                                y = 1;
                            }
                            else if (acumuladorJ2R1 >= 20 )
                            {
                                cout << "Jugador 2, desea cambiar la carta embaucadora?"<<endl;
                                cout << "ingrese S/N"<<endl;
                                cin>> s;
                                if (s == 's' || s == 'S' )
                                {
                                    puntosj1 = 0;
                                    puntosj2 = 0;
                                    system("cls");
                                    imprimirRondaj(j);
                                    cembaucadora(vcemb, tam);
                                    PaloEmbaucador = embaucada(vcemb, 0);

                                    puntosj1 += sacarPuntacos(ValoresManoJ1, PalosManoJ1, PaloEmbaucador);
                                    puntosj2 += sacarPuntacos(ValoresManoJ2, PalosManoJ2, PaloEmbaucador);

                                    puntosj2 - 20;
                                    imprimirMano(vectorMano1, nombrej1, puntosj1);
                                    imprimirMano(vectorMano2, nombrej2, puntosj2);
                                    imprimirEmbaucadora(PaloEmbaucador);
                                    ganadorRonda1 = funcGanador(puntosj1, puntosj2, nombrej1, nombrej2);
                                    y = 1;
                                }
                            }
                        }
                            if(y==0){
                                ganadorRonda1 = funcGanador(puntosj1, puntosj2, nombrej1, nombrej2);
                                y = 1;
                            }

                        system("pause");

                        acumuladorJ1R2 += puntosj1;
                        acumuladorJ2R2 += puntosj2;

                        cout << " total puntos jugador 1 ronda 2: "<< acumuladorJ1R1+ acumuladorJ1R2 <<endl;
                        cout << " total puntos jugador 2 ronda 2: "<< acumuladorJ2R1+ acumuladorJ2R2 <<endl;

                        if(y==1){camino=1;}
                        break;


    }
                    case 6:
                    {


                        imprimirRondaj(j);
                        imprimirMano(vectorMano1, nombrej1, puntosj1);
                        imprimirMano(vectorMano2, nombrej2, puntosj2);
                        imprimirEmbaucadora(PaloEmbaucador);

                        if (acumuladorJ2R2 >= 20 )
                            {
                                cout << "Jugador 2, desea cambiar la carta embaucadora?"<<endl;
                                cout << "ingrese S/N"<<endl;
                                cin>> s;
                                if (s == 's' || s == 'S' )
                                {
                                    puntosj1 = 0;
                                    puntosj2 = 0;
                                    system("cls");
                                    imprimirRondaj(j);
                                    cembaucadora(vcemb, tam);
                                    PaloEmbaucador = embaucada(vcemb, 0);

                                    puntosj1 += sacarPuntacos(ValoresManoJ1, PalosManoJ1, PaloEmbaucador);
                                    puntosj2 += sacarPuntacos(ValoresManoJ2, PalosManoJ2, PaloEmbaucador);

                                    puntosj2 - 20;
                                    imprimirMano(vectorMano1, nombrej1, puntosj1);
                                    imprimirMano(vectorMano2, nombrej2, puntosj2);
                                    imprimirEmbaucadora(PaloEmbaucador);
                                    ganadorRonda1 = funcGanador(puntosj1, puntosj2, nombrej1, nombrej2);
                                    o = 1;
                                }
                            }
                        else if (acumuladorJ1R2 >= 20)
                        {
                            cout << "Jugador 1, desea cambiar la carta embaucadora"<<endl;
                            cout << "ingrese S/N"<<endl;
                            cin >> s;
                            if (s == 's' || s == 'S' )
                            {
                                system("cls");
                                puntosj1 = 0;
                                puntosj2 = 0;

                                cembaucadora(vcemb, tam);
                                PaloEmbaucador = embaucada(vcemb, 0);

                                puntosj1 += sacarPuntacos(ValoresManoJ1, PalosManoJ1, PaloEmbaucador);
                                puntosj2 += sacarPuntacos(ValoresManoJ2, PalosManoJ2, PaloEmbaucador);
                                puntosj1 - 20;

                                imprimirRondaj(j);
                                imprimirMano(vectorMano1, nombrej1, puntosj1);
                                imprimirMano(vectorMano2, nombrej2, puntosj2);
                                imprimirEmbaucadora(PaloEmbaucador);
                                ganadorRonda1 = funcGanador(puntosj1, puntosj2, nombrej1, nombrej2);
                                o = 1;
                            }
                            else{
                                ganadorRonda1 = funcGanador(puntosj1, puntosj2, nombrej1, nombrej2);
                                o = 1;
                                }

                            }

                            system("pause");
                            acumuladorJ1R3 += puntosj1;
                            acumuladorJ2R3 += puntosj2;


                            if(o==0){
                                ganadorRonda1 = funcGanador(puntosj1, puntosj2, nombrej1, nombrej2);
                                o = 1;
                            }
                            if(o==1){camino=7;}
                        break;
                    }
                    case 7:
                    {
                        system("cls");


                        acumuladorFinalJ1 = acumuladorJ1R1 + acumuladorJ1R2 + acumuladorJ1R3;
                        acumuladorFinalJ2 = acumuladorJ2R1 + acumuladorJ2R2 + acumuladorJ2R3;

                        cout << " FIN PARTIDA JUGADOR 1 : "<< acumuladorFinalJ1 <<endl;
                        cout << " FIN PARTIDA JUGADOR 2 : "<< acumuladorFinalJ2 <<endl;

                        maximopuntaje=ganadorPartida(acumuladorFinalJ1, acumuladorFinalJ2);

                        bool banderapuntaje = false;

                        if(banderapuntaje == false){
                            if(maximopuntaje == 1){
                            maxh = acumuladorFinalJ1;
                            maxj = nombrej1;
                            }
                            else if(maximopuntaje == 2){
                            maxh = acumuladorFinalJ2;
                            maxj = nombrej2;
                            }
                        }

                        else if(maximopuntaje > maxh){
                            if(maximopuntaje == 1){
                            maxh = acumuladorFinalJ1;
                            maxj = nombrej1;
                            }
                            else if(maximopuntaje == 2){
                            maxh = acumuladorFinalJ2;
                            maxj = nombrej2;
                            }
                        }
                        system("pause");
                        camino=8;

                        cout << " PUNTOS JUGADOR 1 RONDA 1: "<< acumuladorJ1R1 <<endl;
                        cout << " PUNTOS JUGADOR 1 RONDA 2: "<< acumuladorJ1R2 <<endl;
                        cout << " PUNTOS JUGADOR 1 RONDA 3: "<< acumuladorJ1R3 <<endl;
                        cout <<endl;

                        cout << " PUNTOS JUGADOR 2 RONDA 1: "<< acumuladorJ2R1 <<endl;
                        cout << " PUNTOS JUGADOR 2 RONDA 2: "<< acumuladorJ2R2 <<endl;
                        cout << " PUNTOS JUGADOR 2 RONDA 3: "<< acumuladorJ2R3 <<endl;
                        cout <<endl;

                        break;

                    }
                    } /// LLAVE FIN DEL SWITCH

                } /// LLAVE FIN DEL DO WHILE
                while(camino != 8);




            break;
        }
/// OPCION ESTADISTICAS (2)
        case 2:
        {
            system("cls");
            if(maxh ==0){
            cout << "todavia no han jugado por lo que no hay estadisticas"<<endl;
            }
            else{
            cout << "el mayor puntaje fue : " << maxh <<endl;
            cout << "del jugador  : " << maxj <<endl;
            }
            volvermenu();
            cin >> opcion;
            break;
        }
/// OPCION CREDITOS (3)
        case 3:
        {
            system("cls");
            menucreditos();
            volvermenu();
            cin >> opcion;
            break;
        }
/// OPCION AUXILIAR PARA VOLVER AL MENU (5)
        case 4:
        {
            system("cls");
            reglas();
            volvermenu();
            cin >> opcion;
            break;
        }
/// OPCION PARA SALIR DEL JUEGO (0)

        case 9:
        {
            menusalida();
            cin >> salida;
            if (salida == 0)
            {
                salir = true;
            }
            break;
        }
                                        default:
                    {

                    cout << "------------------------" << endl;
                    cout << "Ponga una opcion valida." << endl;
                    cout << "------------------------" << endl;
                    volvermenu();

                    break;
                    }


        }

    }
    while (!salir);




    return 0;
}
