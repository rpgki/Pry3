/* 
 * File:   Simulador.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 06:46 PM
 */
 
#include "Simulador.h"
 
Simulador::Simulador(Grafo<int, Nodo>& g):mapAct(g) {
     
}
 
Simulador::~Simulador() {
     
}
 
void Simulador::iniciarSimulacion(int ios, double vsc, int mvcf, double rc, double grc){
    //Se infectan los vertices de acuerdo a distribucion de probabilidad comparandolo con el parametro ios
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Se establece la semilla
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> nmAltr(0, mapAct.obtTotVrt() - 1); //Se genera una distribución uniforme de enteros entre 0 y la cantidad de vertices - 1
    while (ios != 0) {
        int num = nmAltr(generator); //Se guarda el número generado
        if (mapAct[num].obtEst() != 1) {// Se infectan aleatoriamente los nodos de acuerdo al valor ingresado en ios
            mapAct[num].infectar();
            ios--;
        }
    }
     
    //Se aleatoriza el temporizador de chequeo de virus.
    for(int i = 0; i < mapAct.obtTotVrt(); i++){
        mapAct[i].azarizarTmpChqVrs(mvcf);
    }
     
    prbInf = vsc; 
    rec = rc;
    resis = grc;
 }
 
void Simulador::simular() {
    Grafo<int, Nodo> mapAnt(mapAct); //Se crea una instancia de tipo grafo que crea una copia, la cual servira como base para los estados en el tiempo t.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Se planta la semilla.
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> prb(0.0, 1.0); //Se crea el dado.
    vector<int> vecTemp; //Se crea un vector de adyacentes para cada vertice
    for (int i = 0; i < mapAnt.obtTotVrt(); i++) { //Se recorre el arreglo de vertices
        vecTemp = mapAnt.obtAdy(i); //Se guarda el vector de adyacentes.
        mapAct[i].actCntChqVrs(); //Se actualiza el contador de chequeo de virus
        //Si el vertice es susceptible, entonces se evalua cada uno de sus adyacentes.
        //Si alguno infectado se genera un numero aleatorio para evaluar la probabilidad de infeccion.
        if (mapAnt[i].obtEst() == 0) {
            for (int j = 0; j < mapAnt.obtTotAdy(i); j++) {
                if (mapAnt[vecTemp[j]].obtEst() == 1) {
                    double prbAlt = prb(generator);
                    if (prbAlt <= prbInf) {
                        mapAct[i].modEst(Nodo::I);
                        j = mapAnt.obtTotAdy(i);
                    }
                }
            }
        } else { //Si el vertice no es susceptible, y esta infectado se evalua la probabilidad de recuperarse.
            if (mapAnt[i].obtEst() == 1 && mapAnt[i].obtCntChqVrs() == 0) {
                double prbAlt = prb(generator);
                if (prbAlt <= rec) {
                    prbAlt = prb(generator);
                    if (prbAlt <= resis) { //Si el vertice infectado se recupera, entonces se evalua la probabilidad de que se vuelva resistente al virus.
                        mapAct[i].modEst(Nodo::R);
                    } else {
                        mapAct[i].modEst(Nodo::S);
                    }
                }
            }
        }
    }
}