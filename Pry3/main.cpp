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
    return 0;
}