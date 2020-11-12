#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
private:
    int dd, mm, aa;
    // m�todo auxiliar, incrementa 1 d�a la fecha
    void incrementar ();
public:
    //Constructor por defecto
    Fecha ();
    //Constructor com�n
    Fecha (int, int, int);
    //Constructor de copia
    Fecha (const Fecha &);
    //Selectoras del tipo fecha
    int getDia ();
    int getMes ();
    int getAnio ();
    //Compara por menor 2 fechas
    boolean operator< (Fecha);
    //Compara por igualdad 2 fechas
    boolean operator== (Fecha);
    //Devuelve la fecha incrementada en n dias
    Fecha operator+ (int);
    //Operador prefijo de incremento
    Fecha operator++ ();
    //Operador postfijo de incremento
    Fecha operator++ (int);
    //Devuelve la diferencia en d�as entre 2 fechas
    int operator- (Fecha);
    //Validacion de la fecha
    boolean esValida ();
};

#endif // FECHA_H_INCLUDED
