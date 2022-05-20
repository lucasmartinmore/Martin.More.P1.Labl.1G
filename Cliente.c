#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cargarDescripCliente(char descripcionCliente[], int idCliente, Cliente clientes[], int tamClientes)
{
    if(clientes!=NULL && tamClientes>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].idCliente==idCliente)
            {
                strcpy(descripcionCliente, clientes[i].nombreCliente);
                break;
            }
        }
    }
}
