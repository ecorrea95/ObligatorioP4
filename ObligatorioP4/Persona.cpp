#include "Persona.h"

Persona :: Persona() : nombre(" ")
{
    cedula = 0;
}
Persona :: Persona(long int ced, String nom): nombre(nom)
{
    cedula = ced;
}

Persona :: ~Persona()
{

}
int Persona :: getCedula()
{
    return cedula;
}
String Persona :: getNombre()
{
    return nombre;
}
