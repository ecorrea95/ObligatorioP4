#include "Vendedor.h"

Vendedor::Vendedor(long int p, String ps, int s, int c) : Persona(p, ps)
{
    Super = NULL;
    sueldoBase = s;
    cantVentas = c;
}

Vendedor :: ~Vendedor()
{
    ///No se si usamos así pero para poder probar
}
Supervisor* Vendedor::  getSupervisor ()
{
    return Super;
}
int Vendedor::getSueldoBase()
{
    return sueldoBase;
}

int Vendedor::getCantVentas()
{
    return cantVentas;
}

void Vendedor :: setSueldoBase(int s)
{
    sueldoBase = s;
}

void Vendedor :: setCantVentas(int c)
{
    cantVentas = c;
}
void Vendedor :: setSupervisor (Supervisor * su)
{
    Super = su;
}
