#ifndef SUPERVISOR_H_INCLUDED
#define SUPERVISOR_H_INCLUDED
#include "Persona.h"

class Supervisor : public Persona
{
private:
    String barrio;
    int cantManzanas;
public:
    //Constructor por defecto
    Supervisor();
    //Constructor común
    Supervisor(String, int); ///Falta pasarle parametros de Persona
    //Constructor de copia
    Supervisor(const Supervisor &);
    //Selectora de barrio
    String getbarrio();
    //Selectora de cantManzanas
    int getcantManzanas();
    //Modificador de barrio
    void setbarrio(String);
    //Modificador de cantManzanas
    void setcantManzanas(int);

    String tipoObjeto ();

};

#endif // SUPERVISOR_H_INCLUDED
