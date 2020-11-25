/*#ifndef DICCIONARIOSUPERVISORES_H_INCLUDED
#define DICCIONARIOSUPERVISORES_H_INCLUDED
#include "Supervisor.h"
#include "Iterador.h"

class Supervisores
{
private:
    const int M = 60;
    typedef struct nodoL    {
                            Supervisor info;
                            nodoL * sig;
                            } nodo;
    typedef nodo * Lista;
    typedef Lista Hash[M];

public:
    //Constructor por defecto
    Supervisores();
    //Destructor
    ~Supervisores();
    //Inserta supervisor en el hash
    //Precondición: el supervisor no pertenece
    void insert(Supervisor *);
    //Indica si el supervisor es miembro
    bool member(long int);
    //Retorna vendedor dado
    Supervisor Find(long int);
    //Indica si el hash está vacio
    bool estaVacio();
    //Listar
    void listar(nodo *, Iterador &);

};
#endif // DICCIONARIOSUPERVISORES_H_INCLUDED
*/
