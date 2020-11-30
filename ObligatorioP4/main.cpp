#include <iostream>
#include "DiccionarioVendedores.h"
#include "DiccionarioSupervisores.h"
#include "CapaLogica.h"
using namespace std;

int main()
{
    Iterador iter;
    TipoError tipo;
    Persona * per;
    Vendedor * vend;
    Supervisor * Sup;
    Fecha fec;
    CapaLogica cap;
    long int ceds = 0;
    long int cedv = 0;
    String nom;
    String barrio;
    int num = 0;
    int num1 = 0;
    int num2 = 0;
    int dia, mes, anio;
    int input = 100;
    char option;
    int i = 1;
    while(input != 0)
    {
        cout << "Ingrese una opcion: ";
        cin >> input;
        system("cls");
        if(input == 1)
        {
            bool salir = false;
            do
            {
                cout << "Ingrese cedula del supervisor: " << endl;
                cin >> ceds;
                cout << "Ingrese nombre del supervisor: " << endl;
                nom.scan();
                nom.scan();
                cout << "Ingrese barrio: " << endl;
                barrio.scan();
                cout << "Ingrese cantidad de manzanas: " << endl;
                cin >> num;
                Sup = new Supervisor(ceds,nom,barrio,num);
                cap.registrarSupervisor(Sup, tipo);
                if(tipo != SIN_ERROR)
                {
                    cout << "Error: " << tipo /*No anda!!! Meter un switch en tipoerror.h*/ << " Desea ingresar nuevamente o salir?" << endl;
                    cout << "Ingrese S para salir N para ingresar nuevamente: " << endl;
                    cin >> option;
                    if(option == 'S' || option == 's')
                        salir = true;
                }
            }while(tipo != SIN_ERROR && !salir);
        }
        else if(input == 2)
        {
            bool salir = false;
            do
            {
                cout << "Ingrese cedula del supervisor: " << endl;
                cin >> ceds;
                cout << "Ingrese nombre del vendedor: " << endl;
                nom.scan();
                nom.scan();
                cout << "Ingrese cedula del vendedor: " << endl;
                cin >> cedv;
                cout << "Ingrese sueldo base: " << endl;
                cin >> num;
                cout << "Ingrese cantidad de ventas: " << endl;
                cin >> num1;
                cout << "Ingrese si vendedor es zafral: Z o fijo: F " << endl;
                cin >> option;
                if(option == 'Z' || option == 'z')
                {
                    cout << "Ingrese fecha de vencimiento: dd/mm/aaaa" << endl;
                    cin >> dia; cin >> mes; cin >> anio;
                    Fecha fec1 (dia, mes, anio);
                    cout << "Ingrese la comisión por venta: ";
                    cin >> num2;
                    vend = new Zafral(num, num1, cedv, nom, fec1, num2);
                    cap.registrarVendedor(vend, ceds, tipo);
                    cout << endl;
                }
                else if(option == 'F' || option == 'f')
                {
                    cout << "Ingrese plus: ";
                    cin >> num2;
                    vend = new Fijo(num, num1, cedv, nom, num2);
                    cap.registrarVendedor(vend, ceds, tipo);
                    cout << endl;
                }
                else
                    tipo = NO_INGRESA_TIPO;
                if(tipo != SIN_ERROR)
                {
                    cout << "Error: " << tipo /*No anda!!! Meter un switch en tipoerror.h*/ << " Desea ingresar nuevamente o salir?" << endl;
                    cout << "Ingrese S para salir N para ingresar nuevamente: " << endl;
                    cin >> option;
                    if(option == 'S' || option == 's')
                    {
                        salir = true;
                        system("cls");
                    }
                }
            }while(tipo != SIN_ERROR && !salir);
        }
        else if(input == 3)
        {
            cap.listarSupervisores(iter);
            if(!iter.HayMasPersonas())
                cout << "Error: no hay supervisores para listar." << endl;
            while(iter.HayMasPersonas())
            {
                per = iter.ProximaPersona();
                cout << "Cedula: "<<per->getCedula() << " - Nombre: ";
                per->getNombre().print();
                cout << " - Barrio: ";
                ((Supervisor*) per)->getbarrio().print();
                cout << " - Manzanas: " << ((Supervisor*) per) -> getcantManzanas() << endl;
            }
            iter.~Iterador();
        }
        else if(input == 4)
        {
            cap.listarVendedores(iter);
            if(!iter.HayMasPersonas())
                cout << "Error: no hay vendedores para listar." << endl;
            while(iter.HayMasPersonas())
            {
                per = iter.ProximaPersona();
                cout << "Cedula: " << per->getCedula() << " - Nombre: ";
                per->getNombre().print();
                cout << "- Tipo Vendedor: ";
                ((Vendedor*) per)->tipoObjeto().print();
            }
            iter.~Iterador();
        }
        else if(input == 5)
        {
            cout << "Ingrese cedula del vendedor: ";
            cin >> cedv;
            cap.listarVendedor(cedv, vend, tipo);
            if(tipo == SIN_ERROR)
            {
                cout << "Cedula: "<<vend-> getCedula() << " - Nombre: ";
                vend->getNombre().print();
                cout << " - Sueldo Base: " << vend->getSueldoBase();
                cout << " - Cantidad de ventas: " << vend->getCantVentas();
                cout << " - Tipo vendedor: ";
                vend ->tipoObjeto().print();
                cout << endl << "El supervisor asignado al vendedor es: " << endl;
                Sup = vend->getSupervisor();
                cout << "Nombre: ";
                Sup->getNombre().print();
                cout << " - Cedula: " << Sup->getCedula() << endl;
            }
        }
        else if(input == 6)
        {
            cout << "Ingrese cedula del vendedor: ";
            cin >> cedv;
            cout << "Ingrese la cantidad de ventas: ";
            cin >> num;
            cap.registrarVentas(cedv, num, tipo);
            if(tipo == VENDEDOR_NO_EXISTE)
                cout << "Error: vendedor no existe" << endl;
        }
        else if(input == 7)
        {
            cout << "El monto total a pagar es: " << cap.sueldoTotal() << endl;
        }
        else if(input == 8)
        {
            cout << "Ingrese fecha: dd/mm/aaaa" << endl;
                    cin >> dia; cin >> mes; cin >> anio;
                    Fecha fec1 (dia, mes, anio);
            cout << "La cantidad de vendedores zafrales que estaran contratados luego de " << dia << "/" << mes << "/" << anio << " es: " << cap.cantZafralesHasta(fec1) << endl;

        }
        else
        {
            cout << "La opcion ingresada no es correcta. " << endl;
            cout << "Ingrese nuevamente: " << endl;
        }
    }


}
