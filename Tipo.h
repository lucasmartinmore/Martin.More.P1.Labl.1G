#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int idTipo;
    char descripcion[20];
} Tipo;

#endif // TIPO_H_INCLUDED

void mostrarTipo(Tipo tipo); //TIPO
int mostrarTipos(Tipo tipos[], int tamTipos); //TIPO
void cargarDescripcionTipo(char descripcionTipo[], int idTipo,Tipo tipos[], int tamTipos); //TIPO
