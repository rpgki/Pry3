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
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void asgNombre(string n);
    void asgId(string idd);
    void asgEdad(int ed);
    void asgSexo(char sx);
    
private:
        string nombre;
        string id;
        int edad;
        char sexo;
};

#endif	/* PERSONA_H */

