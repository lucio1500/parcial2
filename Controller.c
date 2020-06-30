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


/** \brief Load Vuelo data from data.csv file (text mode),
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int Return the id of last Vuelo.
 *
 */
int controller_Gonzalez_loadFromText(LinkedList* pArrayListVuelos)
{
    int r=-1;
    char path[128];
    FILE* pFile;

    getString(path,"Ingrese el nombre del archivo que desea abrir: ");

    if(path!=NULL && pArrayListVuelos!=NULL)
    {
        pFile = fopen (path, "r");
            if(pFile!=NULL)
            {
                r=parser_VueloFromText(pFile,pArrayListVuelos);
            }
        fclose(pFile);
    }

    return r;

}


/** \brief Load Vuelo data from data.csv file (text mode),
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int Return the id of last Vuelo.
 *
 */
int controller_Gonzalez_loadPilotos(LinkedList* pArrayListPilotos)
{
    int r=-1;
    char path[128];
    FILE* pFile;

    if(path!=NULL && pArrayListPilotos!=NULL)
    {
        pFile = fopen ("Pilotos.csv", "r");
            if(pFile!=NULL)
            {
                r=parser_PilotoFromText(pFile,pArrayListPilotos);
            }
        fclose(pFile);
    }

    return r;

}


/** \brief List Vuelos.
 *
 * \param pArrayListVuelos LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_Gonzalez_List(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int r=-1;
    int i;

    printf("\nIdVUELO\t\tIdAVION\t\tIdPILOTO\t\tFECHA\t\tDESTINO\t\tCantPASAJEROS\tHoraDESPESGUE\tHoraLLEGADA\n");

    for(i=0;i<ll_len(pArrayListVuelos);i++)
    {
        r=listVuelo(pArrayListVuelos,pArrayListPilotos,i);
    }
    printf("\nIdVUELO\t\tIdAVION\t\tIdPILOTO\t\tFECHA\t\tDESTINO\t\tCantPASAJEROS\tHoraDESPESGUE\tHoraLLEGADA\n");

    return r;
}

/** \brief List Vuelos.
 *
 * \param pArrayListVuelos LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_Gonzalez_ListPiloto(LinkedList* pArrayListPilotos)
{
    int r=-1;
    int i;

    printf("\nIdVUELO\t\tNOMBRE\n");

    for(i=0;i<ll_len(pArrayListPilotos);i++)
    {
        r=listPiloto(pArrayListPilotos,i);
    }
    printf("\nIdVUELO\t\tNOMBRE\n");

    return r;
}


/** \brief Shows the total number of passengers.
 *
 * \param pArrayListVuelos LinkedList*
 * \return int Return total.
 *
 */
int controller_Gonzalez_cantPasajeros(LinkedList* pArrayListVuelos)
{
    int total=0;

    total=ll_count(pArrayListVuelos,cantPasajeros);

    printf("Total: %d\n",total);

    return total;
}


/** \brief Shows the total number of passengers going to Ireland.
 *
 * \param pArrayListVuelos LinkedList*
 * \return int Return total.
 *
 */
int controller_Gonzalez_cantPasajerosIrlanda(LinkedList* pArrayListVuelos)
{
    int total=0;

    total=ll_count(pArrayListVuelos,filtrarIrlanda);

    printf("Total a irlanda: %d\n",total);

    return total;
}


/** \brief Shows flights to Portugal.
 *
 * \param pArrayListVuelos LinkedList*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int controller_Gonzalez_ListPortugal(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int r=-1;
    int i;
    LinkedList* pArrayFilter = ll_newLinkedList();

    pArrayFilter=ll_filter(pArrayListVuelos,filtrarPortugal);

    for(i=0;i<ll_len(pArrayFilter);i++)
    {
        r=listVuelo(pArrayFilter,pArrayListPilotos,i);
    }

    return r;
}


/** \brief Generate a file with flights lasting less than 3 hours.
 *
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int controller_Gonzalez_vuelosCortos(LinkedList* pArrayListVuelos)
{
    int r=-1;
    FILE* pFile;
    LinkedList* pArrayFilter = ll_newLinkedList();

    if(pArrayListVuelos!=NULL)
    {
    pArrayFilter=ll_filter(pArrayListVuelos,filtrarVuelosCortos);

        pFile = fopen ("VuelosCortos.csv", "w");
            if(pFile!=NULL)
            {
                r=parser_SaveVueloFromText(pFile,pArrayFilter);
            }
        fclose(pFile);
    }

    return r;
}


/** \brief Shows flights excluding a pilot.
 *
 * \param pArrayListVuelos LinkedList*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int controller_Gonzalez_Filtrar(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int r=-1;
    LinkedList* pArrayFilter = ll_newLinkedList();

    if(pArrayListVuelos!=NULL && pArrayListPilotos!=NULL)
    {
    pArrayFilter=ll_filter(pArrayListVuelos,filtrarPiloto);
        for(int i=0;i<ll_len(pArrayFilter);i++)
        {
            r=listVuelo(pArrayFilter,pArrayListPilotos,i);
        }
    }

    return r;
}

/** \brief Shows flights excluding a pilot.
 *
 * \param pArrayListVuelos LinkedList*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int controller_Gonzalez_FiltrarNombre(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int r=-1;
    char nombre[128];
    char auxNombre[128];
    Piloto* pPiloto;
    LinkedList* pArrayFilter = ll_newLinkedList();

    if(pArrayListVuelos!=NULL && pArrayListPilotos!=NULL)
    {

    controller_Gonzalez_ListPiloto(pArrayListPilotos);
    getStringOfLetters(auxNombre,"Ingrese el nombre del Piloto por el que desea filtrar la lista: ","Error, reingrese un nombre sin numeros o con maximo un espacio: ");
    pArrayFilter=ll_filter_parametro(pArrayListPilotos,filtrarPilotoNombre,auxNombre);
    //controller_Gonzalez_vuelosFiltrados(pArrayFilter);
    r=controller_Gonzalez_ListPiloto(pArrayFilter);
    }

    return r;
}


/** \brief Genera una lista con los vuelos filtrados por piloto.
 *
 * \param pArrayListVuelosFiltrados LinkedList*
 * \return int
 *
 */
int controller_Gonzalez_vuelosFiltrados(LinkedList* pArrayListVuelosFiltrados)
{
    int r=-1;
    FILE* pFile;

    if(pArrayListVuelosFiltrados!=NULL)
    {

        pFile = fopen ("VuelosFiltrados.csv", "w");
            if(pFile!=NULL)
            {
                r=parser_SaveVueloFromText(pFile,pArrayListVuelosFiltrados);
            }
        fclose(pFile);
    }

    return r;
}
