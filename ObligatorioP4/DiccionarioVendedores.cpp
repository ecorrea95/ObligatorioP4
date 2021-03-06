#include "DiccionarioVendedores.h"

void Vendedores :: destruirArbol(NodoA *&abb)
{
 if (abb != NULL)
 {
     destruirArbol (abb -> hizq);
     destruirArbol (abb -> hder);
     delete (abb -> info);
     delete (abb);
     abb = NULL;
 }
}
///Precondicion, existe ced
void Vendedores :: registrarcantVentasRecu(NodoA * &a, long int ced, int cantVent)
{
    if(a->info->getCedula() == ced)
        a->info->setCantVentas(cantVent);
    else if(ced < a->info->getCedula())
        registrarcantVentasRecu(a -> hizq, ced, cantVent);
    else
        registrarcantVentasRecu(a -> hder, ced, cantVent);
}
void Vendedores :: ListarRecu(NodoA * a, Iterador &iter)
{
    if(a != NULL)
    {
        ListarRecu(a -> hizq, iter);
        iter.Insertar(a -> info);
        ListarRecu(a -> hder, iter);
    }
}
int Vendedores :: contarZafralesRecu(NodoA * a, Fecha Fec)
{
    if(a != NULL)
    {
        if(a -> info -> tipoObjeto() == "Zafral")
        {
            if( Fec < ((((Zafral *)a)->getFechaVencimiento()))) ///no tenemos implementado >
                return 1 + contarZafralesRecu(a -> hizq, Fec) + contarZafralesRecu(a -> hder, Fec);
            else
                return 0 + contarZafralesRecu(a -> hizq, Fec) + contarZafralesRecu(a -> hder, Fec);
        }
        else
            return 0 + contarZafralesRecu(a -> hizq, Fec) + contarZafralesRecu(a -> hder, Fec);
    }
    else
    {
        return 0;
    }
}

int Vendedores :: calcularmontototaldesueldosRecu(NodoA * a)
{
    if(a != NULL)
        return (a -> info -> calcularSueldo() + calcularmontototaldesueldosRecu(a -> hizq) + calcularmontototaldesueldosRecu(a -> hder));
    else
        return 0;
}

bool Vendedores :: MemberRecu (NodoA * a, long int ced)
{
    if(a != NULL)
    {
        if(a ->info->getCedula() == ced)
        {
            return true;
        }
        else
        {
            if (ced < a->info->getCedula())
                return MemberRecu(a->hizq, ced);
            else
                return MemberRecu(a->hder, ced);
        }
    }
    else
        return false;

}
void Vendedores :: insertEnArbol (NodoA * &a, Vendedor * vend)
{
    if (a == NULL)
    {
        a = new NodoA;
        a -> info = vend;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else if (vend->getCedula() < a->info->getCedula())
        insertEnArbol(a->hizq,vend);
    else
        insertEnArbol(a->hder,vend);
}
Vendedor* Vendedores :: FindVendedorRecu(NodoA * a, long int ced)
{
    if(a ->info->getCedula() == ced)
    {
        return a->info;
    }
    else if (ced < a->info->getCedula())
        return FindVendedorRecu(a->hizq, ced);
    else
        return FindVendedorRecu(a->hder, ced);
}

void Vendedores :: insert (Vendedor * vend)
{
    insertEnArbol (ABBVendedores, vend);
}

Vendedores :: Vendedores ()
{

    ABBVendedores = NULL;
}

Vendedores :: ~Vendedores ()
{
    destruirArbol(ABBVendedores);
}

bool Vendedores :: member (long int ced)
{
    return MemberRecu(ABBVendedores, ced);
}

Vendedor* Vendedores :: find (long int ced)
{
    return FindVendedorRecu(ABBVendedores, ced);
}

bool Vendedores :: estaVacio ()
{
    return (ABBVendedores == NULL);
}
void Vendedores :: listar(Iterador &iter)
{
    NodoA * a = ABBVendedores;
    ListarRecu(a, iter);
}
void Vendedores :: registrarcantventas (long int ced, int cantVent)
{
    registrarcantVentasRecu(ABBVendedores, ced, cantVent);
}
int Vendedores :: calcularmontototaldesueldos()
{
    return calcularmontototaldesueldosRecu(ABBVendedores);
}
int Vendedores :: contarcuantoszafrales(Fecha fec)
{
    return contarZafralesRecu(ABBVendedores, fec);
}



