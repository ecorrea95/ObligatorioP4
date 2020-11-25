#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED
#include "Persona.h"

class Iterador
{
    private:
        struct Nodo {   Persona * info;
                        Nodo * sig;
                    };
        Nodo * prim;
        Nodo * ult;
        Nodo * actual;
    public:
        Iterador();
        //Constructor por defecto;
        void Insertar (Persona *);
        //Inserta una persona en el iterador;
        bool HayMasPersonas ();
        //Determina si quedan dueños por visitar en el iterador;
        Persona * ProximaPersona();
        //Retorna la proxima persona por visitar en el iterador;
        ~Iterador();
        //Destructor;
};



#endif // ITERADOR_H_INCLUDED
