/* 
 * File:   Nombre.h
 * Author: a76326
 *
 * Created on 7 de noviembre de 2016, 04:20 PM
 */

#ifndef NOMBRE_H
#define	NOMBRE_H

#include <string>

using namespace std;

class Nombre {
public:
    Nombre();
    Nombre(const Nombre& orig);
    virtual ~Nombre();
    void asgNombre(string n);
    void asgApellido1(string ap1);
    void asgApellido2(string ap2);
    bool operator<=(const Nombre&) const;
    bool operator==(const Nombre&) const;
private:
    string nombre;
    string apellido1;
    string apellido2;
};

#endif	/* NOMBRE_H */

