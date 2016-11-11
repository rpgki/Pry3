/* 
 * File:   Nodo.cpp
 * Author: alan.calderon
 * 
 * Created on 24 de octubre de 2016, 06:00 PM
 */

#include "Nodo.h"

Nodo::Nodo():std(S), tmpChqVrs(1), cntChqVrs(0) {
}

Nodo::Nodo(const Nodo& orig) {
    E copStd = orig.std;
    int copTmpChqVrs = orig.tmpChqVrs;
    int copCntChqVrs = orig.cntChqVrs;
    
    std = copStd;
    tmpChqVrs = copTmpChqVrs;
    cntChqVrs = copCntChqVrs;
}

Nodo::~Nodo() {
}

Nodo::E Nodo::obtEst() const {
    return std;
}

int Nodo::obtCntChqVrs() const {
    return cntChqVrs;
}

int Nodo::obtTmpChqVrs() const {
    return tmpChqVrs;
}

void Nodo::modTmpChqVrs(int nt) {
    tmpChqVrs = nt;
}

void Nodo::modEst(E ne) {
    std = ne;
}

void Nodo::infectar() {
    std = I;
}

void Nodo::azarizarTmpChqVrs(int vcf){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Se crea la semilla
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> nmAltr(1, vcf); //Se genera una distribución uniforme desde 1 hasta el valor ingresado por en vcf
    int num = nmAltr(generator); //Se guarda el número generado
    tmpChqVrs = num; //Se asigna el número generado al temporizador del vertice i
}

void Nodo::actCntChqVrs(){
    if(tmpChqVrs == cntChqVrs)
        cntChqVrs = 0;
    else
        cntChqVrs++;
}