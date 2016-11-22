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
    Grafo<int, Nodo> grf;
    // aquí habría que llenar el conjunto de vértices de grf usando asgVrt(...).
    
    Nodo ndo1; Nodo ndo2; Nodo ndo3; Nodo ndo4; Nodo ndo5;
    Nodo ndo6; Nodo ndo7; Nodo ndo8; Nodo ndo9; Nodo nd10;
    
    grf.asgVrt(0,ndo1); grf.asgVrt(1,ndo1); grf.asgVrt(2,ndo1); grf.asgVrt(3,ndo1); grf.asgVrt(4,ndo1);
    grf.asgVrt(5,ndo1); grf.asgVrt(6,ndo1); grf.asgVrt(7,ndo1); grf.asgVrt(8,ndo1); grf.asgVrt(9,ndo1);
    
    grf.generaPequenyoMundo(4,0.5); // con promedio de 88 adyacencias por nodo y beta = 0.5
    
    cout << "Coeficiente global: " << grf.coeficienteAgrupamiento() << endl;
    
    cout << "Coeficiente de 0: " << grf.coeficienteAgrupamiento(0) << endl;
    cout << "Coeficiente de 1: " << grf.coeficienteAgrupamiento(1) << endl;
    cout << "Coeficiente de 2: " << grf.coeficienteAgrupamiento(2) << endl;
    cout << "Coeficiente de 3: " << grf.coeficienteAgrupamiento(3) << endl;
    cout << "Coeficiente de 4: " << grf.coeficienteAgrupamiento(4) << endl;
    cout << "Coeficiente de 5: " << grf.coeficienteAgrupamiento(5) << endl;
    cout << "Coeficiente de 6: " << grf.coeficienteAgrupamiento(6) << endl;
    cout << "Coeficiente de 7: " << grf.coeficienteAgrupamiento(7) << endl;
    cout << "Coeficiente de 8: " << grf.coeficienteAgrupamiento(8) << endl;
    cout << "Coeficiente de 9: " << grf.coeficienteAgrupamiento(9) << endl;
    
    /*cout << grf.obtTotAdy(0) << endl;
    cout << grf.obtTotAdy(1) << endl;
    cout << grf.obtTotAdy(2) << endl;
    cout << grf.obtTotAdy(3) << endl;
    cout << grf.obtTotAdy(4) << endl;
    cout << grf.obtTotAdy(5) << endl;
    cout << grf.obtTotAdy(6) << endl;
    cout << grf.obtTotAdy(7) << endl;
    cout << grf.obtTotAdy(8) << endl;
    cout << grf.obtTotAdy(9) << endl;*/
    
    //  Simulador sml(grf);
    //  visualizar(grf);
     
    Nombre n1("Batistuta", "Araya", "Ana");
    Nombre n2("Araya", "Batistuta", "Ana");
    Nombre n3("Araya", "Batistuta", "Luis");
    Nombre n4(n1);
     
    if(n4 < n3)
        cout << "n4 es menor a n3" << endl;
    else
        cout << "n3 es menor a n4" << endl;
     
    if(n2 < n1)
        cout << "n2 es menor a n1" << endl;
    else
        cout << "n1 es menor a n2" << endl;
    
    
    
    return 0;
}