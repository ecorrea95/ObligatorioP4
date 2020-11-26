#include "Fijo.h"

Fijo :: Fijo(int sueldoB, int cantV, long int ced, String nom /*Supervisor*/, int p) : Vendedor(ced, nom, sueldoB, cantV)
{
    plus = p;
}
int Fijo :: getPlus()
{
    return plus;
}
void Fijo :: setPlus(int p)
{
    plus = p;
}
int Fijo :: calcularSueldo()
{
    int sueldo = Vendedor :: getSueldoBase();
    if(getCantVentas() < 10)
    {
        return sueldo;
    }
    else if (getCantVentas() < 20)
    {
        return sueldo + plus;
    }
    else
    {
        return sueldo + plus * 2;
    }
}
String Fijo :: tipoObjeto()
{
    String tipo = "Fijo";
    return (String) tipo;
}
