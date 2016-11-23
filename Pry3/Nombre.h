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
    Nombre(string n, string ap1, string ap2);
    Nombre(const Nombre& orig);
    virtual ~Nombre();
    
    /*SETTERS*/
    
    //MOD: *this.
    //EFE: Asigna el nombre al identificador.
    void asgNombre(string n);
    
    //MOD: *this.
    //EFE: Asigna el primer apellido al identificador.
    void asgApellido1(string ap1);
    
    //MOD: *this.
    //EFE: Asigna el segundo apellido al identificador.
    void asgApellido2(string ap2);
    
    /*GETTERS*/
    
    //EFE: Retorna el nombre del identificador.
    string obtNombre() const;
    
    //EFE: Retorna el primer apellido del identificador.
    string obtApellido1() const;
    
    //EFE: Retorna el segundo apellido del identificador.
    string obtApellido2() const;
    
    //EFE: Sobrecarga el operador <.
    bool operator<(const Nombre& n) const;
    
    //EFE: Sobrecarga el operador ==.
    bool operator==(const Nombre& n) const;
private:
    string nombre; //Se inicializa el nombre del identificador.
    string apellido1; //Se inicializa el primer apellido del identificador.
    string apellido2; //Se inicializa el segundo apellido del identificador.
};

#endif	/* NOMBRE_H */

