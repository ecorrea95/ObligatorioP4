#ifndef DICCIONARIOSUPERVISORES_H_INCLUDED
#define DICCIONARIOSUPERVISORES_H_INCLUDED
#include "Supervisor.h"
#include "Iterador.h"

class Supervisores
{
private:
    const int MAX = 60;
    typedef struct nodoL    {
                            Supervisor info;
                            nodoL * sig;
                            } Nodo;
    typedef Nodo * HashSupervisor;
    typedef HashSupervisor Hash[MAX];

public:
    //Constructor por defecto
    Supervisores();
    //Destructor
    ~Supervisores();
    //Indica si el supervisor es miembro
    bool member(long int);
    //Inserta supervisor en el hash
    //Precondición: el supervisor no pertenece
    void insert(Supervisor *);
    //Retorna vendedor dado
    Supervisor Find(long int);
    //Indica si el hash está vacio
    bool estaVacio();
    //Listar
    void listar(Nodo *, Iterador &);

};
#endif // DICCIONARIOSUPERVISORES_H_INCLUDED
