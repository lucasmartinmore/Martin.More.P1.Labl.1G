#include "Color.h"

void mostrarColor(Color color)
{
    printf("   %5d           %-11s\n",color.idColor,color.nombreColor);
    printf("__________________________________________\n");
}

int mostrarColores(Color colores[], int tamColores)
{
    int error=-1;
    if(colores!=NULL && tamColores>0)
    {
        system("cls");
        printf("  ----- ***** LISTADO DE COLORES ***** -----  \n");
        printf("____________________________________________  \n");
        printf("ID COLORES      DESCRIPCION\n");
        printf("____________________________________________\n");
        for(int i=0; i<tamColores; i++)
        {
            mostrarColor(colores[i]);
            error=0;
        }
    }
    return error;
}

void cargarDescripcionColor(char descripcionColor[], int idColor, Color colores[], int tamColores)
{
    if(colores!=NULL && tamColores>0)
    {
        for(int i=0; i<tamColores; i++)
        {
            if(colores[i].idColor==idColor)
            {
                strcpy(descripcionColor, colores[i].nombreColor);
                break;
            }
        }
    }
}

