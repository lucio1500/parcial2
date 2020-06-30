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


/** \brief Vuelo Builder.
 *
 * \return Vuelo* Vuelo created.
 *
 */
Vuelo* vuelo_new()
{
    Vuelo* pVuelo;

    pVuelo = (Vuelo*) calloc(sizeof(Vuelo),1);

    return pVuelo;
}


/** \brief Vuelo Builder with parameters
 *
 * \param idVueloStr char*
 * \param idAvionStr char*
 * \param idPilotoStr char*
 * \param fechaStr char*
 * \param destinoStr char*
 * \param cantPasajerosStr char*
 * \param horaDespegueStr char*
 * \param horaLlegadaStr char*
 * \return Vuelo*
 *
 */
Vuelo* vuelo_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr)
{
    Vuelo* pVuelo = vuelo_new();

    if(pVuelo!=NULL && idVueloStr!=NULL && idAvionStr!=NULL && idPilotoStr!=NULL && fechaStr!=NULL && destinoStr!=NULL && cantPasajerosStr!=NULL && horaDespegueStr!=NULL && horaLlegadaStr!=NULL)
    {
        vuelo_setIdVuelo(pVuelo,atoi(idVueloStr));
        vuelo_setIdAvion(pVuelo,atoi(idAvionStr));
        vuelo_setIdPiloto(pVuelo,atoi(idPilotoStr));
        vuelo_setFecha(pVuelo,fechaStr);
        vuelo_setDestino(pVuelo,destinoStr);
        vuelo_setCantPasajeros(pVuelo,atoi(cantPasajerosStr));
        vuelo_setHoraDespegue(pVuelo,atoi(horaDespegueStr));
        vuelo_setHoraLlegada(pVuelo,atoi(horaLlegadaStr));
    }

    return pVuelo;
}


/** \brief Delete an Vuelo in memory.
 *
 * \param this Vuelo*
 * \return void
 *
 */
void vuelo_delete(Vuelo* this)
{
    if(this!=NULL)
    {
        free(this);
        this=NULL;
    }
}


/** \brief Set a idVuelo in an Vuelo.
 *
 * \param this Vuelo*
 * \param id int
 * \return int Return (0) if Ok.
 *
 */
int vuelo_setIdVuelo(Vuelo* this,int idVuelo)
{
    int r;

    if(this!=NULL)
    {
        this->idVuelo=idVuelo;
        r=1;
    }

    return r;
}


/** \brief Get a idVuelo from an Vuelo.
 *
 * \param this Vuelo*
 * \param id int*
 * \return int Return (0) if Ok.
 *
 */
int vuelo_getIdVuelo(Vuelo* this,int* idVuelo)
{
    int r;

    if(this!=NULL && idVuelo!=NULL)
    {
        *idVuelo=this->idVuelo;
        r=1;
    }

    return r;
}


/** \brief Set a idAvion in an Vuelo.
 *
 * \param this Vuelo*
 * \param id int
 * \return int Return (0) if Ok.
 *
 */
int vuelo_setIdAvion(Vuelo* this,int idAvion)
{
    int r;

    if(this!=NULL)
    {
        this->idAvion=idAvion;
        r=1;
    }

    return r;
}


/** \brief Get a idAvion from an Vuelo.
 *
 * \param this Vuelo*
 * \param id int*
 * \return int Return (0) if Ok.
 *
 */
int vuelo_getIdAvion(Vuelo* this,int* idAvion)
{
    int r;

    if(this!=NULL && idAvion!=NULL)
    {
        *idAvion=this->idAvion;
        r=1;
    }

    return r;
}

/** \brief Set a idPiloto in an Vuelo.
 *
 * \param this Vuelo*
 * \param id int
 * \return int Return (0) if Ok.
 *
 */
int vuelo_setIdPiloto(Vuelo* this,int idPiloto)
{
    int r;

    if(this!=NULL)
    {
        this->idPiloto=idPiloto;
        r=1;
    }

    return r;
}


/** \brief Get a idPiloto from an Vuelo.
 *
 * \param this Vuelo*
 * \param id int*
 * \return int Return (0) if Ok.
 *
 */
int vuelo_getIdPiloto(Vuelo* this,int* idPiloto)
{
    int r;

    if(this!=NULL && idPiloto!=NULL)
    {
        *idPiloto=this->idPiloto;
        r=1;
    }

    return r;
}


/** \brief Set a fecha in an Vuelo.
 *
 * \param this Vuelo*
 * \param fecha char*
 * \return int Return (1) if Ok.
 *
 */
int vuelo_setFecha(Vuelo* this,char* fecha)
{
    int r=0;

    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        r=1;
    }

    return r;
}


/** \brief Get a fecha from an Vuelo.
 *
 * \param this Vuelo*
 * \param fecha char*
 * \return int Return (1) if Ok.
 *
 */
int vuelo_getFecha(Vuelo* this,char* fecha)
{
    int r;

    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        r=1;
    }

    return r;
}

/** \brief Set a destino in an Vuelo.
 *
 * \param this Vuelo*
 * \param destino char*
 * \return int Return (1) if Ok.
 *
 */
int vuelo_setDestino(Vuelo* this,char* destino)
{
    int r=0;

    if(this!=NULL && destino!=NULL)
    {
        strcpy(this->destino,destino);
        r=1;
    }

    return r;
}


/** \brief Get a destino from an Vuelo.
 *
 * \param this Vuelo*
 * \param destino char*
 * \return int Return (1) if Ok.
 *
 */
int vuelo_getDestino(Vuelo* this,char* destino)
{
    int r;

    if(this!=NULL && destino!=NULL)
    {
        strcpy(destino,this->destino);
        r=1;
    }

    return r;
}


/** \brief Set a cantPasajeros in an Vuelo.
 *
 * \param this Vuelo*
 * \param cantPasajeros int
 * \return int Return (1) if Ok.
 *
 */
int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros)
{
    int r;

    if(this!=NULL)
    {
        this->cantPasajeros=cantPasajeros;
        r=1;
    }

    return r;
}


/** \brief Get a cantPasajeros from an Vuelo
 *
 * \param this Vuelo*
 * \param cantPasajeros int*
 * \return int Return (1) if Ok.
 *
 */
int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros)
{
    int r;

    if(this!=NULL && cantPasajeros!=NULL)
    {
        *cantPasajeros=this->cantPasajeros;
        r=1;
    }

    return r;
}

/** \brief Set a horaDespegue in an Vuelo.
 *
 * \param this Vuelo*
 * \param horaDespegue int
 * \return int Return (1) if Ok.
 *
 */
int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue)
{
    int r;

    if(this!=NULL)
    {
        this->horaDespegue=horaDespegue;
        r=1;
    }

    return r;
}


/** \brief Get a horaDespegue from an Vuelo
 *
 * \param this Vuelo*
 * \param horaDespegue int*
 * \return int Return (1) if Ok.
 *
 */
int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue)
{
    int r;

    if(this!=NULL && horaDespegue!=NULL)
    {
        *horaDespegue=this->horaDespegue;
        r=1;
    }

    return r;
}


/** \brief Set a horaLlegada in an Vuelo.
 *
 * \param this Vuelo*
 * \param horaLlegada int
 * \return int Return (1) if Ok.
 *
 */
int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada)
{
    int r;

    if(this!=NULL)
    {
        this->horaLlegada=horaLlegada;
        r=1;
    }

    return r;
}


/** \brief Get a horaLlegada from an Vuelo
 *
 * \param this Vuelo*
 * \param horaLlegada int*
 * \return int Return (1) if Ok.
 *
 */
int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada)
{
    int r;

    if(this!=NULL && horaLlegada!=NULL)
    {
        *horaLlegada=this->horaLlegada;
        r=1;
    }

    return r;
}
