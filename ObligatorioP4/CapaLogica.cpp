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

Iterador CapaLogica :: listarSupervisores(Iterador &iter)
{
    supervisores.listar(iter);
}

Iterador CapaLogica :: listarVendedores(Iterador &iter)
{
    vendedores.listar(iter);
}

void CapaLogica :: listarVendedor(long int ced, TipoError &error)
{
    error = SIN_ERROR;
    ///Hay que crear un listado o devuelvo un vendedor y después en main mostramos atributos
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


