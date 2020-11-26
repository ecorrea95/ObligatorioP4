#include "Supervisor.h"

Supervisor::Supervisor(long int p, String ps, String b, int c) : Persona(p, ps)
{
    barrio = b;
    cantManzanas = c;
}
Supervisor :: ~Supervisor()
{

}
String Supervisor::getbarrio()
{
    return barrio;
}

int Supervisor::getcantManzanas()
{
    return cantManzanas;
}

void Supervisor::setbarrio(String b)
{
    barrio = b;
}

void Supervisor::setcantManzanas(int c)
{
    cantManzanas = c;
}
String Supervisor :: tipoObjeto ()
{
    String tipo = "Supervisor";
    return (String) tipo;
}
