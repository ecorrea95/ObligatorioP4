#include "Persona.h"

Persona :: Persona() : nombre("Juan")
{
    cedula = 1112231;
}
Persona :: Persona(int ced, String nom): nombre(nom)
{
    cedula = ced;
}
Persona :: Persona(const Persona &otro) : nombre(otro.nombre)
{
    cedula = otro.cedula;
}
Persona :: ~Persona()
{

}
Persona Persona :: operator= (const Persona &otro)
{
    if(this != &otro)
    {
        cedula = otro.cedula;
        nombre = otro.nombre;
    }
    return(*this);
}
int Persona :: getCedula()
{
    return cedula;
}
String Persona :: getNombre()
{
    return nombre;
}
