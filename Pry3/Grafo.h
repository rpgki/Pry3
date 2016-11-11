/* 
 * File:   Grafo.h
 * Author: alan.calderon
 *
 * Created on 1 de septiembre de 2016, 06:49 PM
 */

#ifndef GRAFO_H
#define	GRAFO_H


#include <vector>
#include <map>
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
        V vertice;
        vector< IV > lstAdy; // representa la lista de nodos adyacentes
        Vrt(): vertice(), lstAdy() {};
    };
    
    map< IV, Vrt > mapNodos;
};

template < typename IV, typename V >
Grafo<IV,V>::Grafo(){
    
}

template < typename IV, typename V >
Grafo<IV,V>::~Grafo() {

}

template < typename IV, typename V >
Grafo<IV,V>::Grafo(const Grafo<IV,V>& orig) {

}

template < typename IV, typename V >
bool Grafo<IV,V>::xstVrt(const IV& idVrt) const {

}

template < typename IV, typename V >
bool Grafo<IV,V>::xstAdy(const IV& idVrtO, const IV& idVrtD) const {

}

template < typename IV, typename V >
const V& Grafo<IV,V>::obtVrt(const IV& idVrt) const {
    
}

template < typename IV, typename V >
const vector<IV>& Grafo<IV,V>::obtAdy(const IV& idVrt) const {

}

template < typename IV, typename V >
int Grafo<IV,V>::obtTotVrt() const {

}

template < typename IV, typename V >
int Grafo<IV,V>::obtTotAdy() const {

}

template < typename IV, typename V >
int Grafo<IV,V>::obtTotAdy(const IV& idVrt) const {

}

template < typename IV, typename V >
double Grafo<IV,V>::obtPrmAdy() const {

}

template < typename IV, typename V >
double Grafo<IV,V>::coeficienteAgrupamiento(const IV& idVrt) const {

}

template < typename IV, typename V >
double Grafo<IV,V>::coeficienteAgrupamiento() const {
    
}

template < typename IV, typename V >
V& Grafo<IV,V>::operator[](const IV& idVrt){
    
}

template < typename IV, typename V >
void Grafo<IV,V>::asgVrt(const IV& idVrt, const V& vrt){
    
}

template < typename IV, typename V >
void Grafo<IV,V>::asgAdy(const IV& idVrtO, const IV& idVrtD){
    
}

template < typename IV, typename V >
void Grafo<IV,V>::elmVrt(const IV& idVrt){
    
}

template < typename IV, typename V >
void Grafo<IV,V>::elmAdy(const IV& idVrtO, const IV& idVrtD){
    
}

template < typename IV, typename V >
void Grafo<IV,V>::generaPequenyoMundo(int K, double beta) {
    
}
#endif	/* GRAFO_H */