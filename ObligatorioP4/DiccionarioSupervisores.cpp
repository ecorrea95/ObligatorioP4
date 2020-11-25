/*#include "DiccionarioSupervisores.h"

//Constructor por defecto
Supervisores :: Supervisores()
{
    HashSupervisor = NULL;
}

//Destructor
Supervisores :: ~Supervisores()
{

}

//Inserta supervisor en el hash
//Precondición: el supervisor no pertenece
void Supervisores :: insert(Supervisor * sup)
{
    insertEnHash(Hash, sup);
}

void Supervisores :: insertEnHash(NodoL * &h, Supervisor * sup)
{
    int cedula = Supervisor.getCedula();
    int cubeta = h(cedula);
    InsFront(sup, h[cubeta]);
}

//Indica si el supervisor es miembro
bool Supervisores :: member(long int ced)
{
    return MemberHash(Hash, ced)
}

bool Supervisores :: MemberHash(Hash h, int ced)
{
    boolean existe = false;
    while (!existe && h != NULL)
    {
        if (ced == Supervisor.getCedula(h->Info))
            existe = true;
        else
            h = h->sig;
    }
    return existe;
}

bool Vendedores :: MemberRecu (NodoA * a, long int ced)
{
    if(a ->info->getCedula() == ced)
    {
        return true;
    }
    else if (ced < a->info->getCedula())
        return MemberRecu(a->hizq, ced);
    else if (ced > a->info->getCedula())
        return MemberRecu(a->hder, ced);
    else
        return false;

}
*/
