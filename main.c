#include "Moto.h"
#include "Trabajo.h"
#include "Informe.h"
#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define TAM_MOTOS 500
#define TAM_TRABAJOS 500
#define TAM_CLIENTES 6

int main()
{
    //ESTRUCTURAS HARDCODEADAS
    Tipo tipos[TAM_TIPO]= {{1000,"Enduro"}, {1001,"Chopera"}, {1002,"Scooter"}, {1003,"Vintage"}};
    Color colores[TAM_COLOR]= {{10000,"Gris"}, {10001,"Negro"}, {10002, "Azul"}, {10003, "Blanco"}, {10004, "Rojo"}};
    Servicio servicios[TAM_SERVICIO]= {{20000, "Limpieza", 450}, {20001, "Ajuste", 300}, {20002, "Balanceo", 150}, {20003, "Cadena", 390}};
    Cliente clientes[TAM_CLIENTES]= {{20,"Lucas",'M'},{21,"Miguel",'M'},{22,"Juan",'M'},{23,"Martin",'M'},{24,"Belen",'F'},{25,"Lucia",'F'}};
    //VARIABLES MOTOS
    Moto motos[TAM_MOTOS];
    int idMotos=100;
    int seguirInicial=0;
    int opcionOrdenamiento;
    //VARIABLES TRABAJO
    Trabajo trabajos[TAM_TRABAJOS];
    int idTrabajo=1;
    //INICIALIZO MIS ARRAYS
    iniciarMotos(motos,TAM_MOTOS);
    iniciarTrabajos(trabajos,TAM_TRABAJOS);

    do
    {
        switch(MenuPrincipal())
        {
        case 1:
            altaMoto(motos,TAM_MOTOS,idMotos,colores,TAM_COLOR,tipos,TAM_TIPO);
            idMotos++;
            break;
        case 2:
            modificarMotos(motos,TAM_MOTOS,colores,TAM_COLOR,tipos,TAM_TIPO,clientes,TAM_CLIENTES);
            break;
        case 3:
            bajaMoto(motos,TAM_MOTOS,colores,TAM_COLOR,tipos,TAM_TIPO,clientes,TAM_CLIENTES);
            break;
        case 4:
            opcionOrdenamiento=menuOdenamiento();
            if(opcionOrdenamiento==1)
            {
                ordenarMotos(motos,TAM_MOTOS,0);
                mostrarMotos(motos,TAM_MOTOS,colores,TAM_COLOR,tipos,TAM_TIPO,clientes,TAM_CLIENTES);
            }
            else
            {
                ordenarMotos(motos,TAM_MOTOS,1);
                mostrarMotos(motos,TAM_MOTOS,colores,TAM_COLOR,tipos,TAM_TIPO,clientes,TAM_CLIENTES);
            }
            break;
        case 5:
            mostrarTipos(tipos,TAM_TIPO);
            break;
        case 6:
            mostrarColores(colores, TAM_COLOR);
            break;
        case 7:
            mostrarServicios(servicios, TAM_SERVICIO);
            break;
        case 8:
            altaTrabajo(motos,TAM_MOTOS,colores,TAM_COLOR,tipos,TAM_TIPO,trabajos,TAM_TRABAJOS,idTrabajo,servicios,TAM_SERVICIO,clientes,TAM_CLIENTES);
            break;
        case 9:
            mostrarTrabajos(trabajos,TAM_TRABAJOS,servicios,TAM_SERVICIO);
            break;
        case 10:
            hardcodearMotos(motos,TAM_MOTOS,10,idMotos);
            break;
        case 11:
            hardcodearTrabajos(trabajos,TAM_TRABAJOS,10,idTrabajo);
            break;
        case 12:
            switch(MenuInformes())
            {
            case 1:
                mostrarMotoPorColor(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR,clientes,TAM_CLIENTES);
                break;
            case 2:
                mostrarPromedioPorTipo(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR);
                break;
            case 3:
                mostrarMotosConMayorCilindrada(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR,clientes,TAM_CLIENTES);
                break;
            case 4:
                mostrarMotoSeparadoPorTipo(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR,clientes, TAM_CLIENTES);
                break;
            case 5:
                contadorMotosPorColorTipo(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR);
                break;
            case 6:
                printf("\nFALTA TERMINAR EL 6\n");
                break;
            case 7:
                mostrarTrabajosDeMoto(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR,trabajos,TAM_TRABAJOS,servicios,TAM_SERVICIO,clientes,TAM_CLIENTES);
                break;
            case 8:
                mostrarImportePorServicioDeMoto(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR,trabajos,TAM_TRABAJOS,servicios,TAM_SERVICIO,clientes,TAM_CLIENTES);
                break;
            case 9:
                mostrarMotoPorServicio(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR,trabajos,TAM_TRABAJOS,servicios,TAM_SERVICIO);
                break;
            case 10:
                mostrarServiciosPorFecha(motos,TAM_MOTOS,tipos,TAM_TIPO,colores,TAM_COLOR,trabajos,TAM_TRABAJOS,servicios,TAM_SERVICIO);
                break;
            }
            break;
        case 13:
            seguirInicial=1;
            break;
        }
        system("pause");
    }
    while(seguirInicial==0);

    return 0;
}
