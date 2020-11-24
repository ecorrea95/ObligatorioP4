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
    //Constructor común
    Vendedor(int, int);   ///Es necesario si es abstracta?
    //Constructor de copia ///Falta pasarle parametros de Persona

    int getSueldoBase();
    //Selectora de cantVentas
    int getCantVentas();
    //Modificador de sueldoBase
    void setSueldoBase(int);       ///Debería llevar virtual, debería existir?
    //Modificador de cantVentas
    void setCantVentas(int);

    virtual String tipoObjeto () = 0; ///Es abstracta?

    ~Vendedor(); ///debería llevar el = 0, si es que existe?

};

#endif // VENDEDOR_H_INCLUDED
