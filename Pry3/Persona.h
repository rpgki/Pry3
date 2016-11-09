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
    Persona(const string& n, const string& idd, const int& ed, const char& sx);
    Persona(const Persona& orig);
    virtual ~Persona();
    void asgNombre(string n);
    void asgId(string idd);
    void asgEdad(int ed);
    void asgSexo(char sx);
    string& obtNombre();
    string& obtId();
    int& obtEdad();
    char& obtSexo();
    
private:
        string nombre;
        string id;
        int edad;
        char sexo;
};

#endif	/* PERSONA_H */

