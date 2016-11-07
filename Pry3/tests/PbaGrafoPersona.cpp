/* 
 * File:   PbaGrafoPersona.cpp
 * Author: a76326
 *
 * Created on 07/11/2016, 03:20:21 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Grafo.h"

/*
 * Simple C++ Test Suite
 */

void testAsgAdy() {
    const IV& idVrtO;
    const IV& idVrtD;
    Grafo grafo;
    grafo.asgAdy(idVrtO, idVrtD);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgAdy (PbaGrafoPersona) message=error message sample" << std::endl;
    }
}

void testAsgVrt() {
    const IV& idVrt;
    const V& vrt;
    Grafo grafo;
    grafo.asgVrt(idVrt, vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgVrt (PbaGrafoPersona) message=error message sample" << std::endl;
    }
}

void testElmAdy() {
    const IV& idVrtO;
    const IV& idVrtD;
    Grafo grafo;
    grafo.elmAdy(idVrtO, idVrtD);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testElmAdy (PbaGrafoPersona) message=error message sample" << std::endl;
    }
}

void testElmVrt() {
    const IV& idVrt;
    Grafo grafo;
    grafo.elmVrt(idVrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testElmVrt (PbaGrafoPersona) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PbaGrafoPersona" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testAsgAdy (PbaGrafoPersona)" << std::endl;
    testAsgAdy();
    std::cout << "%TEST_FINISHED% time=0 testAsgAdy (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testAsgVrt (PbaGrafoPersona)" << std::endl;
    testAsgVrt();
    std::cout << "%TEST_FINISHED% time=0 testAsgVrt (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testElmAdy (PbaGrafoPersona)" << std::endl;
    testElmAdy();
    std::cout << "%TEST_FINISHED% time=0 testElmAdy (PbaGrafoPersona)" << std::endl;

    std::cout << "%TEST_STARTED% testElmVrt (PbaGrafoPersona)" << std::endl;
    testElmVrt();
    std::cout << "%TEST_FINISHED% time=0 testElmVrt (PbaGrafoPersona)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

