/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PbaGrafoPersona.cpp
 * Author: Carlos
 *
 * Created on 8 de noviembre de 2016, 09:59 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Grafo.h"
#include "Nombre.h"
#include "Persona.h"
#include <vector>

/*
 * Simple C++ Test Suite
 */

void testGrafo() {
    Grafo grafo();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo (PbaGrafoPersona) message=error message sample" << std::endl;
    }
}

void testGrafo2() {
    Grafo orig;
    Grafo grafo(orig);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=error message sample" << std::endl;
    }
}

void testOperator(){
    Nombre& idVrt("Carlos","Solis","Fonseca");
    Persona& vrt;
    Grafo grafo();
    vrt = grafo[idVrt];
    if (vrt.obtNombre() != "Carlos" && vrt.obtEdad() != 27 && vrt.obtId() != "113980914" && vrt.obtSexo() != 'M') {
        std::cout << "%TEST_FAILED% time=0 testname=testOperator[] (PbaGrafoPersona) message=error prueba del operador [] fallo" << std::endl;
    }
}

void testAsgVrt() {
    Nombre& idVrt("Luis","Solano","Fernandez");
    Persona& vrt("Luis",18,"123456789",'M');
    Grafo grafo;
    grafo.asgVrt(idVrt, vrt);
    Persona vrt2 = grafo.obtVrt();
    if (vrt2.obtNombre() != "Luis" && vrt2.obtEdad() != 18 && vrt2.obtId() != "123456789" && vrt2.obtSexo() != 'M') {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgVrt (PbaGrafoPersona) message=error prueba asignar vertice fallo" << std::endl;
    }
}

void testAsgAdy() {
    Nombre& idVrtO("Donald","Trump");
    Nombre& idVrtD("Hilary","Clinton");
    bool rsl;
    Grafo grafo;
    grafo.asgAdy(idVrtO, idVrtD);
    vector<Nombre> vecAdy = grafo.obtAdy(idVrtO);
    for(int i = 0; i < vecAdy.size(); i++){
        if (vecAdy[i] == idVrtO)
            rsl = true;
        else
            rsl = false;
    }
    if(!rsl){
        std::cout << "%TEST_FAILED% time=0 testname=testAsgAdy (PbaGrafoPersona) message=error prueba asignar adyacencia fallo" << std::endl;
    }
}

void testElmVrt() {
    Nombre& idVrt("Fabiola", "Salazar","Artavia");
    Grafo grafo;
    grafo.elmVrt(idVrt);
    if (grafo.xstVrt(idVrt)) {
        std::cout << "%TEST_FAILED% time=0 testname=testElmVrt (PbaGrafoPersona) message=error prueba eliminar vertice fallo" << std::endl;
    }
}

void testElmAdy() {
    Nombre& idVrtO;
    Nombre& idVrtD;
    Grafo grafo;
    grafo.elmAdy(idVrtO, idVrtD);
    if (grafo.xstAdy(idVrtO,idVrtD)) {
        std::cout << "%TEST_FAILED% time=0 testname=testElmAdy (PbaGrafoPersona) message=error prueba eliminar adyacencia fallo" << std::endl;
    }
}

void testGeneraPequenyoMundo() {
    int K;
    double beta;
    Grafo grafo;
    grafo.generaPequenyoMundo(K, beta);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGeneraPequenyoMundo (PbaGrafoPersona) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PbaGrafoPersona" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo (PbaGrafoPersona)" << std::endl;
    testGrafo();
    std::cout << "%TEST_FINISHED% time=0 testGrafo (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo2 (PbaGrafoPersona)" << std::endl;
    testGrafo2();
    std::cout << "%TEST_FINISHED% time=0 testGrafo2 (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testOperator[] (PbaGrafoPersona)" << std::endl;
    testOperator();
    std::cout << "%TEST_FINISHED% time=0 testOperator[] (PbaGrafoPersona)" << std::endl;
    
    std::cout << "%TEST_STARTED% testAsgVrt (PbaGrafoPersona)" << std::endl;
    testAsgVrt();
    std::cout << "%TEST_FINISHED% time=0 testAsgVrt (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testAsgAdy (PbaGrafoPersona)" << std::endl;
    testAsgAdy();
    std::cout << "%TEST_FINISHED% time=0 testAsgAdy (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testElmVrt (PbaGrafoPersona)" << std::endl;
    testElmVrt();
    std::cout << "%TEST_FINISHED% time=0 testElmVrt (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testElmAdy (PbaGrafoPersona)" << std::endl;
    testElmAdy();
    std::cout << "%TEST_FINISHED% time=0 testElmAdy (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testGeneraPequenyoMundo (PbaGrafoPersona)" << std::endl;
    testGeneraPequenyoMundo();
    std::cout << "%TEST_FINISHED% time=0 testGeneraPequenyoMundo (PbaGrafoPersona)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

