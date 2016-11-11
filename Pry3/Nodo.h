/* 
 * File:   Nodo.h
 * Author: alan.calderon
 *
 * Created on 24 de octubre de 2016, 06:00 PM
 */

#ifndef NODO_H
#define	NODO_H
#include <chrono>
#include <random>

class Nodo {
public:
    // Representa un nodo de la red de computadores sobre la cual se aplica la simulación
	// de dispersión de virus.
	
    /* TIPO PÚBLICO DE ESTADOS DE VÉRTICES */
    enum E{ // representa el tipo de estados de la red de infección
        S, // representa un vértice susceptible de infección
        I, // representa un vértice infectado
        R, // representa un vértice resistente
    };
    
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    
    // EFE: retorna el valor del estado del nodo.
    E obtEst() const;
    
    // EFE: retorna el valor del temporizador de chequeo de antivirus del nodo.
    int obtTmpChqVrs() const;

    // EFE: retorna el valor del contador de chequeo de antivirus del nodo.	
    int obtCntChqVrs() const;
    
    /* MÉTODOS MODIFICADORES */

    // MOD: *this.
    // EFE: cambia el estado del nodo a ne.
    void modEst(E ne);

    // MOD: *this.
    // EFE: cambia el valor del temporizador de chequeo de virus del nodo a nt.
    void modTmpChqVrs(int nt);
    
    // MOD: *this.
    // EFE: incrementa en uno el valor del contador de chequeo de virus del nodo.
    void actCntChqVrs();

    // MOD: *this.
    // EFE: cambia el estado a I (infectado) del nodo.
    void infectar();
    
    // MOD: *this
    // EFE: asigna el valor del temporizador del nodo al azar entre 1 y vcf.
    //      vcf o virus-check-frecuency: frecuencia máxima de chequeo antivirus.
    void azarizarTmpChqVrs(int vcf);
    
private:
    E std; // representa el estado del nodo
    int tmpChqVrs; // representa la frecuencia del chequeo de virus en el nodo
    int cntChqVrs; // representa el contador de chequeo de virus: va de 0 a tmpChqVrs  
};

#endif	/* NODO_H */