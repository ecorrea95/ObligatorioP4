#ifndef DICCIONARIOSUPERVISORES_H_INCLUDED
#define DICCIONARIOSUPERVISORES_H_INCLUDED
#include "Supervisor.h"
#include "Iterador.h"

const int B = 60;
class Supervisores
{
    private:
        struct Nodo {   Supervisor * info;
                        Nodo * sig;
                    };
        Nodo * hash[B];
        void CrearLista(Nodo *&);
        int h (long int);
        bool buscarEnLista(Nodo *, long int);
        void InsFront (Nodo *&, Supervisor *);
        Supervisor* devolverEnLista(Nodo *, long int);
        void listarRecu(Nodo *, Iterador &);

    public:
        Supervisores();
        ~Supervisores();
        bool Member(long int);
        void Insert(Supervisor *);
        Supervisor* Find(long int);
        void listar(Iterador &);
};


#endif // DICCIONARIOSUPERVISORES_H_INCLUDED
