#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombreCliente[50];
    char sexoCliente;
}Cliente;

#endif // CLIENTE_H_INCLUDED

void cargarDescripCliente(char descripcionCliente[], int idCliente, Cliente clientes[], int tamClientes);
