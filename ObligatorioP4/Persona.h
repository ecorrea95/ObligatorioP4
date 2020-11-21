#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "String.h"

class Persona
{
    private:
        int cedula;
        String nombre;
    public:
        Persona();
        Persona(int, String);
        Persona(const Persona &);
        ~Persona();
        Persona operator= (const Persona &);
        int getCedula();
        String getNombre();
};



#endif // PERSONA_H_INCLUDED
