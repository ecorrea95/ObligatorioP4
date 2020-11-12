#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED

class Vendedor
{
private:
    int sueldoBase;
    int cantVentas;
public:
    //Constructor por defecto
    Vendedor();
    //Constructor común
    Vendedor(int, int);
    //Constructor de copia
    Vendedor(const Vendedor &);
    //Selectora de sueldoBase
    int getsueldoBase();
    //Selectora de cantVentas
    int getcantVentas();
    //Modificador de sueldoBase
    void setsueldoBase();
    //Modificador de cantVentas
    void setcantVentas();
};

#endif // VENDEDOR_H_INCLUDED
