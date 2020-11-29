#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#include "Persona.h"
#include "Supervisor.h"
#include "Fecha.h"

class Vendedor : public Persona
{
private:
    int sueldoBase;
    int cantVentas;
    Supervisor * Super;
public:
    //Constructor común
    Vendedor(long int, String, int, int);
    void setSupervisor (Supervisor * su);
    int getSueldoBase();
    //Selectora de cantVentas
    int getCantVentas();
    //Modificador de sueldoBase
    virtual int calcularSueldo() = 0;

    void setSueldoBase(int);
    //Modificador de cantVentas
    void setCantVentas(int);

    virtual String tipoObjeto () = 0;
    ///Vendedor es Zafral

    ~Vendedor();

};

#endif // VENDEDOR_H_INCLUDED
