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
    Grafo<Nombre,Persona> grafo;
    int totVrt = grafo.obtTotVrt();
    double vrtProm = grafo.obtPrmAdy();
    int totAdy = grafo.obtTotAdy();
    if (totVrt != 0 && vrtProm != 0.0 && totAdy != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo (PbaGrafoPersona) message=error prueba constructor estandar fallo" << std::endl;
    }
}

void testGrafo2() {
    Grafo<Nombre,Persona> orig;
    Nombre nombre1("Maria","Alvarado", "Toledo"); Persona persona1("Maria","123456789",21,'F');
    Nombre nombre2("Enrique", "Castro", "Vargas"); Persona persona2("Enrique", "012345678",23,'M');
    Nombre nombre3("Melissa", "Fernadez", "Osorio"); Persona persona3("Melissa", "901234567",19, 'F');
    
    orig.asgVrt(nombre1, persona1); orig.asgVrt(nombre2, persona2); orig.asgVrt(nombre3, persona3);
    orig.asgAdy(nombre1, nombre2); orig.asgAdy(nombre1, nombre3); orig.asgAdy(nombre2, nombre3);
    
    Grafo<Nombre,Persona> grafo(orig);
    if ( (!grafo.xstVrt(nombre1) && !grafo.xstVrt(nombre2) && !grafo.xstVrt(nombre3)) || 
         (!grafo.xstAdy(nombre1, nombre2) && !grafo.xstAdy(nombre1, nombre3) && !grafo.xstAdy(nombre2, nombre3))) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=prueba constructor de copias fallo" << std::endl;
    }
    
    Persona datos1; Persona datos2; Persona datos3;
    
    datos1 = grafo.obtVrt(nombre1); datos2 = grafo.obtVrt(nombre2); datos3 = grafo.obtVrt(nombre3);
    if (datos1.obtNombre() != "Maria" && datos1.obtEdad() != 21 && datos1.obtId() != "123456789" && datos1.obtSexo() != 'F'){
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=prueba constructor de copias fallo con la persona1" << std::endl;
    }
    if (datos2.obtNombre() != "Enrique" && datos2.obtEdad() != 23 && datos2.obtId() != "012345678" && datos2.obtSexo() != 'M'){
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=prueba constructor de copias fallo con la persona2" << std::endl;
    }
    if (datos3.obtNombre() != "Melissa" && datos3.obtEdad() != 19 && datos3.obtId() != "901234567" && datos3.obtSexo() != 'F'){
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (PbaGrafoPersona) message=prueba constructor de copias fallo con la persona3" << std::endl;
    }
}

void testOperator(){
    Nombre idVrt("Carlos","Solis","Fonseca");
    Persona vrt("Carlos","113980914",27,'M');
    Persona vrtPba;
    Grafo<Nombre,Persona> grafo;
    grafo.asgVrt(idVrt,vrt);
    vrtPba = grafo[idVrt];
    if (vrt.obtNombre() != "Carlos" && vrt.obtEdad() != 27 && vrt.obtId() != "113980914" && vrt.obtSexo() != 'M') {
        std::cout << "%TEST_FAILED% time=0 testname=testOperator[] (PbaGrafoPersona) message=error prueba del operador [] fallo" << std::endl;
    }
}

void testAsgVrt() {
    Nombre idVrt("Luis","Solano","Fernandez");
    Persona vrt("Luis","123456789",18,'M');
    Persona vrt2;
    Grafo<Nombre,Persona> grafo;
    grafo.asgVrt(idVrt, vrt);
    vrt2 = grafo.obtVrt(idVrt);
    if ( vrt2.obtNombre() != "Luis" && vrt2.obtEdad() != 18 && vrt2.obtId() != "123456789" && vrt2.obtSexo() != 'M') {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgVrt (PbaGrafoPersona) message=error prueba asignar vertice fallo" << std::endl;
    }
}

void testAsgAdy() {
    Nombre idVrtO("Donald","Trump","Republicano");
    Nombre idVrtD("Hilary","Clinton","Democrata");
    bool rsl;
    Grafo<Nombre,Persona> grafo;
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
    Nombre idVrt("Fabiola", "Salazar","Artavia");
    Persona vrt("Fabiola","123456789",18,'F');
    Grafo<Nombre,Persona> grafo;
    grafo.asgVrt(idVrt,vrt);
    grafo.elmVrt(idVrt);
    if (grafo.xstVrt(idVrt)) {
        std::cout << "%TEST_FAILED% time=0 testname=testElmVrt (PbaGrafoPersona) message=error prueba eliminar vertice fallo" << std::endl;
    }
}

void testElmAdy() {
    Nombre idVrtO;
    Nombre idVrtD;
    Grafo<Nombre,Persona> grafo;
    grafo.asgAdy(idVrtO, idVrtD);
    grafo.elmAdy(idVrtO, idVrtD);
    if (grafo.xstAdy(idVrtO,idVrtD)) {
        std::cout << "%TEST_FAILED% time=0 testname=testElmAdy (PbaGrafoPersona) message=error prueba eliminar adyacencia fallo" << std::endl;
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

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

