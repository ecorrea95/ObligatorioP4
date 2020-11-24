#include "Zafral.h"

Zafral :: Zafral() : Vendedor(), Vencimiento() ///Hace falta crear objeto Vendedor y a su vez persona???
{
    comisionVenta = 0;
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


