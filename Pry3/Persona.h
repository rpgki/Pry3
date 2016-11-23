/* 
 * File:   Persona.h
 * Author: a76326
 *
 * Created on 7 de noviembre de 2016, 03:36 PM
 */

#ifndef PERSONA_H
#define	PERSONA_H

#include <string>

using namespace std;

class Persona {
    //Clase que representa los datos de una persona
public:
    Persona();
    Persona(string n, string idd, int ed, char sx);
    Persona(const Persona& orig);
    virtual ~Persona();
    
    /*SETTERS*/
    
    //MOD: *this.
    //EFE: asigna el nombre de la persona. 
    void asgNombre(string n);
    
    //MOD: *this.
    //EFE: asigna el id de la persona. 
    void asgId(string idd);
    
    //MOD: *this.
    //EFE: asigna el nombre de la persona. 
    
    //MOD: *this.
    //EFE: asigna la edad de la persona. 
    void asgEdad(int ed);
    
    //MOD: *this.
    //EFE: asigna el sexo de la persona. 
    void asgSexo(char sx);
    
    /*GETTERS*/
    
    //EFE: retorna el nombre de la persona.
    string obtNombre() const;
    
    //EFE: retorna el identificador de la persona.
    string obtId() const;
    
    //EFE: retorna la edad de la persona.
    int obtEdad() const;
    
    //EFE: retorna el sexo de la persona.
    char obtSexo() const;
    
private:
        string nombre; //Se inicializa el nombre.
        string id; //Se inicializa el identificador.
        int edad; //Se inicializa la edad.
        char sexo; //se inicializa el sexo.
};

#endif	/* PERSONA_H */

