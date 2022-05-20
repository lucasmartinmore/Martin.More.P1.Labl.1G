#include "Servicio.h"

void mostrarServicio(Servicio servicio)
{
    printf("   %5d       %-11s   %4.2f\n",servicio.idServicio,servicio.descripcion,servicio.precio);
    printf("____________________________________________________\n");
}

int mostrarServicios(Servicio servicios[], int tamServicios)
{
    int error=-1;
    if(servicios!=NULL && tamServicios>0)
    {
        system("cls");
        printf("  ----- ***** LISTADO DE SERVICIOS ***** -----  \n");
        printf("____________________________________________________\n");
        printf("ID SERVICIO   DESCRIPCION    PRECIO\n");
        printf("____________________________________________________\n");
        for(int i=0; i<tamServicios; i++)
        {
            mostrarServicio(servicios[i]);
            error=0;
        }
    }
    return error;
}

void cargarDescripcionServicio(char descripcionServicio[], int idServicio, Servicio servicios[], int tamServicios)
{
    if(servicios!=NULL && tamServicios>0)
    {
        for(int i=0; i<tamServicios; i++)
        {
            if(servicios[i].idServicio==idServicio)
            {
                strcpy(descripcionServicio, servicios[i].descripcion);
                break;
            }
        }
    }
}
