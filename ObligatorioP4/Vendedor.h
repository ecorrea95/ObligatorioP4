#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#include "Persona.h"
#include "Supervisor.h"

class Vendedor : public Persona
{
private:
    int sueldoBase;
    int cantVentas;
    Supervisor * Super;
public:
    //Constructor por defecto
    Vendedor();
    //Constructor com�n
    Vendedor(int, int);   ///Es necesario si es abstracta?
    //Constructor de copia ///Falta pasarle parametros de Persona

    int getSueldoBase();
    //Selectora de cantVentas
    int getCantVentas();
    //Modificador de sueldoBase
    void setSueldoBase(int);       ///Deber�a llevar virtual, deber�a existir?
    //Modificador de cantVentas
    void setCantVentas(int);

    virtual String tipoObjeto () = 0; ///Es abstracta?

    ~Vendedor(); ///deber�a llevar el = 0, si es que existe?

};

#endif // VENDEDOR_H_INCLUDED
