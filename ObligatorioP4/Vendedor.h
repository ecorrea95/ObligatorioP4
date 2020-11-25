#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#include "Persona.h"
#include "Supervisor.h"

class Vendedor : public Persona
{
private:
    int sueldoBase;
    int cantVentas;
    Supervisor * Super; ///Ver como borrarlo
public:
    //Constructor por defecto
    Vendedor();
    //Constructor común
    Vendedor(long int, String, int, int);
    //Constructor de copia
    int getSueldoBase();
    //Selectora de cantVentas
    int getCantVentas();
    //Modificador de sueldoBase
    void setSueldoBase(int);
    //Modificador de cantVentas
    void setCantVentas(int);

    virtual String tipoObjeto () = 0;

    ~Vendedor();

};

#endif // VENDEDOR_H_INCLUDED
