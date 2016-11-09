/* 
 * File:   Nombre.cpp
 * Author: a76326
 * 
 * Created on 7 de noviembre de 2016, 04:20 PM
 */

#include "Nombre.h"

Nombre::Nombre():nombre(""), apellido1(""), apellido2("") {
}

Nombre::Nombre(const string& n, const string& ap1, const string& ap2):nombre(n), apellido1(ap1), apellido2(ap2) {
}


Nombre::Nombre(const Nombre& orig) {
    string copiaNombre = orig.nombre;
    string copiaApellido1 = orig.apellido1;
    string copiaApellido2 = orig.apellido2;
    
    nombre = copiaNombre;
    apellido1 = copiaApellido1;
    apellido2 = copiaApellido2;
}

Nombre::~Nombre() {
}

void Nombre::asgNombre(string n) {
    nombre = n;
}

void Nombre::asgApellido1(string ap1) {
    apellido1 = ap1;
}

void Nombre::asgApellido2(string ap2) {
    apellido2 = ap2;
}

string& Nombre::obtNombre(){
    return nombre;
}

string& Nombre::obtApellido1() {
    return apellido1;
}

string& Nombre::obtApellido2() {
    return apellido2;
}

bool Nombre::operator<(const Nombre& n) const {
    if(apellido1 < n.apellido1)
        return apellido1 < n.apellido1;
    else if(apellido2 < n.apellido2)
        return apellido2 < n.apellido2;
    else if(nombre < n.nombre)
        return nombre < n.nombre;
}

bool Nombre::operator==(const Nombre& n) const {
    return apellido1 == n.apellido1 && apellido2 == n.apellido2 && nombre == n.nombre;
}
