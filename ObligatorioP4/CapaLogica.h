#ifndef CAPALOGICA_H_INCLUDED
#define CAPALOGICA_H_INCLUDED
#include "DiccionarioSupervisores.h"
#include "DiccionarioVendedores.h"
#include "TipoError.h"

class CapaLogica
{
private:
    Supervisores supervisores;
    Vendedores vendedores;

public:
    //Constructor por defecto
    CapaLogica();
    //Registra un supervisor
    //Devuelve un error si el supervisor ya existe
    void registrarSupervisor(Supervisor *, TipoError &);
    //Registra un vendedor en el sistema
    //Devuelve un error si el supervisor ya existe
    void registrarVendedor(Vendedor *, TipoError &);
    //Devuelve un iterador con todos los supervisores
    Iterador listarSupervisores(Iterador &iter);
    //Devuelve un iterador con todos los vendedores
    Iterador listarVendedores(Iterador &iter);
    //Lista un vendedor dado
    void listarVendedor(long int,TipoError &);
    //Registrar la cantidad de ventas realizadas por un vendedor en una semana
    void ventasSemanales(int, int, TipoError &);
    //Calcular el sueldo dependiendo del tipo de vendedor
    int sueldoTotal(Vendedor *);
    //Devuelve cuantos zafrales se encuentran registrados antes de X fecha
    int cantZafralesHasta(Fecha);
};


#endif // CAPALOGICA_H_INCLUDED
