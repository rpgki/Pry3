/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PbaSimulador.cpp
 * Author: Carlos
 *
 * Created on 25 de noviembre de 2016, 08:41 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Simulador.h"

/*
 * Simple C++ Test Suite
 */

void testSimular() {
    //Se inicializan las instancias necesarias para construir el grafo.
    Nodo ndo1; Nodo ndo2; Nodo ndo3; Nodo ndo4; Nodo ndo5;
    
    //Se construye el grafo
    Grafo<int, Nodo> grf;
    grf.asgVrt(0, ndo1); grf.asgVrt(1,ndo2); grf.asgVrt(2, ndo3); grf.asgVrt(3, ndo4); grf.asgVrt(4, ndo5);
    grf.asgAdy(0, 3); grf.asgAdy(0, 4);
    grf.asgAdy(1, 4); grf.asgAdy(1, 2); grf.asgAdy(1, 3);
    grf.asgAdy(2, 1); grf.asgAdy(2, 3);
    grf.asgAdy(3, 0); grf.asgAdy(3, 1); grf.asgAdy(3, 2); grf.asgAdy(3, 4);
    grf.asgAdy(4, 0); grf.asgAdy(4, 1); grf.asgAdy(4, 4);
    
    //Se copia el grafo para los diferentes casos de las pruebas
    Grafo<int, Nodo> grf2(grf); Grafo<int, Nodo> grf3(grf); Grafo<int, Nodo> grf4(grf);
    
    //Se infectan los vertices 1 y 2
    grf[1].infectar(); grf[2].infectar();
    
    // Primera prueba: Que un vertice en estado susceptible pase a infectado.
    Simulador simulador1(grf);
    simulador1.iniciarSimulacion(0, 1.0, 3, 0.0, 0.0);
    simulador1.simular();
    if (grf[3].obtEst() != Nodo::I && grf[4].obtEst() != Nodo::I) {
        std::cout << "%TEST_FAILED% time=0 testname=testSimular (PbaSimulador) message=error el metodo simular fallo al cambiar el estado de 3 y 4 a infectado" << std::endl;
    }
    
    //Se infectan los vertices 1 y 2
    grf2[1].infectar(); grf2[2].infectar();
    // Segunda prueba: Que un vertice en estado infectado pase a susceptible.
    Simulador simulador2(grf2);
    simulador2.iniciarSimulacion(0, 0.0, 3, 1.0, 0.0);
    simulador2.simular();
    if (grf2[1].obtEst() != Nodo::S && grf2[2].obtEst() != Nodo::S) {
        std::cout << "%TEST_FAILED% time=0 testname=testSimular (PbaSimulador) message=error el metodo simular fallo al cambiar el estado de 1 y 2 a susceptible" << std::endl;
    }
    
    //Se infectan los vertices 1 y 2
    grf3[1].infectar(); grf3[2].infectar();
    // Tercera prueba: Que un vertice en estado infectado pase a resistente.
    Simulador simulador3(grf3);
    simulador3.iniciarSimulacion(0, 0.0, 5, 1.0, 1.0);
    simulador3.simular();
    if (grf3[1].obtEst() != Nodo::R && grf3[2].obtEst() != Nodo::R) {
        std::cout << "%TEST_FAILED% time=0 testname=testSimular (PbaSimulador) message=error el metodo simular fallo al cambiar el estado de 1 y 2 a resistente" << std::endl;
    }
    
    //Se infectan los vertices 1 y 2
    grf4[1].infectar(); grf4[2].infectar();
    
    // Cuarta prueba: Que un vertice en estado susceptible no cambie su estado al no tener adyacentes infectados.
    Simulador simulador4(grf4);
    simulador4.iniciarSimulacion(0, 0.5, 5, 0.5, 0.5);
    simulador4.simular();
    if (grf4[0].obtEst() != Nodo::S) {
        std::cout << "%TEST_FAILED% time=0 testname=testSimular (PbaSimulador) message=error el metodo simular fallo al no mantener susceptible al vertice 0" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PbaSimulador" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testSimular (PbaSimulador)" << std::endl;
    testSimular();
    std::cout << "%TEST_FINISHED% time=0 testSimular (PbaSimulador)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

