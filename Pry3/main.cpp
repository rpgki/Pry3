/* 
 * File:   main.cpp
 * Author: alan.calderon
 *
 * Created on 1 de septiembre de 2016, 06:48 PM
 */

#include <iostream>
#include <vector>
using namespace std;

#include "Grafo.h"
#include "Simulador.h"
#include "Nodo.h"
#include "Persona.h"
#include "Nombre.h"

// EFE: despliega en la ventana dibujos de nodos y arcos
void display(void){
    
}

// EFE: despliega en la ventana el estado de g.
void visualizar(Grafo<Nodo, int>&g){
    
}

int main(int argc, char** argv) {
    Grafo<Nodo, int> grf;
    // aquí habría que llenar el conjunto de vértices de grf usando asgVrt(...).
    grf.generaPequenyoMundo(88,0.5); // con promedio de 88 adyacencias por nodo y beta = 0.5
    Simulador sml(grf);
    visualizar(grf);
    
    Nombre n1("Araya", "Batistuta", "Ana");
    Nombre n2("Araya", "Abarca", "Ana");
    Nombre n3("Araya", "Batistuta", "Luis");
    Nombre n4(n1);
    
    if(n1 < n3)
        cout << "n1 es menor a n3" << endl;
    else
        cout << "n3 es menor a n1" << endl;
    
    Persona p("Carlos","113980914",27,'M');
    Persona p2(p);
    
    cout << p2.obtId() << endl;
    
    return 0;
}