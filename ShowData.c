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


/** \brief Shows the program options menu.
 *
 * \param void
 * \return void
 *
 */
void showMenu(void)
{
    printf("\n1. Cargar archivo.\n");
    printf("2. Imprimir vuelos.\n");
    printf("3. Cantidad de pasajeros.\n");
    printf("4. Cantidad de pasajeros a Irlanda.\n");
    printf("5. Filtrar vuelos cortos.\n");
    printf("6. Listar vuelos a Portugal.\n");
    printf("7. Filtrar a Alex Lifeson.\n");
    printf("8. Filtrar por piloto.\n");
    printf("9. Salir.\n");
}



