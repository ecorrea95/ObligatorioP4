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
        virtual ~Persona();
        Persona operator= (const Persona &); ///no compila
        int getCedula();
        String getNombre();
        virtual String tipoObjeto() = 0;

};



#endif // PERSONA_H_INCLUDED