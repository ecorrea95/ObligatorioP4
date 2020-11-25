#include <iostream>
#include "DiccionarioVendedores.h"
using namespace std;

int main()
{
    Fecha Colon(12,5,1494);
    Fecha Guerra(5,9,1939);
    Vendedor * Vend1 = new Zafral(25000, 15, 5088929, "Joaco", Colon, 3000);
    Vendedor * Vend2 = new Zafral(17800, 3, 5458288, "Juan", Guerra, 4000);
    Vendedor * Vend3 = new Fijo(1500, 3, 1234345, "Chorizo", 1400);
    Vendedores diccioVendedores;
    diccioVendedores.insert(Vend1);
    diccioVendedores.insert(Vend2);
    diccioVendedores.insert(Vend3);
    if(diccioVendedores.estaVacio())
        cout << "true" <<endl;
    else
        cout << "false" << endl;
    if(diccioVendedores.member(5088929))
        cout << "true" <<endl;
    else
        cout << "false" << endl;
    Vendedor * v = diccioVendedores.find(5088929);
    cout << v-> getCantVentas() << endl;
    cout << v-> getCedula() << endl;
    cout << diccioVendedores.calcularmontototaldesueldos() << endl;
    diccioVendedores.registrarcantventas(5088929, 24);
    cout << "Cantidad de ventas luego: " << v-> getCantVentas() << endl;
    cout << "Hay " << diccioVendedores.contarcuantoszafrales() << " Zafrales" << endl;



}
