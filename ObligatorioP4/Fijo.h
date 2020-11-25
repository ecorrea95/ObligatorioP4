#ifndef FIJO_H_INCLUDED
#define FIJO_H_INCLUDED
#include "Vendedor.h"

class Fijo : public Vendedor{
    private:
        int plus;
    public:
        Fijo(int, int, long int, String nom /*Supervisor*/, int);
        int getPlus();
        void setPlus(int);
        String tipoObjeto();

};













#endif // FIJO_H_INCLUDED
