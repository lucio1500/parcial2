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


/** \brief Piloto Builder.
 *
 * \return Piloto* Piloto created.
 *
 */
Piloto* piloto_new()
{
    Piloto* pPiloto;

    pPiloto = (Piloto*) calloc(sizeof(Piloto),1);

    return pPiloto;
}

/** \brief Piloto Builder with parameters
 *
 * \param idStr char*
 * \param fechaStr char*
 * \param horasTrabajadasStr char*
 * \param CantPasajerosStr char*
 * \return Piloto* Piloto created.
 *
 */
Piloto* Piloto_newParametros(char* idStr,char* nombreStr)
{
    Piloto* pPiloto = piloto_new();

    if(pPiloto!=NULL && idStr!=NULL && nombreStr!=NULL)
    {
        piloto_setId(pPiloto,atoi(idStr));
        piloto_setNombre(pPiloto,nombreStr);
    }

    return pPiloto;
}


/** \brief hardcode of Pilotos.
 *
 * \param pArrayList LinkedList*
 * \return int int Return (0) if Ok.
 *
 */
int cargarpiloto(LinkedList* pArrayList)
{
    int r=0;
    Piloto* pPiloto;
    int id[5]={1,2,3,4,5};
    char nombre[5][128]={{"Alex Lifeson"},{"Richard Bach"},{"John Kerry"},{"Erwin Rommel"},{"Stephen Coonts"}};

    for(int i=0;i<5;i++)
    {
        pPiloto=piloto_new();
        pPiloto->id=id[i];
        strcpy(pPiloto->nombre,nombre[i]);
        r=ll_add(pArrayList,pPiloto);
    }

    return r;
}


/** \brief Set a id in an Piloto.
 *
 * \param this Piloto*
 * \param id int
 * \return int Return (0) if Ok.
 *
 */
int piloto_setId(Piloto* this,int id)
{
    int r;

    if(this!=NULL)
    {
        this->id=id;
        r=1;
    }

    return r;
}


/** \brief Get a id from an Piloto.
 *
 * \param this Piloto*
 * \param id int*
 * \return int Return (0) if Ok.
 *
 */
int piloto_getId(Piloto* this,int* id)
{
    int r;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        r=1;
    }

    return r;
}

/** \brief Set a nombre in an Piloto.
 *
 * \param this Piloto*
 * \param nombre char*
 * \return int Return (1) if Ok.
 *
 */
int piloto_setNombre(Piloto* this,char* nombre)
{
    int r=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        r=1;
    }

    return r;
}


/** \brief Get a nombre from an Piloto.
 *
 * \param this Piloto*
 * \param nombre char*
 * \return int Return (1) if Ok.
 *
 */
int piloto_getNombre(Piloto* this,char* nombre)
{
    int r;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        r=1;
    }

    return r;
}
