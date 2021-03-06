/* 
 * File:   Persona.cpp
 * Author: a76326
 * 
 * Created on 7 de noviembre de 2016, 03:36 PM
 */

#include "Persona.h"

Persona::Persona(): nombre(""),id(""),edad(0),sexo() {
}

Persona::Persona(string n, string idd, int ed, char sx) {
    nombre = n;
    id = idd;
    edad = ed;
    sexo = sx;
}

Persona::Persona(const Persona& orig) {
    nombre = orig.nombre;
    id = orig.id;
    edad = orig.edad;
    sexo = orig.sexo;
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

string Persona::obtNombre() const {
    return nombre;
}

string Persona::obtId() const {
    return id;
}

int Persona::obtEdad() const {
    return edad;
}

char Persona::obtSexo() const {
    return sexo;
}
