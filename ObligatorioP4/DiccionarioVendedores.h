#ifndef DICCIONARIOVENDEDORES_H_INCLUDED
#define DICCIONARIOVENDEDORES_H_INCLUDED
#include "Vendedor.h"
#include "Iterador.h"
#include "Zafral.h"
#include "Fijo.h"

class Vendedores
{
    private:
    struct NodoA {
                    Vendedor * info;
                    NodoA * hizq;
                    NodoA * hder;
                 };
    NodoA * ABBVendedores;

    void insertEnArbol (NodoA *&, Vendedor *);
    bool MemberRecu(NodoA *, long int);
    Vendedor* FindVendedorRecu(NodoA *, long int);
    void registrarcantVentasRecu(NodoA *&, long int, int);
    int calcularmontototaldesueldosRecu(NodoA *);
    int contarZafralesRecu(NodoA *, Fecha);
    void ListarRecu(NodoA *, Iterador &);
    void destruirArbol(NodoA *&);

    public:
        Vendedores ();
        // constructor por defecto
        ~Vendedores ();
        // destructor
        bool member (long int);
        // indica si el vendedor con el código recibido es miembro
        void insert (Vendedor *);
         // inserta el nuevo articulo al diccionario
         // precondición: el articulo no es miembro
        Vendedor* find (long int);
        // retorna al vendedor cuyo número es num
        // precondición: la estadía es miembro
        bool estaVacio ();
        // indica si el diccionario está vacío
        void listar(Iterador &);
        void registrarcantventas (long int, int);
        int calcularmontototaldesueldos();
        int contarcuantoszafrales(Fecha);





};










#endif // DICCIONARIOVENDEDORES_H_INCLUDED
