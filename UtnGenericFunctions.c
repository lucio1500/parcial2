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

/** \brief Requesting the entry of a number after validating returns an integer.
 *
 * \param num int
 * \param message[] char
 * \param messageError[] char
 * \param min int
 * \param max int
 * \return int Returns a validated integer.
 *
 */
int getInt(int num,char message[],char messageError[],int min,int max)
{
    char cadena[50];
    int flag=0;
    printf("%s",message);
    flag=getIntAndRange(flag,cadena,num,min,max);
    num=atoi(cadena);

    while(flag==0||flag==1)
    {
    printf("%s",messageError);
    flag=getIntAndRange(flag,cadena,num,min,max);
    num=atoi(cadena);
    }

    num=atoi(cadena);

    return num;
}


/** \brief Validate an integer within a range.
 *
 * \param flag int
 * \param cadena[] char
 * \param num int
 * \param min int
 * \param max int
 * \return int Returns 1 if it is an integer or 2 if it is an integer and is within range.
 *
 */
int getIntAndRange(int flag,char cadena[],int num,int min,int max)
{
    int validate=0;
    fflush(stdin);
    gets(cadena);
    validate=validateNumbersInt(cadena);

    if(validate==1)
    {
    flag=1;
     num=atoi(cadena);
        if(num>=min&&num<=max)
        {
        flag=2;
        return flag;
        }
    }

    return flag;

}


/** \brief Request the entry of a number after validating returns a floating number.
 *
 * \param num float
 * \param message[] char
 * \param messageError[] char
 * \param min float
 * \param max float
 * \return float Returns the validated floating number.
 *
 */
float getFloat(float num,char message[],char messageError[],float min,float max)
{
    char cadena[50];
    int flag=0;
    printf("%s",message);
    flag=getFloatAndRange(flag,cadena,num,min,max);
    num=atof(cadena);

    while(flag==0||flag==1)
    {
    printf("%s",messageError);
    flag=getFloatAndRange(flag,cadena,num,min,max);
    num=atof(cadena);
    }

    num=atof(cadena);

    return num;
}


/** \brief Validate a floating number within a range.
 *
 * \param flag int
 * \param cadena[] char
 * \param num float
 * \param min float
 * \param max float
 * \return int Returns 1 if it is a floating number or 2 if it is a floating number and it is within the range.
 *
 */
int getFloatAndRange(int flag,char cadena[],float num,float min,float max)
{
    int validate=0;
    fflush(stdin);
    gets(cadena);
    validate=validateNumbersFloat(cadena);

    if(validate==1)
    {
    flag=1;
     num=atoi(cadena);
        if(num>=min&&num<=max)
        {
        flag=2;
        return flag;
        }
    }

    return flag;

}


/** \brief Asks for the input of a string and saves it in a variable.
 *
 * \param dato[] char
 * \param mensaje[] char
 * \return void
 *
 */
void getString(char dato[], char mensaje[])
{
     printf("%s", mensaje);
     fflush(stdin);
     gets(dato);
}


/** \brief asks to enter a string containing only letters.
 *
 * \param array[] char
 * \param message[] char
 * \param messageError[] char
 * \return void
 *
 */
void getStringOfLetters(char array[],char message[],char messageError[])
{
    int validate=0;

    printf("%s",message);
    fflush(stdin);
    gets(array);
    validate=validateStringOfLetters(array);

    while(validate==0)
    {
    printf("%s",messageError);
    fflush(stdin);
    gets(array);
    validate=validateStringOfLetters(array);
    }

}


/** \brief Receives an initialized ID and adds 1.
 *
 * \param id int
 * \return int Return a new id
 *
 */
int generateId(int id)
{
    id++;

    return id;
}


/** \brief Check if the entered string is an integer.
 *
 * \param numero[] char
 * \return int Returns 1 if the string is numeric or 0 (zero) if it is not.
 *
 */
int validateNumbersInt(char numero[])
{
    int i=0;
    if(numero[0]=='-')
    {
        i=1;
    }
    for(; i<strlen(numero); i++)
    {
        if(!(numero[i]>=48 && numero[i]<=57))
        {
            printf("SOLO INGRESA NUMEROS\n");
            return 0;
        }
    }
    return 1;
}


/** \brief Check if the entered string is a floating number.
 *
 * \param numero[] char
 * \return int Returns 1 if the string is numeric or 0 (zero) if it is not.
 *
 */
int validateNumbersFloat(char numero[])
{
    int i=0;
    if(numero[0]=='-')
    {
        i=1;
    }
    for(; i<strlen(numero); i++)
    {

            if(!(numero[i]>=48 && numero[i]<=57 ))
            {
                if(numero[i]!='.'|| numero[i-1]=='.')
                {
                printf("SOLO INGRESA NUMEROS\n");
                return 0;
                }

            }
    }
    return 1;
}


/** \brief Verify that the string contains only letter or spaces.
 *
 * \param array[] char
 * \return int Returns 1 if the string contains only letters or 0 (zero).
 *
 */
int validateStringOfLetters(char array[])
{
    int i;
    for(i=0 ; i<strlen(array); i++)
    {
        if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
        {
            if(array[i]!=' ' || array[i-1]==' ')
            {
            printf("SOLO INGRESA LETRAS O CON MAXIMO UN ESPACIO ENTRE ELLAS\n");
            return 0;
            }
        }
    }
    return 1;
}


/** \brief Verify the value of return and show a message.
 *
 * \param message char*
 * \param messageError char*
 * \param r int
 * \return void
 *
 */
void verifyReturn(char* message,char* messageError,int r)
{
    if(r==0)
    {
        printf("%s",message);
    }
    else
    {
        printf("%s",messageError);
    }
}
