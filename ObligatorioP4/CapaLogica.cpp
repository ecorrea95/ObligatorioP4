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

void CapaLogica :: registrarVendedor(Vendedor * vend, TipoError &error)
{
    error = SIN_ERROR;
    long int ced = vend->getCedula();
    if(vendedores.member(ced))
        error = VENDEDOR_YA_EXISTE;
    else
        vendedores.insert(vend);
}

Iterador CapaLogica :: listarSupervisores(Iterador &iter)
{
    Supervisores.listar(iter);
}

Iterador CapaLogica :: listarVendedores(Iterador &iter)
{
    Vendedores.listar(iter);
}

void CapaLogica :: listarVendedor(long int ced, TipoError &error)
{
    error = SIN_ERROR;
    ///IMPLEMENTAR UN LISTAR DE VENDEDOR?
}

void CapaLogica :: ventasSemanales(int ventas, long int ced, TipoError &error)
{
    error = SIN_ERROR;
    if(!vendedores.member(ced))
        error = VENDEDOR_NO_EXISTE;
    else
    {
        Vendedor vend = vendedores.find(ced);
        vend.setCantVentas(ventas);
    }
}

int CapaLogica :: sueldoTotal(Vendedor *vend)
{

}

int CapaLogica :: cantZafralesHasta(Fecha f)
{

}
