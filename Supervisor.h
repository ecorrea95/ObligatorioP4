#ifndef SUPERVISOR_H_INCLUDED
#define SUPERVISOR_H_INCLUDED

class Supervisor : public Persona
{
private:
    String barrio;
    int cantManzanas;
public:
    //Constructor por defecto
    Supervisor();
    //Constructor común
    Supervisor(string b, int c);
    //Constructor de copia
    Supervisor(const Supervisor &);
    //Selectora de barrio
    string getbarrio();
    //Selectora de cantManzanas
    int getcantManzanas();
    //Modificador de barrio
    void setbarrio(string b);
    //Modificador de cantManzanas
    void setcantManzanas(int c);

    String tipoObjeto ();

};

#endif // SUPERVISOR_H_INCLUDED
