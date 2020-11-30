#ifndef CAPALOGICA_H_INCLUDED
#define CAPALOGICA_H_INCLUDED
#include "DiccionarioSupervisores.h"
#include "DiccionarioVendedores.h"
#include "TipoError.h"
class CapaLogica : public Vendedores, public Supervisores //Para mi no hereda nada
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
    void registrarVendedor(Vendedor *, long int, TipoError &);
    //Devuelve un iterador con todos los supervisores
    void listarSupervisores(Iterador &iter);
    //Devuelve un iterador con todos los vendedores
    void listarVendedores(Iterador &iter);
    //Lista un vendedor dado
    Vendedor* listarVendedor(long int, Vendedor *&, TipoError &);
    //Registrar la cantidad de ventas realizadas por un vendedor en una semana
    void ventasSemanales(int, long int, TipoError &);
    //Calcular el sueldo de todos los vendedores registrados
    int sueldoTotal();
    //Devuelve cuantos zafrales se encuentran registrados antes de X fecha
    int cantZafralesHasta(Fecha);

    void registrarVentas(long int, int, TipoError &);

};


#endif // CAPALOGICA_H_INCLUDED
