/* 
 * File:   Simulador.h
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 06:46 PM
 */
 
#ifndef SIMULADOR_H
#define SIMULADOR_H
 
 
using namespace std;
 
#include "Grafo.h"
#include "Nodo.h"
#include <chrono>
#include <random>
 
class Simulador {
    // Representa el proceso de simulación de la infección en la red de computadoras.
     
public:
     
    // EFE: Construye un simulador que transformará al grafo g.
    Simulador(Grafo<int, Nodo>& g);
 
    // Destruye a *this retornando toda la memoria asignada dinámicamente.
    ~Simulador();
 
 
    // REQ: el grafo asociado (el pasado al constructor) esté bien construido.
    // MOD: el grafo asociado.    
    // EFE: inicializa el simulador con los siguientes parámetros:
    //      ios o initial-outbreak-size [1..N], N cantidad de vértices: cantidad
    //           de vértices infectados al comienzo de la simulación.
    //      vsc o virus-spread-chance [0..0.1]: probabilidad de infección.
    //      mvcf o virus-check-frecuency [1..20]: máxima frecuencia de chequeo antivirus.
    //      rc o recovery-chance [0..0.1]: probabilidad de recuperación de infección.
    //      grc o gain-resistance-chance [0..1]: probabilidad de lograr resistencia.   
    void iniciarSimulacion(int ios, double vsc, int mvcf, double rc, double grc);
     
    // REQ: el grafo asociado (el pasado al constructor) esté bien construido.
    // MOD: el grafo asociado.
    // EFE: aplica al grafo asociado una transformación con base en las reglas de 
    //      cambio de estado para los vértices:
    //      1. un vértice sólo puede ser infectado por alguno de sus vecinos infectados
    //         con probabilidad vsc.
    //      2. sólo un vértice infectado cuyo temporizador de chequeo de virus está en cero
    //         puede recuperarse con probabilidad rc.
    //      3. sólo un vértice recuperado puede ganar resistencia con probabilidad grc.
    //      4. Sólo las transformaciones #2 y #3 pueden ser simultáneas. 
    void simular();
 
private:
    Grafo<int, Nodo>& mapAct;
    int tam; // Cantidad de vertices infectados al azar.
    double prbInf; // Probabilidad de infeccion
    int maxFrqChqVrs; // Numero maximo temporizador de chequeo de virus.
    double rec; // Probabilidad de recuperacion.
    double resis; // Probabilidad volverse resistente.
    // se deben agregar más variables de estado.
};
 
#endif  /* SIMULADOR_H */