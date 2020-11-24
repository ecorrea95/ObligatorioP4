#include "Fijo.h"

Fijo :: Fijo() : Vendedor()
{
    plus = 0;
}
int Fijo :: getPlus()
{
    return plus;
}
void Fijo :: setPlus(int p)
{
    plus = p;
}
