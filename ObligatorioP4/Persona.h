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
        Persona(int, String);   ///Es necesario si es abstracta?
        virtual ~Persona();
        int getCedula();
        String getNombre();
        virtual String tipoObjeto() = 0;

};



#endif // PERSONA_H_INCLUDED
