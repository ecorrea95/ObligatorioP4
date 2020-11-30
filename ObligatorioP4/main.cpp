#include <iostream>
#include "DiccionarioVendedores.h"
#include "DiccionarioSupervisores.h"
#include "CapaLogica.h"
using namespace std;

int main()
{
    bool salir = false;
    Iterador iter;
    TipoError tipo;
    Persona * per;
    Vendedor * vend;
    Supervisor * Sup;
    Fecha fec1;
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
        cout << "******Ingrese una opcion: ******" << endl;
        cout << "0 - Salir." << endl;
        cout << "1 - Registrar los datos de un nuevo supervisor. " << endl << "2 - Dar de alta al vendedor en el sistema." << endl;
        cout << "3 - Listado de supervisores registrados." << endl << "4 - Listado de vendedores registrados ordenados por cedula." << endl;
        cout << "5 - Dada la cedula de un vendedor, listar todos sus datos junto con los datos de su supervisor." << endl;
        cout << "6 - Registrar la cantidad de ventas que realizo el vendedor en la semana." << endl;
        cout << "7 - Calcular el monto total de sueldos a pagar a los vendedores en la semana. " << endl;
        cout << "8 - Dada una fecha, contar cuantos de los vendedores zafrales actualmente registrados estaran contratados hasta despues" << endl << "de esa fecha." << endl;
        cin >> input;
        system("cls");
        switch(input) {
            case 0:
            {
                cap.~CapaLogica();
                iter.~Iterador();
                break;
            }
            case 1:
            {
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
                    if(tipo == SUPERVISOR_YA_EXISTE)
                    {
                        cout << "Error: El supervisor ya existe en el sistema" << endl;
                        cout << "Desea ingresar nuevamente o salir?" << endl;
                        cout << "Ingrese S para salir o N para ingresar nuevamente: " << endl;
                        cin >> option;
                        if(option == 'S' || option == 's')
                            salir = true;
                    }
                }while(tipo != SIN_ERROR && !salir);
                break;
            }
            case 2:
            {
                do
                {
                    cout << "Ingrese cedula del supervisor: " << endl;
                    cin >> ceds;
                    cout << "Ingrese nombre del vendedor: " << endl;
                    nom.scan();///Si pongo una sola se la saltea
                    nom.scan();
                    cout << "Ingrese cedula del vendedor: " << endl;
                    cin >> cedv;
                    cout << "Ingrese sueldo base: " << endl;
                    cin >> num;
                    cout << "Ingrese cantidad de ventas: " << endl;
                    cin >> num1;
                    cout << "Ingrese si vendedor es zafral: Z o fijo: F " << endl;
                    cin >> option;
                    bool invalida = false;
                    if(option == 'Z' || option == 'z')
                    {
                        cout << "Ingrese fecha de vencimiento: dd/mm/aaaa" << endl;
                        cin >> dia; cin >> mes; cin >> anio;
                        Fecha fec (dia, mes, anio);
                        if(!fec.esValida())
                            invalida = true;
                        cout << "Ingrese la comision por venta: ";
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
                        if(invalida)
                            cout << "Error: la fecha ingresada no es valida, Desea ingresar nuevamente o salir? " << endl;
                        else
                        {
                            cout << "Error: ";
                            if(tipo == NO_INGRESA_TIPO)
                                cout << "No ingresa tipo";
                            else if(tipo == VENDEDOR_YA_EXISTE)
                                cout << "Vendedor ya existe";
                            else
                                cout << "Supervisor no existe";

                            cout << " Desea ingresar nuevamente o salir?" << endl;
                        }
                        cout << "Ingrese S para salir N para ingresar nuevamente: " << endl;
                        cin >> option;
                        if(option == 'S' || option == 's')
                        {
                            salir = true;
                            system("cls");
                        }
                    }
                }while(tipo != SIN_ERROR && !salir);
                break;
            }
            case 3:
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
                break;
            }
            case 4:
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
                    cout << endl;
                }
                iter.~Iterador();
                break;
            }
            case 5:
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
                break;
            }
            case 6:
            {
                cout << "Ingrese cedula del vendedor: ";
                cin >> cedv;
                cout << "Ingrese la cantidad de ventas: ";
                cin >> num;
                cap.registrarVentas(cedv, num, tipo);
                if(tipo == VENDEDOR_NO_EXISTE)
                    cout << "Error: vendedor no existe" << endl;
                break;
            }
            case 7:
            {
                cout << "El monto total a pagar es: " << cap.sueldoTotal() << endl;
                break;
            }
            case 8:
            {
                cout << "Ingrese fecha: dd/mm/aaaa" << endl;
                cin >> dia; cin >> mes; cin >> anio;
                Fecha fec2 (dia, mes, anio);
                while((fec2.esValida() == false) && !salir)
                {
                    cout << "Error: la fecha ingresada no es correcta." << endl;
                    cout << "Ingrese N para ingresar nuevmaente o ingrese S para salir. " << endl;
                    cin >> option;
                    if (option == 'S' || option == 's')
                        salir = true;
                    else
                    {
                        cout << "Ingrese fecha: dd/mm/aaaa" << endl;
                        cin >> dia; cin >> mes; cin >> anio;
                        Fecha fecaux (dia, mes, anio);
                        fec2 = fecaux;
                    }
                }
                if(!salir)
                    cout << "La cantidad de vendedores zafrales que estaran contratados luego de " << dia << "/" << mes << "/" << anio << " es: " << cap.cantZafralesHasta(fec2) << endl;
                break;
            }
            default:
            {
                cout << "La opcion ingresada no es correcta. " << endl;
                cout << "Ingrese nuevamente: " << endl;
            }
        }
    }
}
