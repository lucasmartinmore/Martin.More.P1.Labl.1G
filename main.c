#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    int idTipo;
    char descripcion[20];
} Tipo;

typedef struct
{
    int idColor;
    char nombreColor[20];
} Color;

typedef struct
{
    int idMoto;
    char marcaMoto[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int puntaje;
    int isEmpty;
} Moto;

typedef struct
{
    int idServicio;
    char descripcion[25];
    float precio;
} Servicio;

typedef struct
{
    int idTrabajo;
    int idMoto;
    int idServicio;
    Fecha fecha;
} Trabajo;

#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define TAM_MOTOS 500

int MenuPrincipal();
int menuCilindradas();
int iniciarMotos(Moto motos[], int tamMotos);
int buscarMotosVacias(Moto motos[], int tamMotos, int* error);
int altaMoto(Moto motos[],int tamMotos,int posicion,int idMotos);
int menuModificar();
void mostrarMoto(Moto moto);
int mostrarMotos(Moto motos[], int tamMotos);
int modificarMotos(Moto motos[], int tamMotos, Color colores[], int tamColores);
int bajaMoto(Moto motos[], int tamMotos,Color colores[], int tamColores);
void mostrarTipo(Tipo tipo);
int mostrarTipos(Tipo tipos[], int tamTipos);
void mostrarServicio(Servicio servicio);
int mostrarServicios(Servicio servicios[], int tamServicios);
void mostrarColor(Color color);
int mostrarColores(Color colores[], int tamColores);

int main()
{
    Tipo tipos[TAM_TIPO]= {{1000,"Enduro"}, {1001,"Chopera"}, {1002,"Scooter"}, {1003,"Vintage"}};
    Color colores[TAM_COLOR]= {{10000,"Gris"}, {10001,"Negro"}, {10002, "Azul"}, {10003, "Blanco"}, {10004, "Rojo"}};
    Servicio servicios[TAM_SERVICIO]= {{20000, "Limpieza", 450}, {20001, "Ajuste", 300}, {20002, "Balanceo", 150}, {20003, "Cadena", 390}};

    int seguirInicial=0;
    //VARIABLES MOTOS
    Moto motos[TAM_MOTOS];
    int posicionVaciaMoto;
    int errorPosicionMoto;
    int idMotos=100;
    int banderaInicialMotos=0;

    iniciarMotos(motos,TAM_MOTOS);

    do
    {
        switch(MenuPrincipal())
        {
        case 1:
            posicionVaciaMoto=buscarMotosVacias(motos,TAM_MOTOS,&errorPosicionMoto);
            if(errorPosicionMoto!=-1)
            {
                altaMoto(motos,TAM_MOTOS,posicionVaciaMoto,idMotos);
                idMotos++;
                banderaInicialMotos=1;
            }
            else
            {
                printf("  --------- No se encuentra lugar vacio ! ---------  \n");
            }
            break;
        case 2:
            if(banderaInicialMotos==1)
            {
                modificarMotos(motos,TAM_MOTOS,colores,TAM_COLOR);
            }
            else
            {
                printf("  --------- Hay que cargar una moto antes de modificar ! ---------  \n");
            }
            break;
        case 3:
            if(banderaInicialMotos==1)
            {
                mostrarMotos(motos,TAM_MOTOS);
                bajaMoto(motos,TAM_MOTOS,colores,TAM_COLOR);
            }
            else
            {
                printf("  --------- Se debe cargar una moto antes de dar una baja ! ---------  \n");
            }
            break;
        case 4:

            break;
        case 5:
            if(mostrarTipos(tipos,TAM_TIPO)==-1)
            {
                printf("  --------- Error al mostrar tipos ! ---------  \n");
            }
            break;
        case 6:
            if(mostrarColores(colores, TAM_COLOR)==-1)
            {
                printf("  --------- Error al mostrar Colores ! ---------  \n");
            }
            break;
        case 7:
            if(mostrarServicios(servicios, TAM_SERVICIO)==-1)
            {
                printf("  --------- Error al mostrar Servicios ! ---------  \n");
            }
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            seguirInicial=1;
            break;
        }
        system("pause");
    }
    while(seguirInicial==0);


    return 0;
}

int MenuPrincipal()
{
    system("cls");
    int opcion;
    printf("|--------AMB---------|\n");
    printf("|  1) ALTA MOTO      |\n");
    printf("|  2) MODIF MOTO     |\n");
    printf("|  3) BAJA MOTO      |\n");
    printf("|  4) LISTAR MOTO    |\n");
    printf("|  5) LISTAR TIPO    |\n");
    printf("|  6) LISTAR COLOR   |\n");
    printf("|  7) LISTAR SERV    |\n");
    printf("|  8) ALTA TRAB      |\n");
    printf("|  9) LISTAR TRABJ   |\n");
    printf("| 10) SALIR          |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>10)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int menuCilindradas()
{
    system("cls");
    int opcion;
    printf("|----CILINDRADRA-----|\n");
    printf("|  1) 50             |\n");
    printf("|  2) 125            |\n");
    printf("|  3) 500            |\n");
    printf("|  4) 600            |\n");
    printf("|  5) 750            |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>5)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int iniciarMotos(Moto motos[], int tamMotos)
{
    int error=-1;
    if(motos!=NULL && tamMotos>0)
    {
        for(int i=0; i<tamMotos; i++)
        {
            motos[i].isEmpty=1;
            error=1;
        }
    }
    return error;
}

int buscarMotosVacias(Moto motos[], int tamMotos, int* error)
{
    *error=-1;
    int posicion=-1;
    if(motos!=NULL && tamMotos>0)
    {
        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].isEmpty==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}

int altaMoto(Moto motos[],int tamMotos,int posicion,int idMotos)
{
    int error=-1;
    int eleccionCilindrada;
    if((motos!=NULL && tamMotos>0) && posicion!=-1)
    {
        system("cls");
        printf("  --------- ALTA MOTOS ----------  |\n");

        motos[posicion].isEmpty=0;

        motos[posicion].idMoto = idMotos;

        printf("Ingrese nombre de marca de moto: ");
        fflush(stdin);
        scanf("%s", motos[posicion].marcaMoto);

        printf("Ingrese tipo de moto (1000=Enduro/1001=Chopera/1002=Scooter/1003=Vintage): ");
        scanf("%d", &motos[posicion].idTipo);
        while(motos[posicion].idTipo < 1000 || motos[posicion].idTipo > 1003)
        {
            printf("Reingrese tipo de moto (1000=Enduro/1001=Chopera/1002=Scooter/1003=Vintage): ");
            scanf("%d", &motos[posicion].idTipo);
        }

        printf("Ingrese color de moto (10000=Gris/10001=Negro/10002=Azul/10003=Blanco/10004=Rojo): ");
        scanf("%d", &motos[posicion].idColor);
        while(motos[posicion].idColor < 10000 || motos[posicion].idColor > 10003)
        {
            printf("Reingrese color de moto (10000=Gris/10001=Negro/10002=Azul/10003=Blanco/10004=Rojo): ");
            scanf("%d", &motos[posicion].idColor);
        }

        eleccionCilindrada = menuCilindradas();
        scanf("%d", &motos[posicion].cilindrada);

        printf("Ingrese puntaje de moto (1-10): ");
        scanf("%d", &motos[posicion].puntaje);
        while(motos[posicion].puntaje < 1 || motos[posicion].puntaje >10 )
        {
            printf("Reingrese puntaje de moto (1-10): ");
            scanf("%d", &motos[posicion].puntaje);
        }

        error=1;

        printf("  --------- Alta exitosa ---------  \n");
    }
    return error;
}

int menuModificar()
{
    system("cls");
    int opcion;
    printf("|---- MODIFICAR -----|\n");
    printf("|  1) Color          |\n");
    printf("|  2) Puntaje        |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>2)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}


void mostrarMoto(Moto moto)
{
    char descripcionColor[20];
    char descripcionTipo[20];

    if(moto.isEmpty==0)
    {
        switch(moto.idColor)
        {
        case 10000:
            strcpy(descripcionColor,"Gris");
            break;
        case 10001:
            strcpy(descripcionColor,"Negro");
            break;
        case 10002:
            strcpy(descripcionColor,"Azul");
            break;
        case 10003:
            strcpy(descripcionColor,"Blanco");
            break;
        case 10004:
            strcpy(descripcionColor,"Rojo");
            break;
        }

        switch(moto.idTipo)
        {
        case 1000:
            strcpy(descripcionTipo,"Enduro");
            break;
        case 1001:
            strcpy(descripcionTipo,"Chopera");
            break;
        case 1002:
            strcpy(descripcionTipo,"Scooter");
            break;
        case 1003:
            strcpy(descripcionTipo,"Vintage");
            break;
        }

        printf("%2d    %-11s   %-11s     %-11s    %3d    %2d\n",moto.idMoto,moto.marcaMoto,descripcionTipo,
               descripcionColor,moto.cilindrada,moto.puntaje);
        printf("-------------------------------------------------------------------------------------------------\n");
    }
}

int mostrarMotos(Moto motos[], int tamMotos)
{
    int error=-1;
    if(motos!=NULL && tamMotos>0)
    {
        printf("ID MOTO  MARCA   ID-TIP    ID-COLOR   CILIND   PUNTAJE\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].isEmpty==0)
            {
                mostrarMoto(motos[i]);
                error=0;
            }
        }
    }
    return error;
}

int modificarMotos(Moto motos[], int tamMotos, Color colores[], int tamColores)
{
    int posicion;
    int nuevoColor;
    int nuevoPuntaje;
    int error=-1;

    if(motos!=NULL && tamMotos>0 && colores!=NULL && tamColores>0)
    {
        mostrarMotos(motos,tamMotos);
        printf("Ingrese id a modificar: ");
        scanf("%d", &posicion);
        while(posicion<100)
        {
            printf("Reingrese id de moto a dar de baja: ");
           scanf("%d", &posicion);
        }

        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].idMoto==posicion && motos[i].isEmpty==0)
            {
                switch(menuModificar())
                {
                case 1:
                    printf("Ingrese nuevo color de moto (10000=Gris/10001=Negro/10002=Azul/10003=Blanco/10004=Rojo): ");
                    scanf("%d", &nuevoColor);
                    while(nuevoColor < 10000 || nuevoColor > 10004)
                    {
                        printf("Reingrese color de moto (10000=Gris/10001=Negro/10002=Azul/10003=Blanco/10004=Rojo): ");
                        scanf("%d", &nuevoColor);
                    }
                    scanf("%d",&motos[i].idColor);
                    printf("  --------- Cambio de color de moto exitoso ---------  \n");
                    error=1;
                    break;
                case 2:
                    printf("Ingrese nuevo puntaje de moto (1-10): ");
                    scanf("%d", &nuevoPuntaje);
                    while(nuevoPuntaje < 1 || nuevoPuntaje >10 )
                    {
                        printf("Reingrese puntaje de moto (1-10): ");
                        scanf("%d", &nuevoPuntaje);
                    }
                    scanf("%d",&motos[i].puntaje);
                    printf("  --------- Cambio de puntaje de moto exitoso ---------  \n");
                    error=1;
                    break;
                }
            }
        }
    }
    return error;
}

int bajaMoto(Moto motos[], int tamMotos,Color colores[], int tamColores)
{
    int posicion;
    char confirmacion;
    int error=-1;

    if(motos!=NULL && tamMotos>0 && colores!=NULL && tamColores>0)
    {
        //mostrarMotos(motos, tamMotos);
        printf("Ingrese id de moto a dar de baja: ");
        scanf("%d", &posicion);
        while(posicion<100)
        {
            printf("Reingrese id de moto a dar de baja: ");
           scanf("%d", &posicion);
        }

        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].idMoto==posicion)
            {
                printf("Deseas continuar con la baja(Y/N): ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = toupper(confirmacion);
                while(confirmacion!='Y' && confirmacion!='N')
                {
                    printf("Error. Deseas continuar con la baja(Y/N): ");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = toupper (confirmacion);
                }
                if(confirmacion=='Y')
                {
                    error=1;
                    motos[i].isEmpty=1;
                    printf("  --------- Baja exitosa ! ---------  \n");
                    break;
                }
                else
                {
                    printf("  --------- Baja cancelada ! ---------  \n");
                    break;
                }
            }
        }
    }
    return error;
}

void mostrarTipo(Tipo tipo)
{
    printf("%4d    %-11s\n",tipo.idTipo,tipo.descripcion);
    printf("-------------------------------------------------------------------------------------------------\n");
}

int mostrarTipos(Tipo tipos[], int tamTipos)
{
    int error=-1;
    if(tipos!=NULL && tamTipos>0)
    {
        printf("ID T   DESCRIPCION\n");
        for(int i=0; i<tamTipos; i++)
        {
            mostrarTipo(tipos[i]);
            error=0;
        }
    }
    return error;
}

void mostrarServicio(Servicio servicio)
{
    printf("  %5d    %-11s    %4.2f\n",servicio.idServicio,servicio.descripcion,servicio.precio);
    printf("-------------------------------------------------------------------------------------------------\n");
}

int mostrarServicios(Servicio servicios[], int tamServicios)
{
    int error=-1;
    if(servicios!=NULL && tamServicios>0)
    {
        printf("ID-SERV   DESCRIPCION    PRECIO\n");
        for(int i=0; i<tamServicios; i++)
        {
            mostrarServicio(servicios[i]);
            error=0;
        }
    }
    return error;
}

void mostrarColor(Color color)
{
    printf("%5d    %-11s\n",color.idColor,color.nombreColor);
    printf("-------------------------------------------------------------------------------------------------\n");
}

int mostrarColores(Color colores[], int tamColores)
{
    int error=-1;
    if(colores!=NULL && tamColores>0)
    {
        printf("ID C   DESCRIPCION\n");
        for(int i=0; i<tamColores; i++)
        {
            mostrarColor(colores[i]);
            error=0;
        }
    }
    return error;
}



