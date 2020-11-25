#include "DiccionarioSupervisores.h"
int Supervisores :: h (long int clave)
{
    return(clave % B);
}
void Supervisores :: listarRecu(Nodo * L, Iterador &iter)
{
    Nodo * aux = L;
    while(aux != NULL)
    {
        iter.Insertar(aux -> info);
        aux = aux -> sig;
    }
}
void Supervisores :: InsFront (Nodo * &L, Supervisor * Super)
{
     Nodo * aux = new Nodo;
     aux -> info = Super;
     aux -> sig = L;
     L = aux;
}
Supervisor* Supervisores :: devolverEnLista(Nodo * L, long int ced)
{
    Nodo* aux = L;
    long int cedula = aux ->info->getCedula();
    while(aux != NULL && cedula != ced)
    {
        cedula = aux ->info->getCedula();
        aux = aux -> sig;
    }
    return aux -> info;
}

bool Supervisores :: buscarEnLista(Nodo * L, long int ced)
{
    Nodo * aux = L;
    bool existe = false;
    long int cedula;
    while(aux != NULL && !existe)
    {
        cedula = aux ->info->getCedula();
        if(cedula == ced)
            existe = true;
        else
            aux = aux -> sig;
    }
    return existe;
}
void Supervisores :: CrearLista(Nodo * &L)
{
    L = NULL;
}
Supervisores :: Supervisores()
{
    int i;
    for(i=0;i<B;i++)
        CrearLista(hash[i]);
}
bool Supervisores :: Member(long int ced)
{
    int cubeta = h(ced);
    Nodo* L = hash[cubeta];
    return buscarEnLista(L, ced);
}
void Supervisores :: Insert(Supervisor * Super)
{
    long int ced = Super->getCedula();
    int cubeta = h(ced);
    InsFront(hash[cubeta], Super);
}
Supervisor * Supervisores :: Find(long int ced)
{
    int cubeta = h(ced);
    Nodo* L = hash[cubeta];
    return devolverEnLista(L, ced);
}
void Supervisores :: listar(Iterador &iter)
{
    for(int i = 0; i < B; i++)
        listarRecu(hash[i], iter);
}
