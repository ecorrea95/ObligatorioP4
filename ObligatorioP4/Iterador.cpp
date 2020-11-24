#include "Iterador.h"

Iterador :: Iterador()
{
    prim = NULL;
    ult = NULL;
    actual = NULL;
}
void Iterador :: Insertar (Persona * per)
{
    Nodo * nuevo = new Nodo;
    nuevo -> info = per;
    nuevo -> sig = NULL;
    if (prim == NULL)
    {
        prim = nuevo;
        ult = nuevo;
        actual = nuevo;
    }
    else
    {
        ult -> sig = nuevo;
        ult = ult -> sig;
    }
}
bool Iterador :: HayMasPersonas ()
{
    return (actual != NULL);
}
Persona* Iterador :: ProximaPersona()
{
    Persona * resu = actual -> info;
    actual = actual -> sig;
    return resu;
}
Iterador :: ~Iterador()
{
     Nodo * aux = prim;
     while (aux != NULL)
     {
         prim = prim -> sig;
         delete aux;
         aux = prim;
     }
}

















