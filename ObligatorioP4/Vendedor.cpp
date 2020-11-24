#include "Vendedor.h"

Vendedor::Vendedor()
{
    sueldoBase = 0;
    cantVentas = 0;
}

Vendedor::Vendedor(int s, int c) ///Habría que crear punt a obj Supervisor o se hace en las clases derivadas?
{
    sueldoBase = s;
    cantVentas = c;
}

Vendedor::Vendedor(const Vendedor &v)
{
    sueldoBase = v.sueldoBase;
    cantVentas = v.cantVentas;
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
