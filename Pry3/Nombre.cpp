/* 
 * File:   Nombre.cpp
 * Author: a76326
 * 
 * Created on 7 de noviembre de 2016, 04:20 PM
 */
 
#include "Nombre.h"
 
Nombre::Nombre():nombre(""), apellido1(""), apellido2("") {
}
 
Nombre::Nombre(string n, string ap1, string ap2){
    nombre = n;
    apellido1 = ap1;
    apellido2 = ap2;
}
 
 
Nombre::Nombre(const Nombre& orig) {
    nombre = orig.nombre;
    apellido1 = orig.apellido1;
    apellido2 = orig.apellido2;
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
 
string Nombre::obtNombre() const {
    return nombre;
}
 
string Nombre::obtApellido1() const {
    return apellido1;
}
 
string Nombre::obtApellido2() const {
    return apellido2;
}
 
bool Nombre::operator<(const Nombre& n) const {
    if(apellido1 < n.apellido1 || apellido2 < n.apellido2 || nombre < n.nombre)
        return true;
    else
        return false;
}
 
bool Nombre::operator==(const Nombre& n) const {
    if(apellido1 == n.apellido1 && apellido2 == n.apellido2 && nombre == n.nombre)
        return true;
    else
        return false;
}