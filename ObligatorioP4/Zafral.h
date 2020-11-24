#ifndef ZAFRAL_H_INCLUDED
#define ZAFRAL_H_INCLUDED
#include "Vendedor.h"
#include "Fecha.h"

class Zafral : public Vendedor{
private:
    Fecha Vencimiento;
    int comisionVenta;
public:
    Zafral(); ///hace falta constructor común
    Fecha getFechaVencimiento();
    int getComision();
    void setFechaVencimiento(Fecha);
    void setComision(int);

};


#endif // ZAFRAL_H_INCLUDED
