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


/** \brief List an Vuelo.
 *
 * \param pArrayListVuelos LinkedList*
 * \param index int
 * \return int Return (0) if Ok.
 *
 */
int listVuelo(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos,int index)
{
    int r=-1;
    Vuelo* auxVuelo;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[128];
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    Piloto* auxPiloto;
    int id;
    char nombre[128];

    if(pArrayListPilotos!=NULL && pArrayListVuelos!=NULL)
    {
        auxVuelo=ll_get(pArrayListVuelos,index);
        vuelo_getIdVuelo(auxVuelo,&idVuelo);
        vuelo_getIdAvion(auxVuelo,&idAvion);
        vuelo_getIdPiloto(auxVuelo,&idPiloto);
        vuelo_getFecha(auxVuelo,fecha);
        vuelo_getDestino(auxVuelo,destino);
        vuelo_getCantPasajeros(auxVuelo,&cantPasajeros);
        vuelo_getHoraDespegue(auxVuelo,&horaDespegue);
        vuelo_getHoraLlegada(auxVuelo,&horaLlegada);

            for(int i=0;i<ll_len(pArrayListPilotos);i++)
            {
                auxPiloto=ll_get(pArrayListPilotos,i);
                piloto_getId(auxPiloto,&id);
                if(id==idPiloto)
                {
                    r=0;
                    piloto_getNombre(auxPiloto,nombre);
                    break;
                }
            }

        printf("%4d\t\t%5d\t\t%s\t\t%s\t%10s\t\t%d\t\t%d\t%10d\n",idVuelo,idAvion,nombre,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
    }

    return r;
}


/** \brief List an Piloto.
 *
 * \param pArrayListPilotos LinkedList*
 * \param index int
 * \return int Return (0) if Ok.
 *
 */
int listPiloto(LinkedList* pArrayListPilotos,int index)
{
    int r=-1;
    Piloto* auxPiloto;
    int id;
    char nombre[128];

    if(pArrayListPilotos!=NULL)
    {
        auxPiloto=ll_get(pArrayListPilotos,index);
        piloto_getId(auxPiloto,&id);
        piloto_getNombre(auxPiloto,nombre);
        printf("%4d\t\t%s\n",id,nombre);
        r=0;
    }





    return r;
}

/** \brief Check if there are any Vuelos loaded.
 *
 * \param pArrayListVuelos LinkedList*
 * \return int Return (0) if Ok.
 *
 */
int controller_Gonzalez_option(LinkedList* pArrayListVuelos)
{
    int r=1;
    int len;
    len=ll_len(pArrayListVuelos);
    if(len>0)
    {
        r=0;
    }
    return r;
}



/** \brief
 *
 * \param pElement void*
 * \return int Return cantPasajeros
 *
 */
int cantPasajeros(void* pElement)
{
    int r=0;
    Vuelo* pVuelo;

    if(pElement!=NULL)
    {
        pVuelo=(Vuelo*) pElement;
        vuelo_getCantPasajeros(pVuelo,&r);
    }

    return r;
}


/** \brief Filter flights to Portugal.
 *
 * \param pElement void*
 * \return int Return CantPasajeros travel to Ireland.
 *
 */
int filtrarIrlanda(void* pElement)
{
    int r=0;
    char destino[128];
    Vuelo* pVuelo;



    if(pElement!=NULL)
    {
    pVuelo=(Vuelo*) pElement;
    vuelo_getDestino(pVuelo,destino);
        if(strcmp(destino,"Irlanda")==0)
        {
            vuelo_getCantPasajeros(pVuelo,&r);
        }
    }

    return r;
}


/** \brief Filter flights to Portugal.
 *
 * \param pElement void*
 * \return int Return (1) if it is included or (0) if not included.
 *
 */
int filtrarPortugal(void* pElement)
{
    int r=0;
    char destino[128];
    Vuelo* pVuelo;


    if(pElement!=NULL)
    {
    pVuelo=(Vuelo*) pElement;
    vuelo_getDestino(pVuelo,destino);
        if(strcmp(destino,"Portugal")==0)
        {
            r=1;
        }
    }

    return r;
}


/** \brief Filter flights that last less than three hours.
 *
 * \param pElement void*
 * \return int Return (1) if it is included or (0) if not included.
 *
 */
int filtrarVuelosCortos(void* pElement)
{
    int r=0;
    int duracion;
    int horaDespegue;
    int horaLlegada;
    Vuelo* pVuelo;

    if(pElement!=NULL)
    {
    pVuelo=(Vuelo*) pElement;
    vuelo_getHoraDespegue(pVuelo,&horaDespegue);
    vuelo_getHoraLlegada(pVuelo,&horaLlegada);
    duracion=horaLlegada-horaDespegue;
        if(duracion<3)
        {
            r=1;
        }
    }

    return r;
}


/** \brief Filter vuelos excluding a pilot.
 *
 * \param pElement void*
 * \return int Return (1) if it is included or (0) if not included.
 *
 */
int filtrarPiloto(void* pElement)
{
    int r=1;
    int idPiloto;
    Vuelo* pVuelo;


    if(pElement!=NULL)
    {
    pVuelo=(Vuelo*) pElement;
    vuelo_getIdPiloto(pVuelo,&idPiloto);
        if(idPiloto==1)
        {
            r=0;
        }
    }

    return r;
}



/** \brief Filter vuelos excluding a pilot.
 *
 * \param pElement void*
 * \return int Return (1) if it is included or (0) if not included.
 *
 */
int filtrarPilotoNombre(void* pElement,char* nombre)
{
    int r=0;
    char auxNombre[128];
    Piloto* pPiloto;

    if(pElement!=NULL)
    {
    pPiloto=(Piloto*) pElement;
    piloto_getNombre(pPiloto,auxNombre);
        if(strcmp(nombre,auxNombre)!=0)
        {
            r=1;
        }
    }

    return r;
}
