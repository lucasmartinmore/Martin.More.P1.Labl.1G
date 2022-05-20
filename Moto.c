#include "Moto.h"

int MenuPrincipal()
{
    system("cls");
    int opcion;
    printf(" ___******** ABM PARCIAL *********___\n");
    printf("|      1) Alta de moto               |\n");
    printf("|      2) Modificar moto             |\n");
    printf("|      3) Baja de moto               |\n");
    printf("|      4) Listar motos               |\n");
    printf("|      5) Listar tipos de motos      |\n");
    printf("|      6) Listar colores de motos    |\n");
    printf("|      7) Listar Servicios           |\n");
    printf("|      8) Alta de trabajo            |\n");
    printf("|      9) Listar los trabajos        |\n");
    printf("|     10) Hardcodear motos           |\n");
    printf("|     11) Hardcodear trabajos        |\n");
    printf("|     12) Informes de motos          |\n");
    printf("|     13) Salir del menu             |\n");
    printf("|____________________________________|\n\n");
    printf("-------------------------------------\n");
    printf("         Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>13)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int menuCilindradas()
{
    int opcion;
    system("cls");
    printf(" ___*** CILINDRADRA ***___\n");
    printf("|         50              |\n");
    printf("|         125             |\n");
    printf("|         500             |\n");
    printf("|         600             |\n");
    printf("|         750             |\n");
    printf("|_________________________|\n\n");
    printf("--------------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d",&opcion);
    while(opcion!=50 && opcion!=125 && opcion!=500
            && opcion!=600 && opcion!=750)
    {
        printf("Reingrese opcion: ");
        scanf("%d",&opcion);
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

int altaMoto(Moto motos[],int tamMotos,int idMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipos)
{
    int eleccionCilindrada;
    int posicion;
    int lugarVacio;

    posicion=buscarMotosVacias(motos,tamMotos,&lugarVacio);//BUSCO
    if(lugarVacio==-1)
    {
        printf("  --------- No se encuentra lugar vacio ! ---------  \n");
        return -1;
    }
    else if(motos!=NULL && colores!=NULL && tipos!=NULL && tamMotos>0
    && tamColores>0 && tamTipos>0 && posicion!=-1 )
    {
        system("cls");
        printf("  --------- ***** ALTA MOTOS ***** ----------  \n\n");

        motos[posicion].isEmpty=0;

        motos[posicion].idMoto = idMotos;

        printf("Ingrese nombre de marca de moto: ");
        fflush(stdin);
        scanf("%s", motos[posicion].marcaMoto);

        mostrarTipos(tipos,tamTipos);

        printf("Ingrese id del tipo de moto: ");
        scanf("%d", &motos[posicion].idTipo);
        while(motos[posicion].idTipo < 1000 || motos[posicion].idTipo > 1003)
        {
            printf("Reingrese id del tipo de moto: ");
            scanf("%d", &motos[posicion].idTipo);
        }

        mostrarColores(colores,tamColores);

        printf("Ingrese id del color de moto: ");
        scanf("%d", &motos[posicion].idColor);
        while(motos[posicion].idColor < 10000 || motos[posicion].idColor > 10004)
        {
            printf("Reingrese id del color de moto: ");
            scanf("%d", &motos[posicion].idColor);
        }

        eleccionCilindrada = menuCilindradas();
        motos[posicion].cilindrada = eleccionCilindrada;

        printf("Ingrese puntaje de moto (1-10): ");
        scanf("%d", &motos[posicion].puntaje);
        while(motos[posicion].puntaje < 1 || motos[posicion].puntaje >10 )
        {
            printf("Reingrese puntaje de moto (1-10): ");
            scanf("%d", &motos[posicion].puntaje);
        }
        printf("\n  --------- Alta exitosa ! ---------  \n");
    }
    return 0;
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


void mostrarMoto(Moto moto, Color colores[], int tamColores, Tipo tipos[], int tamTipos, Cliente clientes[], int tamClientes)
{
    char descripcionColor[25];
    char descripcionTipo[25];
    char DescripCliente[25];

    cargarDescripcionColor(descripcionColor,moto.idColor,colores,tamColores);
    cargarDescripcionTipo(descripcionTipo,moto.idTipo,tipos,tamTipos);
    cargarDescripCliente(DescripCliente,moto.idCliente,clientes,tamClientes);

    if(moto.isEmpty==0)
    {
        printf("  %3d     %-11s  %-11s %-11s %3d          %2d        %-11s\n",moto.idMoto,moto.marcaMoto,descripcionTipo,
        descripcionColor,moto.cilindrada,moto.puntaje,DescripCliente);
        printf("_______________________________________________________________________________\n");
    }
}

int mostrarMotos(Moto motos[], int tamMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipos, Cliente clientes[], int tamClientes)
{
    int error=-1;
    int flagMotosCargadas=-1;

    if(motos!=NULL && tamMotos>0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0)
    {
        system("cls");
        printf("  ----- ***** LISTADO DE MOTOS ***** -----  \n");
        printf("______________________________________________________________________________\n");
        printf("ID MOTO    MARCA        TIPO       COLOR      CILIND      PUNTAJE     CLIENTE\n");
        printf("______________________________________________________________________________\n");
        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].isEmpty==0)
            {
                mostrarMoto(motos[i],colores,tamColores,tipos,tamTipos,clientes,tamClientes);
                flagMotosCargadas=0;
                error=0;
            }
        }
    }

    if(flagMotosCargadas==-1)
    {
        printf("\n  --------- No se encuentran motos cargadas en el sistema ! ---------  \n\n");
    }
    return error;
}

int modificarMotos(Moto motos[], int tamMotos, Color colores[], int tamColores, Tipo tipos[], int tamTipos, Cliente clientes[], int tamClientes)
{
    int posicion;
    int nuevoColor;
    int nuevoPuntaje;
    int error=-1;

    if(motos!=NULL && tamMotos>0 && colores!=NULL && tamColores>0)
    {
        if(mostrarMotos(motos,tamMotos,colores,tamColores,tipos,tamTipos,clientes,tamClientes)!=-1)
        {
            printf("Ingrese id a modificar: ");
            scanf("%d", &posicion);
        }
        else
        {
            return -1;
        }

        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].idMoto==posicion && motos[i].isEmpty==0)
            {
                switch(menuModificar())
                {
                case 1:
                    mostrarColores(colores,tamColores);
                    printf("Ingrese nuevo color de moto: ");
                    scanf("%d", &nuevoColor);
                    while(nuevoColor < 10000 || nuevoColor > 10004)
                    {
                        printf("Reingrese nuevo color de moto: ");
                        scanf("%d", &nuevoColor);
                    }
                    motos[i].idColor = nuevoColor;
                    printf("\n  --------- Cambio de color de moto exitoso ---------  \n");
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
                    motos[i].puntaje = nuevoPuntaje;
                    printf("\n  --------- Cambio de puntaje de moto exitoso ---------  \n");
                    error=1;
                    break;
                }
            }
        }
        if(error==-1)
        {
            printf("\n  --------- Id ingresado no valido ! ---------  \n\n");
        }
    }
    return error;
}

int bajaMoto(Moto motos[], int tamMotos,Color colores[], int tamColores, Tipo tipos[], int tamTipos, Cliente clientes[], int tamClientes)
{
    int posicion;
    char confirmacion;
    int error=-1;

    if(motos!=NULL && tamMotos>0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0)
    {
        if(mostrarMotos(motos,tamMotos,colores,tamColores,tipos,tamTipos,clientes,tamClientes)!=-1)
        {
            printf("Ingrese id de moto a dar de baja: ");
            scanf("%d", &posicion);
        }
        else
        {
            return -1;
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
                    motos[i].idMoto=0;
                    printf("\n  --------- Baja exitosa ! ---------  \n");
                    break;
                }
                else
                {
                    printf("\n  --------- Baja cancelada ! ---------  \n");
                    error=1;
                    break;
                }
            }
        }
        if(error==-1)
        {
            printf("\n  --------- Id ingresado no valido ! ---------  \n\n");
        }
    }
    return error;
}

int validarIdMotoExistente(Moto motos[], int tamMotos, int idMoto)
{
    int error=-1;
    if(motos!=NULL && tamMotos>0)
    {
        for(int i=0; i<tamMotos; i++)
        {
            if(motos[i].isEmpty==0 && motos[i].idMoto==idMoto)
            {
                error=0;
                break;
            }
        }
    }
    return error;
}

int ordenarMotos(Moto motos[], int tamMotos, int order) //0 CRECIENTE 1 DECRECIENTE //
{
    Moto aux;
    if(motos==NULL || tamMotos<0 || (order != 0 && order != 1))
    {
        return -1;
    }
    else
    {
        for(int i=0; i<tamMotos-1; i++)
        {
            for(int j= i+1; j<tamMotos; j++)
            {
                if(motos[i].isEmpty == 0 && motos[j].isEmpty == 0) //ESTAN CARGADOS
                {
                    if(order==1) //CRECIENTE
                    {
                        if(motos[i].idTipo > motos[j].idTipo)
                        {
                            aux = motos[i];
                            motos[i] = motos[j];
                            motos[j] = aux;
                        }
                        if((motos[i].idTipo == motos[j].idTipo) && motos[i].idMoto > motos[j].idMoto)
                        {
                            aux = motos[i];
                            motos[i] = motos[j];
                            motos[j] = aux;
                        }
                    }
                    else // DECRECIENTE
                    {
                        if(motos[i].idTipo < motos[j].idTipo)
                        {
                            aux = motos[i];
                            motos[i] = motos[j];
                            motos[j]= aux;
                        }
                        else if((motos[i].idTipo == motos[j].idTipo) && motos[i].idMoto < motos[j].idMoto)
                        {
                            aux = motos[i];
                            motos[i] = motos[j];
                            motos[j] = aux;
                        }
                    }

                }

            }
        }
    }
    return 0;
}

int menuOdenamiento()
{
    int opcion;
    system("cls");
    printf(" ___*** ODENAMIENTO ***___\n");
    printf("|                         |\n");
    printf("|      1) ASCENDENTE      |\n");
    printf("|                         |\n");
    printf("|      2) DESCENDENTE     |\n");
    printf("|                         |\n");
    printf("|_________________________|\n\n");
    printf("--------------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d",&opcion);
    while(opcion<1 || opcion>2)
    {
        printf("Reingrese opcion: ");
        scanf("%d",&opcion);
    }
    return opcion;
}

int hardcodearMotos(Moto* vecMotos, int tamMotos, int cantidadMotos, int idMotos)
{
    int retorno=-1;
    if (vecMotos != NULL && tamMotos > 0 && cantidadMotos <= tamMotos)
    {
        Moto motos[10]=
        {
        {0,"Zusuki",1001,10002,125,8,0,20},
        {0,"Honda",1003,10004,600,5,0,22},
        {0,"Yamaha",1002,10001,500,7,0,24},
        {0,"Bmw",1000,10000,750,9,0,21},
        {0,"Ducati",1002,10003,50,6,0,25},
        {0,"Zanella",1001,10002,125,4,0,22},
        {0,"Motomel",1000,10004,500,10,0,21},
        {0,"Gilera",1003,10001,600,9,0,25},
        {0,"Guerrero",1002,10004,50,10,0,24},
        {0,"Corven",1003,10000,750,6,0,21},
        };
        for (int i = 0; i < cantidadMotos; i++)
        {
            vecMotos[i] = motos[i];
            vecMotos[i].idMoto= idMotos;
            idMotos++;
            retorno=0;
        }
        printf("\n  --------- Motos hardcodeadas exitosamente ! ---------  \n");
    }
    return retorno;
}
