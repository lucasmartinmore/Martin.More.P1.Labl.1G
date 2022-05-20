#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include "Color.h"
#include "Tipo.h"
#include "Cliente.h"

typedef struct
{
    int idMoto;
    char marcaMoto[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int puntaje;
    int isEmpty;
    int idCliente;
} Moto;

#endif // MOTO_H_INCLUDED


int MenuPrincipal(); //MOTO
int menuCilindradas(); //MOTO
int menuModificar(); //MOTO
int iniciarMotos(Moto motos[], int tamMotos); //MOTO
int buscarMotosVacias(Moto motos[], int tamMotos, int* error); //MOTO
int altaMoto(Moto motos[],int tamMotos,int idMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipos); //MOTO
int mostrarMotos(Moto motos[], int tamMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipos, Cliente clientes[], int tamClientes);// //MOTO
int mostrarMotos(Moto motos[], int tamMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipo, Cliente clientes[], int tamClientes);// //MOTO
int modificarMotos(Moto motos[], int tamMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipos, Cliente clientes[], int tamClientes); //MOTO
int bajaMoto(Moto motos[], int tamMotos,Color colores[], int tamColores, Tipo tipos[], int tamTipos, Cliente clientes[], int tamClientes);// //MOTO
int validarIdMotoExistente(Moto motos[], int tamMotos, int idMoto); //MOTO
int ordenarMotos(Moto motos[], int tamMotos, int order); //MOTO
int menuOdenamiento(); //MOTO
int hardcodearMotos(Moto* vecMotos, int tamMotos, int cantidadMotos, int idMotos); //MOTO
void cargarDescripCliente(char descripcionCliente[], int idCliente, Cliente clientes[], int tamClientes); //CLIENTE
