#ifndef TIPOERROR_H_INCLUDED
#define TIPOERROR_H_INCLUDED

typedef enum { SIN_ERROR, NO_INGRESA_TIPO, SUPERVISOR_NO_EXISTE, SUPERVISOR_YA_EXISTE, VENDEDOR_YA_EXISTE, VENDEDOR_NO_EXISTE} TipoError;

void mostrarTipoError();

#endif // TIPOERROR_H_INCLUDED
