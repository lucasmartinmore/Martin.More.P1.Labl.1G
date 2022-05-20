#include "Informe.h"

int MenuInformes()
{
    system("cls");
    int opcion;
    printf(" ___********  INFORMES  *********___\n");
    printf("|    1) Mostrar moto por Color      |\n");
    printf("|    2) Mostrar Promedio por Punt   |\n");
    printf("|    3) Mostrar moto mayor Cilind   |\n");
    printf("|    4) Mostrar moto por Tipo       |\n");
    printf("|    5) Contar motos Color/Tipo     |\n");
    printf("|    6) Mostrar motos mas Colores   |\n");
    printf("|    7) Mostrar trabajo por Moto    |\n");
    printf("|    8) Mostrar importe por Moto    |\n");
    printf("|    9) Mostrar moto por Servicio   |\n");
    printf("|   10) Mostrar servicios por fecha |\n");
    printf("|___________________________________|\n\n");
    printf("-------------------------------------\n");
    printf("         Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>10)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

void mostrarMotoPorColor(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores,Cliente clientes[], int tamClientes)
{
    int flagColorInicial=-1;
    int idColor;

    if(motos!=NULL && tamMotos>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        mostrarColores(colores,tamColores);
        printf("Ingrese id del color de moto a mostrar: ");
        scanf("%d", &idColor);
        while(idColor < 10000 || idColor > 10004)
        {
            printf("Reingrese id del color de moto a mostrar: ");
            scanf("%d", &idColor);
        }

        system("cls");
        printf("  ----- ***** LISTADO DE MOTOS POR COLOR ***** -----  \n");
        printf("______________________________________________________________________________\n");
        printf("ID MOTO    MARCA        TIPO       COLOR      CILIND      PUNTAJE     CLIENTE\n");
        printf("______________________________________________________________________________\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].isEmpty==0 && motos[i].idColor == idColor)
            {
                mostrarMoto(motos[i],colores,tamColores,tipos,tamTipos,clientes,tamClientes);
                flagColorInicial=0;
            }
        }
    }

    if(flagColorInicial==-1)
    {
        printf("\n  ---- No se encuentran motos de ese color cargadas en el sistema ! ----  \n\n");
    }
}

void mostrarPromedioPorTipo(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores)
{
    int idTipos;
    float acumuladorPuntajeTipo=0;
    int contadorPuntajeTipo=0;
    float promedioTipo;

    if(motos!=NULL && tamMotos>0 && tipos!=NULL && tamTipos>0 && colores!=NULL && tamColores>0)
    {
        mostrarTipos(tipos,tamTipos);
        printf("Ingrese id del tipo de moto a mostrar: ");
        scanf("%d", &idTipos);
        while(idTipos < 1000 || idTipos > 1003)
        {
            printf("Reingrese id del tipo de moto a mostrar: ");
            scanf("%d", &idTipos);
        }

        system("cls");
        printf("  ----- ***** PROMEDIO DE PUNTAJE POR TIPO ***** -----  \n");
        printf("______________________________________________________________________________\n");

        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].isEmpty==0 && motos[i].idTipo == idTipos)
            {
                acumuladorPuntajeTipo+=motos[i].puntaje;
                contadorPuntajeTipo++;
            }
        }
        promedioTipo=(float)(acumuladorPuntajeTipo/contadorPuntajeTipo);
    }

    if(contadorPuntajeTipo==0)
    {
        printf("\n  ---- No se encuentran motos de ese tipo cargadas en el sistema ! ----  \n\n");
    }
    else
    {
        printf("\n  ---- El promedio del puntaje del tipo seleccionado es de %.2f ! ----  \n\n",promedioTipo);
    }
}

void mostrarMotosConMayorCilindrada(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Cliente clientes[], int tamClientes)
{
    int mayorCilindrada=0;

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].isEmpty == 0)
        {
            if(motos[i].cilindrada > mayorCilindrada)
            {
                mayorCilindrada=motos[i].cilindrada;
            }
        }
    }

    system("cls");
    printf("  ----- ***** LISTADO DE MOTOS CON MAYOR CILINDRADAS ***** -----  \n");
    printf("______________________________________________________________________________\n");
    printf("ID MOTO    MARCA        TIPO       COLOR      CILIND      PUNTAJE     CLIENTE\n");
    printf("______________________________________________________________________________\n");

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].cilindrada == mayorCilindrada)
        {
            mostrarMoto(motos[i],colores,tamColores,tipos,tamTipos,clientes,tamClientes);
        }
    }
    printf("\n  ---- La mayor cilindrada en el sistema es de %d ! ----  \n\n",mayorCilindrada);
}

void mostrarMotoSeparadoPorTipo(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Cliente clientes[], int tamClientes)
{
    system("cls");
    printf("  ----- ***** LISTADO DE MOTOS POR TIPOS ***** -----  \n");

    for(int i=0; i<tamTipos; i++)
    {
        printf("\n\n        ----------- TIPO  -------------\n");
        printf("      |            %s                |\n",tipos[i].descripcion);
        printf("      |___________________________________|\n\n");

        //printf("______________________________________________________________________________\n");
        printf("ID MOTO    MARCA        TIPO       COLOR      CILIND      PUNTAJE     CLIENTE\n");
        printf("______________________________________________________________________________\n");

        for(int j=0; j<tamMotos; j++)
        {
            if(motos[j].isEmpty == 0 && motos[j].idTipo == tipos[i].idTipo)
            {
                mostrarMoto(motos[j],colores,tamColores,tipos,tamTipos,clientes,tamClientes);
            }
        }
    }
}


void contadorMotosPorColorTipo(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores)
{
    int flagColorTipo=0;
    int idColor;
    int idTipos;
    char descripcionColor[20];
    char descripcionTipo[20];
    int contadorColorTipo = 0;

    mostrarColores(colores,tamColores);
    printf("Ingrese id del color de moto a mostrar: ");
    scanf("%d", &idColor);
    while(idColor < 10000 || idColor > 10004)
    {
        printf("Reingrese id del color de moto a mostrar: ");
        scanf("%d", &idColor);
    }

    mostrarTipos(tipos,tamTipos);
    printf("Ingrese id del tipo de moto a mostrar: ");
    scanf("%d", &idTipos);
    while(idTipos < 1000 || idTipos > 1003)
    {
        printf("Reingrese id del tipo de moto a mostrar: ");
        scanf("%d", &idTipos);
    }

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].isEmpty==0 && motos[i].idColor == idColor && motos[i].idTipo == idTipos)
        {
            contadorColorTipo++;
            cargarDescripcionColor(descripcionColor,motos[i].idColor,colores,tamColores);
            cargarDescripcionTipo(descripcionTipo,motos[i].idTipo,tipos,tamTipos);
            flagColorTipo=1;
        }
    }
    if(flagColorTipo!=1)
    {
        printf("\n  ---- No se encuentran motos de ese color y tipo cargadas en el sistema ! ----  \n\n");;
    }
    else
    {
        system("cls");
        printf("  ----- ***** INFORME DE MOTOS POR COLOR Y TIPO ***** -----  \n");
        printf("______________________________________________________________________________\n");
        printf("\n  ---- Hay %d motos del color %s y del tipo %s cargadas en el sistema ! ----  \n\n",contadorColorTipo,descripcionColor,descripcionTipo);
    }
}

void mostrarTrabajosDeMoto(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios, Cliente clientes[], int tamClientes)
{
    int flagTrabajoInicial=-1;
    int idMoto;

    if(mostrarMotos(motos,tamMotos,colores,tamColores,tipos,tamTipos,clientes,tamClientes)!=-1)
    {
        printf("Ingrese id de motos: ");
        scanf("%d", &idMoto);
    }

    if(validarIdMotoExistente(motos,tamMotos,idMoto)!=-1)
    {
        system("cls");
        printf("  ----- ***** LISTADO DE TRABAJOS POR MOTO ***** -----  \n");
        printf("____________________________________________________\n");
        printf("ID TRABAJO   ID MOTO    SERVICIO          FECHA\n");
        printf("____________________________________________________\n");
        for(int i=0; i<tamTrabajos; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == idMoto)
            {
                mostrarTrabajo(trabajos[i],servicios,tamServicios);
                flagTrabajoInicial=0;
            }
        }

        if(flagTrabajoInicial!=0)
        {
            printf("\n  --------- No se encuentran trabajos registrados para la moto indicada ! ---------  \n\n");
        }
    }
    else
    {
        printf("\n  --------- Id ingresado no valido ! ---------  \n\n");
    }


}

void mostrarImportePorServicioDeMoto(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios,  Cliente clientes[], int tamClientes)
{
    int flagServicioInicial=0;
    float acumuladorServicio=0;
    int idMoto;

    if(mostrarMotos(motos,tamMotos,colores,tamColores,tipos,tamTipos,clientes,tamClientes)!=-1)
    {
        printf("Ingrese id de motos: ");
        scanf("%d", &idMoto);
    }

    if(validarIdMotoExistente(motos,tamMotos,idMoto)!=-1)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == idMoto)
            {
                for(int j=0; j<tamServicios; j++)
                {
                    if(servicios[j].idServicio == trabajos[i].idServicio)
                    {
                        acumuladorServicio+=servicios[j].precio;
                        flagServicioInicial=1;
                    }
                }
            }
        }
        printf("\n  --------- El total de servicio/s realizado/s a la moto indicada es de %.2f pesos ! ---------  \n\n",acumuladorServicio);
    }
    else
    {
        printf("\n  --------- Id ingresado no valido ! ---------  \n\n");
    }

    if(flagServicioInicial!=1)
    {
        printf("\n  --------- No se encuentran servicios registrados para la moto indicada ! ---------  \n\n");
    }
}

void mostrarMotoPorServicio(Moto motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios)
{
    int flagServicioInicial=-1;
    int idServicio;

    mostrarServicios(servicios,tamServicios);
    printf("Ingrese id del servicio a realizar: ");
    scanf("%d", &idServicio);
    while(idServicio<20000 || idServicio>20003)
    {
        printf("Reingrese id del servicio a realizar: ");
        scanf("%d", &idServicio);
    }

    system("cls");
    printf("  ----- ***** LISTADO DE MOTOS CON SERVICIO REALIZADO ***** -----  \n");
    printf("____________________________________________________\n");
    printf("ID TRABAJO   ID MOTO    SERVICIO          FECHA\n");
    printf("____________________________________________________\n");
    for(int i=0; i<tamTrabajos; i++)
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].idServicio == idServicio)
        {
            mostrarTrabajo(trabajos[i],servicios,tamServicios);
            flagServicioInicial = 1;
        }
    }

    if(flagServicioInicial!=1)
    {
        printf("\n  --------- No se encuentran motos con ese servicio realizado ! ---------  \n\n");
    }
}

void mostrarServiciosPorFecha(Moto  motos[], int tamMotos, Tipo tipos[], int tamTipos, Color colores[], int tamColores, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicios)
{
    int flagServicioInicial=-1;
    int dia;
    int mes;
    int anio;

    printf("Ingrese dia del servicio a mostrar: ");
    scanf("%d", &dia);
    while(dia<1 || dia>31)
    {
        printf("Reingrese dia del servicio a mostrar: ");
        scanf("%d", &dia);
    }
    printf("Ingrese mes del servicio a mostrar: ");
    scanf("%d", &mes);
    while(mes<1 || mes>12)
    {
        printf("Reingrese mes del servicio a mostrar: ");
        scanf("%d", &mes);
    }
    printf("Ingrese anio del servicio a mostrar(AAAA): ");
    scanf("%d", &anio);
    while(anio<2022 || anio>2050)
    {
        printf("Reingrese anio del servicio a mostrar(AAAA): ");
        scanf("%d", &anio);
    }

    system("cls");
    printf("  ----- ***** LISTADO DE SERVICIOS POR FECHA ***** -----  \n");
    printf("____________________________________________________\n");
    printf("ID TRABAJO   ID MOTO    SERVICIO          FECHA\n");
    printf("____________________________________________________\n");
    for(int i=0; i<tamTrabajos; i++)
    {
        if(trabajos[i].isEmpty == 0 && (trabajos[i].fecha.dia == dia) && (trabajos[i].fecha.mes == mes) && (trabajos[i].fecha.anio == anio))
        {
            mostrarTrabajo(trabajos[i],servicios,tamServicios);
            flagServicioInicial=0;
        }
    }
    if(flagServicioInicial!=0)
    {
        printf("\n  --------- No se encuentran servicios realizados en ese fecha ! ---------  \n\n");
    }
}
