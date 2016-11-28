/* 
 * File:   main.cpp
 * Author: alan.calderon
 *
 * Created on 1 de septiembre de 2016, 06:48 PM
 */
 
#include "Grafo.h"
#include "Simulador.h"
#include "Nodo.h"
#include "Persona.h"
#include "Nombre.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <windows.h>
#include <GL/glut.h>
#include "Datos.h"
#include <stdio.h>
 
using namespace std;
 
 
string nArch;
int N;
int K;
double beta;
int valor;
 
Grafo<int, Nodo> crearGrafo() {
    cout << "Programa de simulacion de un virus en una red. Por favor digite 1 si desea crear una red personalizada o 2 si desea ingresar el archivo" << endl;
    cin >> valor;
    Grafo<int, Nodo> graf;
    Nodo ndo;
    int cont = 0;
    int cntVrt = 0;
    if (valor == 1) {
        cout << "Cantidad de vertices: " << endl;
        cin >> N;
        cout << "Grado de vertices promedio: " << endl;
        cin >> K;
        cout << "Probabilidad de adyacencia: " << endl;
        cin >> beta;
        while (N > 0) {
            graf.asgVrt(cont, ndo);
            N--;
            cont++;
        }
        graf.generaPequenyoMundo(K, beta);
        return graf;
    } else if (valor == 2) {
        cout << "Nombre del archivo: " << endl;
        cin >> nArch;
        vector<Nodo> vectorNodos;
        string hilera; //se inicializa la variable que contendra las hileras del archivo
        string aux; //en esta variable se guarda cada caracter de la hilera
        int pos = 0; //contador para posicion del arreglo que contendra los nodos
        ifstream grafo(nArch); //se lee el archivo que contiene el grafo
 
        if (!grafo) { // operador ! sobrecargado
            cerr << "No se pudo abrir el archivo de entrada" << endl;
            exit(1);
        }
 
        getline(grafo, hilera); //se lee la primera linea del archivo
        cntVrt = stoi(hilera); //se convierte la primera linea a entero
        vectorNodos.reserve(cntVrt); //Se asigna el tamaño de memoria al vector
        while (getline(grafo, hilera)) { //mientras no se acaben las hileras del archivo
            graf.asgVrt(cont, ndo);
            for (int i = 0; i < hilera.size() - 1; i++) { //este ciclo lee todos los caracteres de la hilera
                if (hilera[i] != ' ') {
                    aux = aux + hilera[i]; //se guarda el caracter en aux
                } else {
                    graf.asgAdy(cont, (stoi(aux)));
                    aux = "";
                }
            }
            graf.asgAdy(cont, (stoi(aux)));
            aux = "";
            pos = pos + 1; //se aumenta el contador de posiciones para el arreglo de vertices
            cont++;
        }
    } else {
        cout << "Introduzca una opcion valida" << endl;
        exit(1);
    }
}
Grafo<int, Nodo> g = crearGrafo();
Datos d(g);
Simulador s(g);
  
int tam;
int maxFreq;
double inf;
double recu;
double res;
      
// EFE: Dibuja una línea con dos puntos cuadrados en sus extremos centrados en (xo,yo) y (xd,yd).
void dibujarLinea(float xo, float yo, float xd, float yd, Nodo::E e, Grafo<int, Nodo> g){
  glPointSize(9.0); //Ajusta el tamaño de los puntos
  if(e == Nodo::S){
  glColor3f(0.0, 0.0, 1.0); //Color blanc
  glBegin(GL_POINTS); // dibuja los puntos
    glVertex2f(xo, yo);
  } else{ if(e == Nodo::I){
  glColor3f(1.0, 0.0, 0.0); //Color blanc
  glBegin(GL_POINTS); // dibuja los puntos
    glVertex2f(xo, yo);
  }else{ 
      glColor3f(0.0, 1.0, 0.0); //Color blanc
  glBegin(GL_POINTS); // dibuja los puntos
    glVertex2f(xo, yo);
  }
  }
  glEnd();
  glLineWidth(1.6); //Ajusta el ancho de las lineas
  glColor3f(0.5, 0.5, 0.5); //Color blanco
  glBegin(GL_LINES); // dibuja una sola linea
    glVertex2f(xo, yo);
    glVertex2f(xd, yd);
  glEnd();
}
 
void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos3f(x, y, 0);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
 
void display(void) // no puede tener parámetros, por eso se usan variables globales
{
    Datos d(g);
    vector<int> VecAdya;
    for (int i = 0; i < g.obtTotVrt(); i++) {
        VecAdya = g.obtAdy(i);
        for (int j = 0; j < g.obtTotAdy(i); j++) {
            dibujarLinea(d.obtCrdX(i), d.obtCrdY(i), d.obtCrdX(VecAdya[j]), d.obtCrdY(VecAdya[j]), d.obtEst(i),g);
        }
    }
    glFlush();
}
  
 
// EFE: captura un evento del teclado mientras el control esté en la ventana.
void keyboard(unsigned char key, int x, int y)
{
   
  switch (key)
  {
    case 32: // para capturar el evento blanco-tecleado
        s.simular();
        glutPostRedisplay(); // redibuja
        break;
  }
}
  
void visualizar(int argc, char **argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Red de Nodos");
    glutKeyboardFunc(keyboard); // declara una función para capturar eventos del teclado
    s.iniciarSimulacion(tam, inf, maxFreq, recu, res);
    glutDisplayFunc(display); // dibuja la primera imagen
    glutMainLoop(); // otorga el control a la ventana, cuando se cierra retorna al main.    
}
  
int main(int argc, char **argv) {
    cout << "Acontinuacion se va a iniciar el programa de simulacion. Por favor ingrese los parametros deseados." << endl;
    cout << "Para propagar el virus presione la tecla espaciadora, una vez se haya abierto la ventana con la red" << endl;
    cout << "El color rojo representa un vertice infectado." << endl;
    cout << "El color verde representa un vertice resistente al virus." << endl;
    cout << "El color azul representa un vertice susceptible al virus." << endl;
    cout << "Por favor ingrese los parametros deseados: " << endl;
    cout << "Nodos infectados: " << endl;
    cin >> tam;
    cout << "Probabilidad de infeccion: " << endl;
    cin >> inf;
    cout << "Maxima frecuencia de chequeo de virus: " << endl;
    cin >> maxFreq;
    cout << "Probabilidad de recuperacion: " << endl;
    cin >> recu;
    cout << "Probabilidad de resistencia: " << endl;
    cin >> res;
    visualizar(argc, argv);
    return 0;
}