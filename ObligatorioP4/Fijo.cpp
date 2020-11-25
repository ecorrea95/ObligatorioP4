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
String Fijo :: tipoObjeto()
{
    String tipo = "Fijo";
    return (String) tipo;
}
