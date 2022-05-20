#include "Tipo.h"

void mostrarTipo(Tipo tipo)
{
    printf(" %4d           %-11s\n",tipo.idTipo,tipo.descripcion);
    printf("__________________________________________\n");
}

int mostrarTipos(Tipo tipos[], int tamTipos)
{
    int error=-1;
    if(tipos!=NULL && tamTipos>0)
    {
        system("cls");
        printf("  ----- ***** LISTADO DE TIPOS ***** -----  \n");
        printf("____________________________________________\n");
        printf("ID TIPOS      DESCRIPCION\n");
        printf("____________________________________________\n");
        for(int i=0; i<tamTipos; i++)
        {
            mostrarTipo(tipos[i]);
            error=0;
        }
    }
    return error;
}

void cargarDescripcionTipo(char descripcionTipo[], int idTipo,Tipo tipos[], int tamTipos)
{
    if(tipos!=NULL && tamTipos>0)
    {
        for(int i=0; i<tamTipos; i++)
        {
            if(tipos[i].idTipo==idTipo)
            {
                strcpy(descripcionTipo, tipos[i].descripcion);
                break;
            }
        }
    }
}
