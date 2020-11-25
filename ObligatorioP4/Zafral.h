#ifndef ZAFRAL_H_INCLUDED
#define ZAFRAL_H_INCLUDED
#include "Vendedor.h"
#include "Fecha.h"

class Zafral : public Vendedor{
private:
    Fecha Vencimiento;
    int comisionVenta;
public:
    Zafral(int, int, long int, String , /*Supervisor*/ Fecha, int);
    Fecha getFechaVencimiento();
    int getComision();
    void setFechaVencimiento(Fecha);
    void setComision(int);
    String tipoObjeto();
};


#endif // ZAFRAL_H_INCLUDED
