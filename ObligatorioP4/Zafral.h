#ifndef ZAFRAL_H_INCLUDED
#define ZAFRAL_H_INCLUDED
#include "Vendedor.h"


class Zafral : public Vendedor{
private:
    Fecha Vencimiento;
    int comisionVenta;
public:
    Zafral();
    Zafral(int, int, long int, String , /*Supervisor*/ Fecha, int);
    Fecha getFechaVencimiento();
    int getComision();
    void setFechaVencimiento(Fecha);
    void setComision(int);
    int calcularSueldo();
    String tipoObjeto();
};


#endif // ZAFRAL_H_INCLUDED
