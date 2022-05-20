#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Moto.h"
#include "Trabajo.h"


#endif // INFORME_H_INCLUDED

int MenuInformes();//MENU
void mostrarMotoPorColor(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores,Cliente clientes[], int tamClientes);//PUNTO 1
void mostrarPromedioPorTipo(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores);//PUNTO 2
void mostrarMotosConMayorCilindrada(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Cliente clientes[], int tamClientes);//PUNTO 3
void mostrarMotoSeparadoPorTipo(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Cliente clientes[], int tamClientes);//PUNTO 4
void contadorMotosPorColorTipo(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores);//PUNTO 5
void mostrarTrabajosDeMoto(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios, Cliente clientes[], int tamClientes);//PUNTO 7
void mostrarImportePorServicioDeMoto(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios, Cliente clientes[], int tamClientes);//PUNTO 8
void mostrarMotoPorServicio(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios);//PUNTO 9
void mostrarServiciosPorFecha(Moto  motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios);//PUNTO 10
