#include "Supervisor.h"

Supervisor::Supervisor()
{
    barrio = " ";
    cantManzanas = 0;
}

Supervisor::Supervisor(string b, int c)
{
    barrio = b;
    cantManzanas = c;
}

Supervisor::Supervisor(const Supervisor &s)
{
    barrio = s.barrio;
    cantManzanas = s.cantManzanas;
}

string Supervisor::getbarrio()
{
    return barrio;
}

int Supervisor::getcantManzanas()
{
    return cantManzanas;
}

void Supervisor::setbarrio(string b)
{
    barrio = b;
}

void Supervisor::setcantManzanas(int c)
{
    cantManzanas = c;
}
