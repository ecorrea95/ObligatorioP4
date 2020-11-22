#include "Vendedor.h"

Vendedor::Vendedor()
{
    sueldoBase = 0;
    cantVentas = 0;
}

Vendedor::Vendedor(int s, int c)
{
    sueldoBase = s;
    cantVentas = c;
}

Vendedor::Vendedor(const Vendedor &v)
{
    sueldoBase = v.sueldoBase;
    cantVentas = v.cantVentas;
}

int Vendedor::getsueldoBase()
{
    return sueldoBase;
}

int Vendedor::getcantVentas()
{
    return cantVentas;
}

int Vendedor::setsueldoBase(int s)
{
    sueldoBase = s;
}

int Vendedor::setcantVentas(int c)
{
    cantVentas = c;
}
