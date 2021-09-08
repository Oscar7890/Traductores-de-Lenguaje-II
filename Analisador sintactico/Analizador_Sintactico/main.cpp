#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"
#include "pila.h"

using namespace std;

/*int tablaLRE[3][3]={
    2, 0, 1,
    0, -1, 0,
    0, -2, 0
};*/

int tablaLR[5][4]={
    2, 0, 0, 1,
    0, 0, -1, 0,
    0, 3, 0, 0,
    4, 0, 0, 0,
    0, 0, -2, 0
};

int tablaLR2[5][4]={
    2, 0, 0, 1,
    0, 0, -1, 0,
    0, 3, -3, 0,
    2, 0, 0, 4,
    0, 0, -2, 0
};

/*void ejemplo1()
{
    Pila pila;
    pila.push(22);
    pila.push(3);
    pila.push(4);
    pila.push(5);

    pila.muestra();

    cout<<pila.top()<<endl;
    cout<<pila.top()<<endl;

    cout<<pila.pop()<<endl;
    cout<<pila.pop()<<endl;
}*/

/*void ejemplo2()
{
    Lexico lexico("+-+");

    while (! lexico.terminado() ){
        lexico.sigSimbolo();
        cout << lexico.simbolo << "\t" << lexico.tipoAcad(lexico.tipo) << endl;
    }

}*/

/*void ejemplo3()
{
    Pila pila;
    int fila, columna, accion;
    bool aceptacion= false;
    Lexico lexico("a");

    pila.push( TipoSimbolo::PESOS );
    pila.push( 0 );
    lexico.sigSimbolo();

    fila= pila.top();
    columna= lexico.tipo;
    accion= tablaLRE[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;

    pila.push( lexico.tipo );
    pila.push( accion );
    lexico.sigSimbolo();

    fila= pila.top();
    columna= lexico.tipo;
    accion= tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl<< endl;

    pila.pop();
    pila.pop();

    fila= pila.top();
    columna= 2; //el no terminal que representa a E
    accion= tablaLRE[fila][columna];

    //transición
    pila.push( 2 ); //el 2 es el entero que representa el no terminal E
    pila.push( accion );
    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;

    fila= pila.top();
    columna= lexico.tipo;
    accion= tablaLRE[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;
    aceptacion= accion == -1;
    if (aceptacion) cout << "Aceptacion" << endl;
}*/

void ejercicio1()
{
    Pila pila;
    int fila, columna, accion;
    bool aceptacion= false;
    Lexico lexico("a+b");

    pila.push( TipoSimbolo::PESOS );
    pila.push( 0 );
    lexico.sigSimbolo();
    fila= pila.top();
    columna= lexico.tipo;
    accion= tablaLR[fila][columna];
    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;

    while (lexico.simbolo.compare("$") != 0) {
        pila.push( lexico.tipo );
        pila.push( accion );
        lexico.sigSimbolo();
        fila= pila.top();
        columna= lexico.tipo;
        accion= tablaLR[fila][columna];
        pila.muestra();
        cout << "entrada: " << lexico.simbolo << endl;
        cout << "accion: " << accion << endl<< endl;
    }

    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();

    fila= pila.top();
    columna= 3; //el no terminal que representa a E
    accion= tablaLR[fila][columna];

    //transición
    pila.push( 3 ); //el 3 es el entero que representa el no terminal E
    pila.push( accion );
    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;

    fila= pila.top();
    columna= lexico.tipo;
    accion= tablaLR[fila][columna];

    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;
    aceptacion= accion == -1;
    if (aceptacion) cout << "Aceptacion" << endl;
}

void ejercicio2()
{
    Pila pila;
    int fila, columna, accion;
    bool aceptacion= false;
    Lexico lexico("a+b+c+d+e+f");

    pila.push( TipoSimbolo::PESOS );
    pila.push( 0 );
    lexico.sigSimbolo();
    fila= pila.top();
    columna= lexico.tipo;
    accion= tablaLR2[fila][columna];
    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;

    while (lexico.simbolo.compare("$") != 0) {
        pila.push( lexico.tipo );
        pila.push( accion );
        lexico.sigSimbolo();
        fila= pila.top();
        columna= lexico.tipo;
        accion= tablaLR2[fila][columna];
        pila.muestra();
        cout << "entrada: " << lexico.simbolo << endl;
        cout << "accion: " << accion << endl<< endl;
    }


    while (accion != -1) {
        if (accion > 0){
            pila.pop();
            pila.pop();

            fila= pila.top();
            columna= 3; //el no terminal que representa a E
            accion= tablaLR2[fila][columna];

            //transición
            pila.push( 3 ); //el 3 es el entero que representa el no terminal E
            pila.push( accion );
            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl << endl;

            fila= pila.top();
            columna= lexico.tipo;
            accion= tablaLR2[fila][columna];

            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl << endl;
            aceptacion= accion == -1;
            if (aceptacion) cout << "Aceptacion" << endl;
        }
        else if(accion < 0){
            pila.pop();
            pila.pop();
            pila.pop();
            pila.pop();
            pila.pop();
            pila.pop();

            fila= pila.top();
            columna= 3; //el no terminal que representa a E
            accion= tablaLR2[fila][columna];

            //transición
            pila.push( 3 ); //el 3 es el entero que representa el no terminal E
            pila.push( accion );
            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl << endl;

            fila= pila.top();
            columna= lexico.tipo;
            accion= tablaLR2[fila][columna];

            pila.muestra();
            cout << "entrada: " << lexico.simbolo << endl;
            cout << "accion: " << accion << endl << endl;
            aceptacion= accion == -1;
            if (aceptacion) cout << "Aceptacion" << endl;
        }
        else break;

    }
}

int main(int argc, char *argv[]){

    //cin.get();

    //ejemplo1();

    //ejemplo2();

    //ejemplo3();

    cout<<"Ejercicio 1 Gramatica: E -> id + id"<<endl<<endl;
    ejercicio1();

    cout<<"\n\nEjecicio 2 Gramatica: E -> id + E | id"<<endl<<endl;
    ejercicio2();

    return 0;
}
