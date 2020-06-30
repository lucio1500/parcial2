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


/** \brief Read the vuelo data from the data.csv file (text mode).
 *
 * \param pFile FILE*
 * \param pArrayListVuelos LinkedList*
 * \return int Return the id of last Employee.
 *
 */
int parser_VueloFromText(FILE* pFile, LinkedList* pArrayListVuelos)
{
    int r;
    char idVuelo[128];
    char idAvion[128];
    char idPiloto[128];
    char fecha[128];
    char destino[128];
    char cantPasajeros[128];
    char horaDespegue[128];
    char horaLlegada[128];

    Vuelo* pVuelo;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        pVuelo=vuelo_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
        r=ll_add(pArrayListVuelos,pVuelo);
    }

    return r;
}





/** \brief Read the vuelo data from the data.csv file (text mode).
 *
 * \param pFile FILE*
 * \param pArrayListPilotos LinkedList*
 * \return int Return the id of last Employee.
 *
 */
int parser_PilotoFromText(FILE* pFile, LinkedList* pArrayListPilotos)
{
    int r;
    char id[128];
    char nombre[128];

    Piloto* pPiloto;

    fscanf(pFile,"%[^,],%[^\n]\n", id, nombre);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^\n]\n", id, nombre);
        pPiloto=Piloto_newParametros(id,nombre);
        r=ll_add(pArrayListPilotos,pPiloto);
    }

    return r;
}


/** \brief Write the vuelo data in the data.csv file (text mode).
 *
 * \param pFile FILE*
 * \param pArrayListVuelos LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int parser_SaveVueloFromText(FILE* pFile , LinkedList* pArrayListVuelos)
{
    int r=1;
    int i;
    Vuelo* auxVuelo;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[128];
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;


    fprintf(pFile,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");

    for(i=0;i<ll_len(pArrayListVuelos);i++)
    {
        auxVuelo=ll_get(pArrayListVuelos,i);
        vuelo_getIdVuelo(auxVuelo,&idVuelo);
        vuelo_getIdAvion(auxVuelo,&idAvion);
        vuelo_getIdPiloto(auxVuelo,&idPiloto);
        vuelo_getFecha(auxVuelo,fecha);
        vuelo_getDestino(auxVuelo,destino);
        vuelo_getCantPasajeros(auxVuelo,&cantPasajeros);
        vuelo_getHoraDespegue(auxVuelo,&horaDespegue);
        vuelo_getHoraLlegada(auxVuelo,&horaLlegada);

        fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",auxVuelo->idVuelo,auxVuelo->idAvion,auxVuelo->idPiloto,auxVuelo->fecha,auxVuelo->destino,auxVuelo->cantPasajeros,auxVuelo->horaDespegue,auxVuelo->horaLlegada);
        r=0;
    }

    return r;
}
