/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PbaGrafoNodo.cpp
 * Author: Carlos
 *
 * Created on 10 de noviembre de 2016, 07:02 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Grafo.h"
#include "Nodo.h"

/*
 * Simple C++ Test Suite
 */

void testGrafo() {
    Grafo<int,Nodo> grafo;
    int totVrt = grafo.obtTotVrt();
    double vrtProm = grafo.obtPrmAdy();
    int totAdy = grafo.obtTotAdy();
    if (totVrt != 0 && vrtProm != 0.0 && totAdy != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo (PbaGrafoPersona) message=error prueba constructor estandar fallo" << std::endl;
    }
}

void testGrafo2() {
    Grafo<int,Nodo> orig;
    Nodo ndo1; Nodo ndo2; Nodo ndo3;
    
    orig.asgVrt(0, ndo1); orig.asgVrt(1, ndo2); orig.asgVrt(2, ndo3);
    orig.asgAdy(0, 1); orig.asgAdy(0, 2); orig.asgAdy(1, 2);
    
    Grafo<int,Nodo> grafo(orig);
    if ( (!grafo.xstVrt(0) && !grafo.xstVrt(1) && !grafo.xstVrt(2)) || 
         (!grafo.xstAdy(0, 1) && !grafo.xstAdy(0, 2) && !grafo.xstAdy(1, 2))) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=prueba constructor de copias fallo" << std::endl;
    }
    
    Nodo datos1; Nodo datos2; Nodo datos3;
    
    datos1 = grafo.obtVrt(0); datos2 = grafo.obtVrt(1); datos3 = grafo.obtVrt(2);
    if (datos1.obtCntChqVrs() != 0 && datos1.obtEst() != Nodo::S && datos1.obtTmpChqVrs() != 1){
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=prueba constructor de copias fallo con el nodo1" << std::endl;
    }
    if (datos2.obtCntChqVrs() != 0 && datos2.obtEst() != Nodo::S && datos2.obtTmpChqVrs() != 1){
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=prueba constructor de copias fallo con el nodo2" << std::endl;
    }
    if (datos3.obtCntChqVrs() != 0 && datos3.obtEst() != Nodo::S && datos3.obtTmpChqVrs() != 1){
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=prueba constructor de copias fallo con el nodo3" << std::endl;
    }
}

void testOperator(){
    Nodo vrt; Nodo vrtPba;
    Grafo<int,Nodo> grafo;
    grafo.asgVrt(0,vrt);
    vrtPba = grafo[0];
    if (vrtPba.obtCntChqVrs() != 0 && vrtPba.obtEst() != Nodo::S && vrtPba.obtTmpChqVrs() != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testOperator[] (PbaGrafoPersona) message=error prueba del operador [] fallo" << std::endl;
    }
}

void testAsgVrt() {
    Nodo vrt;
    Grafo<int,Nodo> grafo;;
    grafo.asgVrt(0, vrt);
    Nodo vrt2 = grafo.obtVrt(0);
    if (vrt2.obtCntChqVrs() != 0 && vrt2.obtEst() != Nodo::S && vrt2.obtTmpChqVrs() != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgVrt (PbaGrafoNodo) message=error prueba asignar vertice fallo" << std::endl;
    }
}

void testAsgAdy() {
    Nodo ndo1; Nodo ndo2;
    Grafo<int,Nodo> grafo;
    grafo.asgVrt(0,ndo1); grafo.asgVrt(1,ndo2);
    grafo.asgAdy(0, 1);
    if (!grafo.xstAdy(0,1)) {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgAdy (PbaGrafoNodo) message=error prueba asignar adyacencia fallo" << std::endl;
    }
}

void testElmVrt() {
    Nodo ndo;
    Grafo<int,Nodo> grafo;
    grafo.asgVrt(0,ndo);
    grafo.elmVrt(0);
    if (grafo.xstVrt(0)) {
        std::cout << "%TEST_FAILED% time=0 testname=testElmVrt (PbaGrafoNodo) message=error prueba eliminar vertice fallo" << std::endl;
    }
}

void testElmAdy() {
    int idVrtO = 0; Nodo ndo1;
    int idVrtD = 0; Nodo ndo2;
    Grafo<int,Nodo> grafo;
    grafo.asgVrt(0,ndo1); grafo.asgVrt(1,ndo2);
    grafo.asgAdy(idVrtO, idVrtD);
    grafo.elmAdy(idVrtO, idVrtD);
    if (grafo.xstAdy(idVrtO,idVrtD) || grafo.xstAdy(idVrtD,idVrtO)) {
        std::cout << "%TEST_FAILED% time=0 testname=testElmAdy (PbaGrafoPersona) message=error prueba eliminar adyacencia fallo" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PbaGrafoNodo" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo (PbaGrafoNodo)" << std::endl;
    testGrafo();
    std::cout << "%TEST_FINISHED% time=0 testGrafo (PbaGrafoNodo)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo2 (PbaGrafoNodo)" << std::endl;
    testGrafo2();
    std::cout << "%TEST_FINISHED% time=0 testGrafo2 (PbaGrafoNodo)" << std::endl;

    std::cout << "%TEST_STARTED% testAsgVrt (PbaGrafoNodo)" << std::endl;
    testAsgVrt();
    std::cout << "%TEST_FINISHED% time=0 testAsgVrt (PbaGrafoNodo)" << std::endl;

    std::cout << "%TEST_STARTED% testAsgAdy (PbaGrafoNodo)" << std::endl;
    testAsgAdy();
    std::cout << "%TEST_FINISHED% time=0 testAsgAdy (PbaGrafoNodo)" << std::endl;

    std::cout << "%TEST_STARTED% testElmVrt (PbaGrafoNodo)" << std::endl;
    testElmVrt();
    std::cout << "%TEST_FINISHED% time=0 testElmVrt (PbaGrafoNodo)" << std::endl;

    std::cout << "%TEST_STARTED% testElmAdy (PbaGrafoNodo)" << std::endl;
    testElmAdy();
    std::cout << "%TEST_FINISHED% time=0 testElmAdy (PbaGrafoNodo)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

