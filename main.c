/******************************************************************************


*Programa: Segundo Parcial Laboratorio.
*
*
*
*Autor: Lucio Andres Gonzalez.
*Curso,Division: 1C
*


*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Vuelos.h"
#include "parser.h"
#include "ShowData.h"
#include "Functions.h"
#include "UtnGenericFunctions.h"
#include "Pilotos.h"


int main()
{
    int option;                                 //Value of the chosen menu option.
    LinkedList* pArraListVuelos=NULL;                //List of employees.
    LinkedList* pArrayListPilotos=NULL;                  //Sublist of employees.
    int r=0;                                    //Value of return.
    int flagOption=0;                           //Determine what options the program passed through.
    int flagLoad=-1;                             //Determine what files was load.

    pArraListVuelos=ll_newLinkedList();
    pArrayListPilotos=ll_newLinkedList();

    do
    {
        showMenu();
        option=getInt(option,"Elija una opcion: ","Incorrecto, Ingrese el numero de la opcion que desea: ",0,9);
        flagOption=controller_Gonzalez_option(pArraListVuelos);

        switch(option)
        {
            case 1:
                if(flagLoad==-1)
                {
                    r=controller_Gonzalez_loadPilotos(pArrayListPilotos);
                    r=controller_Gonzalez_loadFromText(pArraListVuelos);
                    cargarpiloto(pArrayListPilotos);
                    flagLoad=r;
                    verifyReturn("Carga completada.\n","Error en la carga\n",r);
                }
                else
                {
                    printf("Ya cargo un archivo.\n");
                }
            break;
            case 2:
                if(flagOption==0)
                {
                    r=controller_Gonzalez_List(pArraListVuelos,pArrayListPilotos);
                    verifyReturn("Listado con exito.\n","Error al listar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar el archivo.\n");
                }
            break;
            case 3:
                if(flagOption==0)
                {
                    controller_Gonzalez_cantPasajeros(pArraListVuelos);
                    verifyReturn("Listado con exito.\n","Error al listar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar el archivo.\n");
                }
            break;
            case 4:
                if(flagOption==0)
                {
                    controller_Gonzalez_cantPasajerosIrlanda(pArraListVuelos);
                    verifyReturn("Listado con exito.\n","Error al listar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 5:
                if(flagOption==0)
                {
                    controller_Gonzalez_vuelosCortos(pArraListVuelos);
                    verifyReturn("Generado con exito.\n","Error en al generar el archivo.\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 6:
                if(flagOption==0)
                {
                    controller_Gonzalez_ListPortugal(pArraListVuelos,pArrayListPilotos);
                    verifyReturn("Listado con exito.\n","Error al listar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 7:
                if(flagOption==0)
                {
                    controller_Gonzalez_Filtrar(pArraListVuelos,pArrayListPilotos);
                    verifyReturn("Listado con exito.\n","Error al listar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
            case 8:
                if(flagOption==0)
                {
                    controller_Gonzalez_FiltrarNombre(pArraListVuelos,pArrayListPilotos);
                    verifyReturn("Listado con exito.\n","Error al listar\n",r);
                }
                else
                {
                    printf("Para ingresar a esta opcion primero debe cargar al menos un empleado.\n");
                }
            break;
        }

    system("pause");
    system("cls");

    }while(option!=9);

    ll_deleteLinkedList(pArrayListPilotos);
    ll_deleteLinkedList(pArraListVuelos);

    return 0;
}
