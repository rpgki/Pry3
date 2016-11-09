/* 
 * File:   Persona.cpp
 * Author: a76326
 * 
 * Created on 7 de noviembre de 2016, 03:36 PM
 */

#include "Persona.h"

Persona::Persona(): nombre(""),id(""),edad(0),sexo() {
}

Persona::Persona(const string& n, const string& idd, const int& ed, const char& sx): nombre(n), id(idd), edad(ed), sexo(sx) {
}

Persona::Persona(const Persona& orig) {
    string copia_nombre = orig.nombre;
    string copia_id = orig.id;
    int copia_edad = orig.edad;
    char copia_sexo = orig.sexo;
    
    nombre = copia_nombre;
    id = copia_id;
    edad = copia_edad;
    sexo = copia_sexo;
}

Persona::~Persona() {
}

void Persona::asgEdad(int ed) {
    edad = ed;
}

void Persona::asgId(string idd) {
    id = idd;
}

void Persona::asgNombre(string n) {
    nombre = n;
}

void Persona::asgSexo(char sx) {
    sexo = sx;
}

string& Persona::obtNombre() {
    return nombre;
}

string& Persona::obtId() {
    return id;
}

int& Persona::obtEdad() {
    return edad;
}

char& Persona::obtSexo() {
    return sexo;
}
