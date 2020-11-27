#include <iostream>
#include "DiccionarioVendedores.h"
#include "DiccionarioSupervisores.h"
#include "CapaLogica.h"
using namespace std;

int main()
{
    Fecha Colon(12,5,1494);
    Fecha Guerra(5,9,1939);
    Vendedor * Vend1 = new Zafral(25000, 15, 5088929, "Joaco", Colon, 3000);
    Vendedor * Vend2 = new Zafral(178000, 3, 5458288, "Soledad", Guerra, 4000);
    Vendedor * Vend3 = new Fijo(60000, 34, 5424324, "Xime", 3000);
    Vendedor * Vend4 = new Fijo(15000, 3, 1234345, "Emiliano", 1400);
    Vendedores diccio;
    diccio.insert(Vend1);
    diccio.insert(Vend2);
    diccio.insert(Vend3);
    diccio.insert(Vend4);
    if(diccio.estaVacio())
        cout << "Esta vacio" <<endl;
    else
        cout << "No esta vacio" << endl;
    if(diccio.member(5088929))
        cout << "Existe el vendedor" <<endl;
    else
        cout << "No existe vendedor" << endl;
    Vendedor * v = diccio.find(5088929);
    cout << v-> getCantVentas() << endl;
    cout << v-> getCedula() << endl;
    cout << "El monto total de sueldos es: "<< diccio.calcularmontototaldesueldos() << endl;
    diccio.registrarcantventas(5088929, 24);
    cout << "Cantidad de ventas luego: " << v-> getCantVentas() << endl;
    cout << "Hay " << diccio.contarcuantoszafrales() << " Zafrales" << endl;
    Iterador iter;
    diccio.listar(iter);
    while(iter.HayMasPersonas())
    {
        Persona * per = iter.ProximaPersona();
        cout << "La cedula es: " << per->getCedula() << " y su nombre es: ";
        String ss = per->getNombre();
        ss.print();
        cout << endl << "Su tipo es : ";
        ss = per->tipoObjeto();
        ss.print();
        cout << endl;
    }
    Supervisores Super;
    Supervisor * Sup1 = new Supervisor(1342424, "Pedro", "Cordon", 3);
    Supervisor * Sup2 = new Supervisor(6646464, "Agus", "Centro", 5);
    Supervisor * Sup3 = new Supervisor(1010101, "Marcos", "Cerro", 1);
    Supervisor * Sup4 = new Supervisor(4949339, "Santiago", "Carrasco", 5);
    Super.Insert(Sup1);
    Super.Insert(Sup2);
    Super.Insert(Sup3);
    Super.Insert(Sup4);
    if(Super.Member(1010101))
        cout<< "----------------------------------" << endl <<"Existe Supervisor" << endl;
    else
        cout << "No existe" << endl;
    Supervisor * SupP = Super.Find(1010101);
    cout << "El nombre es: " ;
    String n = SupP->getNombre();
    n.print();
    cout << " su cedula es: " << SupP->getCedula() << endl;
    Iterador iter2;
    Super.listar(iter2);
    while(iter2.HayMasPersonas())
    {
        Persona * per = iter2.ProximaPersona();
        cout << "La cedula es: " << per->getCedula() << " y su nombre es: ";
        String ss = per->getNombre();
        ss.print();
        cout << endl << "Su tipo es : ";
        ss = per->tipoObjeto();
        ss.print();
        cout << endl;
    }




}
