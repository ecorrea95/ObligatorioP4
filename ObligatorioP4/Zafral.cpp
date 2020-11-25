#include "Zafral.h"

Zafral :: Zafral(int sueldoB, int cantV, long int ced, String nom, /*Supervisor*/ Fecha f, int comision) : Vendedor(ced,nom, sueldoB, cantV), Vencimiento(f)
{
    comisionVenta = comision;
}
Fecha Zafral :: getFechaVencimiento()
{
    return Vencimiento;
}
int Zafral :: getComision()
{
    return comisionVenta;
}
void Zafral :: setFechaVencimiento(Fecha f)
{
    Vencimiento = f;
}
void Zafral :: setComision(int com)
{
    comisionVenta = com;
}
String Zafral :: tipoObjeto()
{
    String tipo = "Zafral";
    return (String) tipo;
}

