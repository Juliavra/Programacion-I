#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


/** \brief Quita el salto de linea que toma la funcion fgets
 *
 * \param char *cadena
 * \return sin return
 *
 */
void removeLineFeed(char *text)
{
    if (text[strlen(text)-1]=='\n')
    {
        text[strlen(text)-1]='\0';
    }
}
///**********************************************************************************************************
///**********************************************************************************************************
int numbersOnly (char auxiliarInput[])
{
    int isdigit_result;              /// HOLDS RESULT OF ISDIGIT FUNCTION
    int array_length;               ///HOLDS LENGTH OF TEXT ARRAY
    int numbersOnlyChar=1;     ///if=0 INVALID VALUE // IF=1 VALID VALUE

    array_length=strlen (auxiliarInput);
    for (int i=0; i<array_length-1; i++)
    {
        isdigit_result=isdigit(auxiliarInput[i]);
        if (isdigit_result==0)
        {
            numbersOnlyChar=0;
            break;
        }
    }
    return numbersOnlyChar;         ///if=0 INVALID VALUE // IF=1 VALID VALUE
}


///**********************************************************************************************************
///**********************************************************************************************************
float numbersOnlyFloat (char auxiliarInput[])
{
    int isdigit_result;              /// HOLDS RESULT OF ISDIGIT FUNCTION
    int array_length;               ///HOLDS LENGTH OF TEXT ARRAY
    int numbersOnlyChar=1;     ///if=0 INVALID VALUE // IF=1 VALID VALUE

    array_length=strlen (auxiliarInput);
    for (int i=0; i<array_length-1; i++)
    {
        printf("\nvalor: %c", auxiliarInput[i] );

        isdigit_result=isdigit(auxiliarInput[i]);
        if (isdigit_result==0)
        {
            if (auxiliarInput[i]=='.')
            {printf("engancho punto");
                numbersOnlyChar=0;
                break;
            }
        printf("es numero");
        }
    }
    return numbersOnlyChar;         ///if=0 INVALID VALUE // IF=1 VALID VALUE
}




///***************************************************************************************************************************************
///***************************************************************************************************************************************
/** \brief validates that input char contains only letters
 *
 * \param auxiliarInput[] char input user received from main
 * \return lettersOnly int validation result
 *
 */

int lettersOnly (char auxiliarInput[])
{
    int isalpha_result;              /// HOLDS RESULT OF ISALPHA FUNCTION
    int txt_length;               ///HOLDS LENGTH OF TEXT ARRAY
    int lettersOnly=1;     ///if=0 INVALID VALUE // IF=1 VALID VALUE

    txt_length=strlen (auxiliarInput);

    for (int i=0; i<txt_length-1; i++)
    {
        isalpha_result=isalpha(auxiliarInput[i]);

        if (auxiliarInput[i]==32)
        {
            /// Condition used to prevent if(isalpha_result==0)
            /// to transform lettersOnly=0 because of an empty space
        }
        else if (isalpha_result==0)
        {
            lettersOnly=0;
            break;
        }
        auxiliarInput[txt_length-1]= 00;              ///This instruction is due to the fact of fgets adding an enter char at the end of the array
    }
    return lettersOnly;
}
///**************************************************************************************************************
///**************************************************************************************************************
/** \brief changes case to Name Lastname
 *
 * \param auxiliarInput[] char input user received from main
 * \return VOID function
 *
 */

void chanceCase (char auxiliarInput[])
{
    int length;
    length=strlen (auxiliarInput);
    auxiliarInput=strlwr(auxiliarInput);
    for (int i=0; i<length; i++)
       {
           if (auxiliarInput[i]==32)
           {
               auxiliarInput[i+1]=auxiliarInput[i+1]-32;
           }
       }
       auxiliarInput[0]=auxiliarInput[0]-32;
 }
///**************************************************************************************************************************
///**************************************************************************************************************************
