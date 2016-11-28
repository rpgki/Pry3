/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
/* 
 * File:   Datos.h
 * Author: Alan
 *
 * Created on 11 de octubre de 2016, 12:41 PM
 */
 
#ifndef DATOS_H
#define DATOS_H
 
#include "Grafo.h"
#include "Nodo.h"
#include <vector>
 
 
class Datos {
public:
    Datos(Grafo<int, Nodo>& g);
    ~Datos();
     
    void inicializarDatos();
     
    float obtCrdX(int vert);
    float obtCrdY(int vert);
    Nodo::E obtEst(int vert);
private:
    struct NodoDato {
        Nodo::E std; // representa el estado del nodo
        float crdX; // representa la frecuencia del chequeo de virus en el nodo
        float crdY; // representa el contador de chequeo de virus: va de 0 a tmpChqVrs        
        NodoDato(): std(Nodo::S), crdX(0), crdY(0){};
    };
     
    vector<NodoDato> VecDatos;
    Grafo<int, Nodo>& grafo;
};
 
#endif /* DATOS_H */

