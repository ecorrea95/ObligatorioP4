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

Iterador listarSupervisores(Iterador &iter)
{
    Supervisores.listar(iter);
}

Iterador listarVendedores(Iterador &iter)
{
    Vendedores.listar(iter);
}



