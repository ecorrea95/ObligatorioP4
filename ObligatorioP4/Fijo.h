#ifndef FIJO_H_INCLUDED
#define FIJO_H_INCLUDED
#include "Vendedor.h"

class Fijo : public Vendedor{
    private:
        int plus;
    public:
        Fijo();
        int getPlus();
        void setPlus(int);


};













#endif // FIJO_H_INCLUDED
