#include "Trabajo.h"

int iniciarTrabajos(Trabajo trabajos[], int tamTrabajos)
{
    int error=-1;
    if(trabajos!=NULL && tamTrabajos>0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            trabajos[i].isEmpty=1;
            error=1;
        }
    }
    return error;
}

int buscarTrabajosVacias(Trabajo trabajos[], int tamTrabajo, int* error)
{
    *error=-1;
    int posicion=-1;
    if(trabajos!=NULL && tamTrabajo>0)
    {
        for(int i=0; i<tamTrabajo; i++)
        {
            if(trabajos[i].isEmpty==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}


int altaTrabajo(Moto motos[],int tamMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipos,Trabajo trabajos[], int tamTrabajos, int idTrabajo, Servicio servicios[], int tamServicios,Cliente clientes[], int tamClientes)
{
    int posicion;
    int lugarVacio;

    posicion=buscarTrabajosVacias(trabajos,tamTrabajos,&lugarVacio);//BUSCO
    if(lugarVacio==-1)
    {
        printf("  --------- No se encuentra lugar vacio ! ---------  \n");
        return -1;
    }
    else if(motos!=NULL && colores!=NULL && tipos!=NULL && tamMotos>0
    && tamColores>0 && tamTipos>0 && posicion!=-1 && trabajos!=NULL &&
    tamTrabajos>0 && servicios!=NULL && tamServicios>0)
    {
        system("cls");
        printf("  --------- ***** ALTA TRABAJO ***** ----------  \n\n");

        if(mostrarMotos(motos,tamMotos,colores,tamColores,tipos,tamTipos,clientes,tamClientes)!=-1)
        {
            printf("Ingrese id moto: ");
            scanf("%d", &trabajos[posicion].idMoto);
        }
        else
        {
            return -1;
        }

        if(validarIdMotoExistente(motos,tamMotos,trabajos[posicion].idMoto)==0)
        {
            trabajos[posicion].isEmpty=0;
            trabajos[posicion].idTrabajo = idTrabajo;
            mostrarServicios(servicios,tamServicios);
            printf("Ingrese id del servicio a realizar: ");
            scanf("%d", &trabajos[posicion].idServicio);
            while(trabajos[posicion].idServicio<20000 || trabajos[posicion].idServicio>20003)
            {
                printf("Reingrese id del servicio a realizar: ");
                scanf("%d", &trabajos[posicion].idServicio);
            }
            printf("Ingrese dia del trabajo a realizar: ");
            scanf("%d", &trabajos[posicion].fecha.dia);
            while(trabajos[posicion].fecha.dia<1 || trabajos[posicion].fecha.dia>31)
            {
                printf("Reingrese dia del trabajo a realizar: ");
                scanf("%d", &trabajos[posicion].fecha.dia);
            }
            printf("Ingrese mes del trabajo a realizar: ");
            scanf("%d", &trabajos[posicion].fecha.mes);
            while(trabajos[posicion].fecha.mes<1 || trabajos[posicion].fecha.mes>12)
            {
                printf("Reingrese mes del trabajo a realizar: ");
                scanf("%d", &trabajos[posicion].fecha.mes);
            }
            printf("Ingrese anio del trabajo a realizar(AAAA): ");
            scanf("%d", &trabajos[posicion].fecha.anio);
            while(trabajos[posicion].fecha.anio<2022 || trabajos[posicion].fecha.anio>2050)
            {
                printf("Reingrese anio del trabajo a realizar(AAAA): ");
                scanf("%d", &trabajos[posicion].fecha.anio);
            }
            printf("\n  --------- Alta exitosa ! ---------  \n");
        }
        else
        {
            printf("  --------- Id ingresado no valido ! ---------  \n");
        }
    }
    return 0;
}


void mostrarTrabajo(Trabajo trabajo, Servicio servicios[], int tamServicios)
{
    char descripcionServicio[25];
    cargarDescripcionServicio(descripcionServicio,trabajo.idServicio,servicios,tamServicios);

    if(trabajo.isEmpty==0)
    {
        printf("   %5d       %3d       %-11s     %2d/%2d/%4d\n",trabajo.idTrabajo,trabajo.idMoto,
               descripcionServicio,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
        printf("____________________________________________________\n");
    }
}

int mostrarTrabajos(Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios)
{
    int error=-1;
    int flagTrabajoInicial=-1;
    if(trabajos!=NULL && tamTrabajos>0 && servicios!=NULL && tamServicios>0)
    {
        system("cls");
        printf("  ----- ***** LISTADO DE TRABAJOS ***** -----  \n");
        printf("____________________________________________________\n");
        printf("ID TRABAJO   ID MOTO    SERVICIO          FECHA\n");
        printf("____________________________________________________\n");
        for(int i=0; i<tamTrabajos; i++)
        {
            if(trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tamServicios);
                flagTrabajoInicial=0;
                error=0;
            }
        }
        if(flagTrabajoInicial==-1)
        {
            printf("\n  --------- No se encuentran Trabajos cargados en el sistema ! ---------  \n\n");
        }
    }
    return error;
}


int hardcodearTrabajos(Trabajo* vecTrabajos, int tamTrabajos, int cantidadTrabajos, int idTrabajo)
{
    int retorno=-1;
    if (vecTrabajos != NULL && tamTrabajos > 0 && cantidadTrabajos <= tamTrabajos)
    {
        Trabajo trabajos[10]=
        {
        {0,100,20000,{22,07,2022},0},
        {0,109,20001,{19,04,2025},0},
        {0,108,20003,{21,5,2030},0},
        {0,107,20002,{31,8,2035},0},
        {0,101,20000,{19,4,2025},0},
        {0,109,20001,{31,5,2040},0},
        {0,102,20003,{8,7,2022},0},
        {0,102,20002,{22,2,2025},0},
        {0,109,20001,{30,4,2032},0},
        {0,107,20000,{8,7,2022},0},
        };
        for (int i = 0; i < cantidadTrabajos; i++)
        {
            vecTrabajos[i] = trabajos[i];
            vecTrabajos[i].idTrabajo= idTrabajo;
            idTrabajo++;
            retorno=0;
        }
        printf("\n  --------- Trabajos hardcodeados exitosamente ! ---------  \n");
    }
    return retorno;
}






