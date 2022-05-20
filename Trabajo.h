#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "Moto.h"
#include "Servicio.h"
#include "Fecha.h"


typedef struct
{
    int idTrabajo;
    int idMoto;
    int idServicio;
    Fecha fecha;
    int isEmpty;
} Trabajo;

#endif // TRABAJO_H_INCLUDED

int iniciarTrabajos(Trabajo trabajos[], int tamTrabajos); //TRABAJO
int buscarTrabajosVacias(Trabajo trabajos[], int tamTrabajo, int* error); //TRABAJO
int altaTrabajo(Moto motos[],int tamMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipos,Trabajo trabajos[], int tamTrabajos, int idTrabajo, Servicio servicios[], int tamServicios,Cliente clientes[], int tamClientes); //TRABAJO
void mostrarTrabajo(Trabajo trabajo, Servicio servicios[], int tamServicios); //TRABAJO
int mostrarTrabajos(Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios); //TRABAJO
int hardcodearTrabajos(Trabajo* vecTrabajos, int tamTrabajos, int cantidadTrabajos, int idTrabajo); //TRABAJO
