#include "String.h"
#include <iostream>
using namespace std;

String :: String()
{
    cadena = new char[1];
    cadena[0] = '\0';
}
String :: String(char * cad)
{
    int largo = strlen(cad);
    cadena = new char[largo + 1];
    strcpy(cadena, cad);
}
String :: ~String()
{
    delete [] cadena;
}
String :: String(const String &otro)
{
    int largo = strlen(otro.cadena);
    cadena = new char[largo + 1];
    strcpy(cadena, otro.cadena);
}
String String :: operator=(const String &otro)
{
    if(this != &otro)
    {
        delete [] cadena;
        int largo = strlen(otro.cadena);
        cadena = new char [largo + 1];
        strcpy(cadena, otro.cadena);
    }
    return (*this);
}
bool String :: mismoLargo(String otro)
{
    bool mismo = false;
    if(strlen(cadena)== strlen(otro.cadena))
        mismo = true;
    else
        mismo = false;
    return mismo;
}
bool String :: operator== (String otro)
{
    return (strcmp(cadena, otro.cadena) == 0);
}
bool String :: operator< (String otro)
{
    return (strcmp(cadena, otro.cadena) == 0);
}
String String :: operator+ (String s)
{
    String aux;
    int largo1 = strlen (cadena);
    int largo2 = strlen (s.cadena);
    aux.cadena = new char [largo1 + largo2 + 1];
    strcpy (aux.cadena,cadena);
    strcat (aux.cadena,s.cadena);
    return aux;
}
void String :: scan()
{
    char aux[MAX];
    char c = cin.get();
    int i=0;
    while (c!='\n' && i<MAX-1)
    {
         aux[i] = c;
         i++;
         c = cin.get();
    }
    aux[i]='\0';
    cadena = new char[i + 1];
    strcpy(cadena,aux);
}
void String :: print()
{
    cout << cadena;
}


