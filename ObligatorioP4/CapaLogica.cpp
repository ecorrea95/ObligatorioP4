#include "CapaLogica.h"

CapaLogica :: CapaLogica(): Supervisores(), Vendedores()
{

}

void CapaLogica :: registrarSupervisor(Supervisor * sup, TipoError &error)
{
    error = SIN_ERROR;
    long int ced = sup->getCedula();
    if(supervisores.Member(ced))
        error = SUPERVISOR_YA_EXISTE;
    else
        supervisores.Insert(sup);
}

void CapaLogica :: registrarVendedor(Vendedor * vend, long int ced, TipoError &error)
{
    error = SIN_ERROR;
    long int c = vend->getCedula();
    if(vendedores.member(c))
        error = VENDEDOR_YA_EXISTE;
    else
    {
        if((supervisores.Member(ced)) == false)
            error = SUPERVISOR_NO_EXISTE;
        else
        {
            Supervisor * su = supervisores.Find(ced);
            vend -> setSupervisor(su);
            vendedores.insert(vend);
        }
    }
}

void CapaLogica :: listarSupervisores (Iterador &iter)
{
    supervisores.Listar(iter);
}

void CapaLogica :: listarVendedores(Iterador &iter)
{
    vendedores.listar(iter);
}

Vendedor* CapaLogica :: listarVendedor(long int ced, Vendedor * &vend, TipoError &error)
{
    error = SIN_ERROR;
    if(vendedores.member(ced))
    {
        vend = vendedores.find(ced);
    }
    else
    {
        vend = NULL;
        error = VENDEDOR_NO_EXISTE;
    }
}

void CapaLogica :: ventasSemanales(int ventas, long int ced, TipoError &error)
{
    error = SIN_ERROR;
    if(!vendedores.member(ced))
        error = VENDEDOR_NO_EXISTE;
    else
    {
        vendedores.find(ced)->setCantVentas(ventas);
    }
}

int CapaLogica :: sueldoTotal()
{
    return vendedores.calcularmontototaldesueldos();
}

int CapaLogica :: cantZafralesHasta(Fecha f)
{
    return vendedores.contarcuantoszafrales(f);
}
void CapaLogica :: registrarVentas(long int ced, int num, TipoError &tipo)
{
    tipo = SIN_ERROR;
    if(vendedores.member(ced))
        vendedores.registrarcantventas(ced, num);
    else
        tipo = VENDEDOR_NO_EXISTE;
}



