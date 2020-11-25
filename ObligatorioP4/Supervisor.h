#ifndef SUPERVISOR_H_INCLUDED
#define SUPERVISOR_H_INCLUDED
#include "Persona.h"

class Supervisor : public Persona
{
private:
    String barrio;
    int cantManzanas;
public:
    //Constructor común
    Supervisor(long int, String, String, int);
    //Constructor de copia
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
