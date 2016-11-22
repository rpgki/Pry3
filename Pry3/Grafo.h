/* 
 * File:   Grafo.h
 * Author: alan.calderon
 *
 * Created on 1 de septiembre de 2016, 06:49 PM
 */
 
#ifndef GRAFO_H
#define GRAFO_H
 
 
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
using namespace std;
 
template < typename IV, typename V >
class Grafo {
    // Representa un grafo con vértices tipo V e identificadores de vértices tipo IV.
    // Requiere:
    // 1. IV() y V() estén definidos.
    // 2. IV(const IV&) y V(const V&) estén definidos.
    // 3. bool IV::operator<(const IV&) const esté definido.
    // 4. bool IV::operator==(const IV&) const esté definido.
     
public:
     
    /* CONSTRUCTORES */
     
    // Construye un grafo cuyos conjuntos de vértices y adyacencias están vacíos. 
    Grafo();
     
    // Construye una copia idéntica a orig.
    Grafo(const Grafo& orig);
     
    // Destruye a *this retornando toda la memoria asignada dinámicamente.
    ~Grafo();
 
    /* MÉTODOS OBSERVADORES BÁSICOS */
     
    // EFE: retorna true si existe un vértice con identificador idVrt.
    bool xstVrt(const IV& idVrt) const;
     
    // REQ: existan en *this vértices con identificadores idVrtO y idVrtD.
    // EFE: retorna true si existe un arco entre los vértices, false en caso contrario.
    bool xstAdy(const IV& idVrtO, const IV& idVrtD) const;
     
    // REQ: xstVrt(idVrt) == true.
    // EFE: retorna por referencia el vértice asociado a idVrt.
    // NOTA: no permite la modificación del vértice en el contexto de invocación.
    const V& obtVrt(const IV& idVrt) const;
     
    // REQ: xstVrt(idVrt) == true.
    // EFE: retorna un vector de identificadores de los vértices
    //      adyacentes al vértice identificado por idVrt.
    // NOTA: no permite la modificación del vector en el contexto de invocación.
    const vector<IV>& obtAdy(const IV& idVrt) const;
 
    // EFE: retorna el total de vértices en *this.
    int obtTotVrt() const;
     
    // EFE: retorna el total de adyacencias en *this.
    int obtTotAdy() const; 
     
    // REQ: xstVrt(idVrt) == true.
    // EFE: retorna la cantidad total de adyacencias del vértice.
    int obtTotAdy(const IV& idVrt) const;    
     
    // EFE: retorna el promedio simple de adyacencias por nodo.
    double obtPrmAdy() const;
     
    /* MÉTODOS OBSERVADORES ESPECIALES */
     
    // REQ: que exista en *this un vértice con identificador idVrt.
    // EFE: retorna el "local clustering coefficient" o coeficiente local de agrupamiento
    //      para el vértice indicado por vrt.
    //      La definición aparece en: http://en.wikipedia.org/wiki/Clustering_coefficient
    //      Se calcula como el cociente entre la cantidad efectiva de arcos entre los
    //      vecinos del vértice indicado por idVrt dividida por la cantidad total de posibles
    //      arcos entre todos los vecinos del vértice indicado por idVrt.
    double coeficienteAgrupamiento(const IV& idVrt) const;
     
    // EFE: calcula el coeficiente de agrupamiento de todo el grafo como el
    //      promedio simple del coeficiente de agrupamiento de todos sus nodos.
    double coeficienteAgrupamiento() const;
 
    /* MÉTODOS MODIFICADORES BÁSICOS */
 
    // REQ: xstVrt(idVrt) == true.
    // MOD: *this.
    // EFE: retorna la referencia al vértice con identificador idVrt.
    V& operator[](const IV& idVrt);
 
    // REQ: xstVrt(idVrt) == false.
    // MOD: *this.
    // EFE: agrega al conjunto de vértices vrt con el identificador idVrt.
    void asgVrt(const IV& idVrt, const V& vrt);
     
    // REQ: (xstVrt(idVrtO) && xstVrt(idVrtD))== true.
    // REQ: (xstAdy(idVrtO) && xstAdy(idVrtD))== false.
    // MOD: *this.
    // EFE: agrega a *this la adyacencia (idVrtO, idVrtD) y la correspondiente (idVrtD, idVrtO).
    void asgAdy(const IV& idVrtO, const IV& idVrtD);
 
    // MOD: *this.
    // EFE: Elimina el vértice identificado por idVrt. 
    //      Si xstVrt(idVrt) == false, queda sin efecto.
    void elmVrt(const IV& idVrt);
     
    // MOD: *this.
    // EFE: Elimina la adyacencia entre idVrtO e idVrtD. 
    //      Si xstAdy(idVrtO, idVrtD) == false, queda sin efecto.    
    void elmAdy(const IV& idVrtO, const IV& idVrtD);
     
    /* MODIFICADORES ESPECIALES: */
     
    // REQ: que obtTotVrt() >> 10 (mucho más grande que).
    // REQ: que obtTotAdy() == 0. 
    // REQ: ( obtTotVrt() >> K >> ln(obtTotVrt()) >> 1 ) && ( 0 <= beta <= 1 ) && ( K mod 2 == 0)
    // MOD: *this.
    // EFE: con base en los vértices previamente agregados a *this, genera las adyacencias
    //      siguiendo el algoritmo de Watts y Strogatz para "pequeños mundos".
    //      Ver:https://en.wikipedia.org/wiki/Watts_and_Strogatz_model
    void generaPequenyoMundo(int K, double beta);
     
private:
    struct Vrt {
        Vrt(V nv):vertice(nv),lstAdy(){};
        Vrt(const Vrt& orig):vertice(orig.vertice), lstAdy(orig.lstAdy){};
        V vertice;
        vector< IV > lstAdy; // representa la lista de nodos adyacentes
        Vrt(): vertice(), lstAdy() {};
    };
     
    map< IV, Vrt > mapNodos;
    int totAdy;
    int totVrt;
    int AdyPrm;
    int totAdyMap;
};
 
template < typename IV, typename V >
Grafo<IV,V>::Grafo(): totAdy(0), totVrt(0),AdyPrm(0){
}
 
template < typename IV, typename V >
Grafo<IV,V>::~Grafo() {
}
 
template < typename IV, typename V >
Grafo<IV,V>::Grafo(const Grafo<IV,V>& orig) {
    mapNodos = orig.mapNodos;
    totAdy = orig.totAdy;
    totVrt= orig.totVrt;
    AdyPrm= orig.AdyPrm;
     
}
 
template < typename IV, typename V >
bool Grafo<IV,V>::xstVrt(const IV& idVrt) const {
    bool result = false;
    typename map<IV,Vrt>::const_iterator it = mapNodos.find(idVrt);
    if(it != mapNodos.end()){
        result = true;
    }
    return result;
}
 
template < typename IV, typename V >
bool Grafo<IV,V>::xstAdy(const IV& idVrtO, const IV& idVrtD) const {
    bool result = false;
    for(int i = 0; i < mapNodos.at(idVrtO).lstAdy.size(); i++){
        if(!result && mapNodos.at(idVrtO).lstAdy.at(i) == idVrtD){
            result = true;
        }
    }
    return result;
}
 
template < typename IV, typename V >
const V& Grafo<IV,V>::obtVrt(const IV& idVrt) const {
    return mapNodos.find(idVrt)->second.vertice;
}
 
template < typename IV, typename V >
const vector<IV>& Grafo<IV,V>::obtAdy(const IV& idVrt) const {
    return mapNodos.find(idVrt)->second.lstAdy;
}
 
template < typename IV, typename V >
int Grafo<IV,V>::obtTotVrt() const {
    return mapNodos.size();
}
 
template < typename IV, typename V >
int Grafo<IV,V>::obtTotAdy() const {
    int result = 0;
    for(typename map<IV,Vrt>::const_iterator it = mapNodos.begin(); it != mapNodos.end() ; it++){
        result += it->second.lstAdy.size();
    }
    return result;
}
 
template < typename IV, typename V >
int Grafo<IV,V>::obtTotAdy(const IV& idVrt) const {
    return mapNodos.at(idVrt).lstAdy.size();
}
 
template < typename IV, typename V >
double Grafo<IV,V>::obtPrmAdy() const {
    int totAdydeaqui = 0;
    int totVrtdeaqui = mapNodos.size();
    for(typename map<IV,Vrt>::const_iterator it = mapNodos.begin(); it != mapNodos.end() ; it++){
        totAdydeaqui += it->second.lstAdy.size();
    }
    if(totVrtdeaqui == 0)
        return totVrtdeaqui;
    else
        return totAdydeaqui/totVrtdeaqui;
}
 
template < typename IV, typename V >
double Grafo<IV,V>::coeficienteAgrupamiento(const IV& idVrt) const {
    double coefLoc; //se crea la variable que almacenara el coeficiente local
    vector<IV> adyLoc = mapNodos.find(idVrt)->second.lstAdy; //se inicializa un vector que contendra las adyacencias de vrt
    double nv = 0.0; // se inicializa la variable total de arcos entre adyacencias de vrt en 0
    int kv = mapNodos.find(idVrt)->second.lstAdy.size(); //se guarda el total de adyacencias para vrt
    if (kv == 0) {
        coefLoc = 0;
    } else {
        if (kv != 1) { //se calcula el coeficiente siempre y cuando haya al menos dos adyacencias
            for (int i = 0; i < kv - 1; i++) { //se lee cada elemento de la lista
                for (int j = i + 1; j < kv; j++) { //se lee el elemento siguiente a i de la lista
                    if (Grafo::xstAdy(adyLoc[i], adyLoc[j])) { //se evalua si el elemento i tiene esta conectado con algun elemento j
                        nv++; //se aumenta el contador de conexiones   
                    }
                }
            }
            coefLoc = (2 * nv) / (kv * (kv - 1)); //se calcula el coeficiente local
        }
    }
    return coefLoc; //se retorna el valor del coeficiente para vrt
}
 
template < typename IV, typename V >
double Grafo<IV,V>::coeficienteAgrupamiento() const {
    int vertices = Grafo::obtTotVrt(); //se obtiene el total de vertices en *this
    double res = 0; //se crea la variable resultado que almacenara el coeficiente global
    for (typename map<IV,Vrt>::const_iterator it = mapNodos.begin(); it != mapNodos.end(); ++it) { //se recorren las posiciones del arreglo que contiene a los vertices
        res += Grafo::coeficienteAgrupamiento(it->first); //se suma el coeficiente local para cada vertice
    }
    res = res / vertices; //se calcula el promedio el cual es el coeficiente global
    return res; //se retorna el coeficiente global 
}
 
template < typename IV, typename V >
V& Grafo<IV,V>::operator[](const IV& idVrt){
    mapNodos[idVrt].vertice;
}
 
template < typename IV, typename V >
void Grafo<IV,V>::asgVrt(const IV& idVrt, const V& vrt){
     mapNodos.insert(pair<IV,Vrt>(idVrt,Vrt(vrt)));
}
 
template < typename IV, typename V >
void Grafo<IV,V>::asgAdy(const IV& idVrtO, const IV& idVrtD){
    mapNodos[idVrtO].lstAdy.push_back(idVrtD);
    mapNodos[idVrtD].lstAdy.push_back(idVrtO);
}
 
template < typename IV, typename V >
void Grafo<IV,V>::elmVrt(const IV& idVrt){
    mapNodos.erase(idVrt);
}
 
template < typename IV, typename V >
void Grafo<IV,V>::elmAdy(const IV& idVrtO, const IV& idVrtD){
    typename vector<IV>::const_iterator it; typename vector<IV>::const_iterator it2;
    it = find(mapNodos[idVrtO].lstAdy.begin(),mapNodos[idVrtO].lstAdy.end(),idVrtD);
    if(it != mapNodos[idVrtO].lstAdy.end()){
        mapNodos[idVrtO].lstAdy.erase(it);
    }
    it2 = find(mapNodos[idVrtD].lstAdy.begin(),mapNodos[idVrtD].lstAdy.end(),idVrtO);
    if(it2 != mapNodos[idVrtD].lstAdy.end()){
        mapNodos[idVrtD].lstAdy.erase(it);
    }
}
 
template < typename IV, typename V >
void Grafo<IV,V>::generaPequenyoMundo(int K, double beta) {
    vector<IV> NoSonAdyDeI;
    int N = mapNodos.size();
    bool aux = false; bool aux2 = false; //Se crea auxiliar para buscar elementos dentro del vector de adyacencias
    //int auxInt; //Auxiliar para borrar un elemento de la lista de adyacencias
    typename vector<IV>::const_iterator it; //Se inicializa el iterador para el vector de adyacentes.
    typename vector<IV>::const_iterator it2;//Iterador auxiliar para borrar elementos.
    Vrt v; 
    int i = 0;
     
    for(typename map<IV, Vrt>::const_iterator iit = mapNodos.begin(); iit != mapNodos.end(); ++iit){ //Se alambran los vértices con sus vecinos de acuerdo al parámetro K
        v.lstAdy.clear(); //Se limpia el vector
        int j = 0;
        for(typename map<IV, Vrt>::const_iterator jt = mapNodos.begin(); jt != mapNodos.end(); ++jt){
            if((abs(i-j)%(N - 1 -(K/2)) > 0) && ((abs(i-j)%(N - 1 -(K/2)) <= K/2))){
                //v.lstAdy.push_back(iit->first); //Se guarda el adyacente
                mapNodos[iit->first].lstAdy.push_back(jt->first);
            }
            j++;
        }
        i++;
    }
 
    // Se construye el generador de números al azar basado en una semilla tomada
    // del reloj del sistema:    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    // Se cargan los dados
    std::uniform_real_distribution<double> dados_0_1(0.0, 1.0);
 
 
    //#2: se re-alambran las conexiones usando beta
    for (typename map<IV, Vrt>::const_iterator iit = mapNodos.begin(); iit != mapNodos.end(); iit++){
        for (typename map<IV, Vrt>::const_iterator jt = mapNodos.begin(); jt != mapNodos.end(); jt++) {
            aux = false;
            // Genera un número al azar entre 0 y 1
            double numAzar = dados_0_1(generator);
            it = find(iit->second.lstAdy.begin(),iit->second.lstAdy.end(),jt->first); //Se guarda un iterador si se encuentra el vertice adyacente en i.
            if(it != iit->second.lstAdy.end()){ //Si se encuentra el vertice en el vector entonces el auxiliar es verdadero.
                aux = true;
                it2 = find(jt->second.lstAdy.begin(),jt->second.lstAdy.end(),iit->first);
            }
            else
                aux = false;
            if (aux == true &&(numAzar <= beta)) { // se re-alambra
                // se borra j de la lstAdy de i
                mapNodos[iit->first].lstAdy.erase(it);
                mapNodos[jt->first].lstAdy.erase(it2);
                 
                NoSonAdyDeI.clear();
                int cntNoAdyDeI = 0;
 
                // se cuentan e identifican todos los nodos no adyacentes a i
                for (typename map<IV, Vrt>::const_iterator kt = mapNodos.begin(); kt != mapNodos.end(); kt++) {
                    aux2 = false;
                    it = find(mapNodos[iit->first].lstAdy.begin(),mapNodos[iit->first].lstAdy.end(),kt->first); //Se guarda un iterador si se encuentra el vertice adyacente en k.
                    if(it != mapNodos[iit->first].lstAdy.end()) //Si se encuentra el vertice en el vector entonces el auxiliar es verdadero.
                        aux2 = true;
                    else
                        aux2 = false;
                    if (aux2 == false) {
                        NoSonAdyDeI.push_back(kt->first);
                        cntNoAdyDeI++;
                    }
                }
 
                // seleccionar entre todas las no-adyacencias una basándose en 
                // la distribución uniforme
                std::uniform_int_distribution<int> dados_0_N(0, cntNoAdyDeI - 1);
                int posNuevaAdy = dados_0_N(generator);
 
                // se busca nueva adyacencia en el vector de no-adyacencias
                IV nuevaAdy = NoSonAdyDeI[posNuevaAdy];
                 
                // se re-alambra o sustituye j por k
                mapNodos[iit->first].lstAdy.push_back(nuevaAdy);
                sort( mapNodos[iit->first].lstAdy.begin(), mapNodos[iit->first].lstAdy.end());
                mapNodos[nuevaAdy].lstAdy.push_back(iit->first);
                sort( mapNodos[nuevaAdy].lstAdy.begin(), mapNodos[nuevaAdy].lstAdy.end());
            }
        }
    }
}
#endif  /* GRAFO_H */