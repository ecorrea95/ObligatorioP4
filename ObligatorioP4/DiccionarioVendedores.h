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
    int contarZafralesRecu(NodoA *, int cuenta);
    void ListarRecu(NodoA *, Iterador &);

    public:
        Vendedores ();
        // constructor por defecto
        ~Vendedores ();
        // destructor
        bool member (long int);
        // indica si el vendedor con el c�digo recibido es miembro
        void insert (Vendedor *);
         // inserta el nuevo articulo al diccionario
         // precondici�n: el articulo no es miembro
        Vendedor* find (long int);
        // retorna al vendedor cuyo n�mero es num
        // precondici�n: la estad�a es miembro
        bool estaVacio ();
        // indica si el diccionario est� vac�o
        void listar(Iterador &);
        void registrarcantventas (long int, int);
        int calcularmontototaldesueldos();
        int contarcuantoszafrales();





};










#endif // DICCIONARIOVENDEDORES_H_INCLUDED
