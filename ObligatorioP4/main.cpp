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
    while(input != 0)
    {
        if(input == 1)
        {
            bool salir = false;
            do
            {
                cout << "Ingrese cedula del supervisor: " << endl;
                cin >> ceds;
                cout << "Ingrese nombre del supervisor: " << endl;
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
                    cout << "Ingrese la comisi�n por venta: ";
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
                cout << "Error: no hay mas personas." << endl;
            while(iter.HayMasPersonas())
            {
                per = iter.ProximaPersona();
                cout << "Cedula: "<<per->getCedula() << " - ";
                per->getNombre().print();
                cout << " - Barrio: ";
                ((Supervisor*) per)->getbarrio().print();
                cout << " - Manzanas: " << ((Supervisor*) per) -> getcantManzanas() << endl;
            }
            iter.~Iterador();
            system("cls");

        }
        else if(input == 4)
        {
            cap.listarSupervisores(iter);
            if(!iter.HayMasPersonas())
                cout << "Error: no hay mas personas." << endl;
            while(iter.HayMasPersonas())
            {
                per = iter.ProximaPersona();
                cout << "Cedula: " << per->getCedula() << " - ";
                per->getNombre().print();
                cout << "- Tipo Vendedor: ";
                ((Vendedor*) per)->tipoObjeto().print();
            }
            iter.~Iterador();
            system("cls");
        }
        else if(option < 50)
        {
            cout << "La opcion ingresada no es correcta. " << endl;
            cout << "Ingrese nuevamente: " << endl;
            cout << "Ingrese una opcion: ";
        }
        else
        {

        }
        cout << "Ingrese una opcion: ";
        cin >> input;
        system("cls");
    }


}
