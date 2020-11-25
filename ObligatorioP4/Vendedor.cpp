#include "Vendedor.h"

Vendedor::Vendedor()
{
    sueldoBase = 0;
    cantVentas = 0;
}

Vendedor::Vendedor(long int p, String ps, int s, int c) : Persona(p, ps)
{
    ///Habría que crear punt a obj Supervisor o se hace en las clases derivadas?
    sueldoBase = s;
    cantVentas = c;
}

Vendedor :: ~Vendedor()
{
    Super = NULL; ///No se si usamos así pero para poder probar
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
