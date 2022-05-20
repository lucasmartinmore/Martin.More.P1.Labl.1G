#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int idServicio;
    char descripcion[25];
    float precio;
} Servicio;

#endif // SERVICIO_H_INCLUDED

void mostrarServicio(Servicio servicio); //SERVICIO
int mostrarServicios(Servicio servicios[], int tamServicios); //SERVICIO
void cargarDescripcionServicio(char descripcionServicio[], int idServicio, Servicio servicios[], int tamServicios); //SERVICIO
