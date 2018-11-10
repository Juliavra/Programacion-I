#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int mainMenu (void);

int main()
{
    int /*r,*/ mainMenuSelection;
    LinkedList* listaEmpleados = ll_newLinkedList();



    do
    {
        mainMenuSelection=mainMenu();

        switch (mainMenuSelection)
        {

        case 1:
        {
            ///system("cls");
            printf("opt %d", mainMenuSelection);
            controller_loadFromText("data.csv",listaEmpleados);
            system("pause");
            break;
        }
        case 2:
        {printf("opt %d", mainMenuSelection);
            controller_loadFromBinary("data.bin",listaEmpleados);
            break;
        }
        case 3:
        {printf("opt %d", mainMenuSelection);
            controller_addEmployee(listaEmpleados);
            break;
        }
        case 4:
        {printf("opt %d", mainMenuSelection);
            controller_editEmployee(listaEmpleados);
            break;
        }
        case 5:
        {printf("opt %d", mainMenuSelection);
            controller_removeEmployee(listaEmpleados);
            break;
        }
        case 6:
        {printf("opt %d", mainMenuSelection);
            ///system("cls");
            controller_ListEmployee(listaEmpleados);
            break;
        }
        case 7:
        {printf("opt %d", mainMenuSelection);
            controller_sortEmployee(listaEmpleados);
            break;
        }
        case 8:
        {printf("opt %d", mainMenuSelection);
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        }
        case 9:
        {printf("opt %d", mainMenuSelection);
            controller_saveAsBinary("data.bin",listaEmpleados);
            break;
        }
        case 10:
        {printf("opt %d", mainMenuSelection);
            printf("Ud Eligio Salir");
            system("pause");
            break;
        }
        }
    }
    while (mainMenuSelection!=10);







    /* do{
         switch(option)
         {
             case 1:
                 controller_loadFromText("data.csv",listaEmpleados);
                 break;
         }
     }while(option != 10);
    */
    return 0;

}
///*******************************************************************************************************************************************************************
///*******************************************************************************************************************************************************************
///BORRAR LUEGO         BORRAR LUEGO       BORRAR LUEGO     BORRAR LUEGO     BORRAR LUEGO    BORRAR LUEGO       BORRAR LUEGO        BORRAR LUEGO

/*
int abreArchivo(void)
{

    char txtleido [50];
    int longitud, cant;
    FILE *parch;

    if((parch=fopen("prueba.txt","rb"))==NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
    else
    {
       fgets(txtleido, 20, parch);

printf("\ntxtleido: %s\n", txtleido);

        longitud=strlen (texto );
        cant=fwrite ( texto , sizeof ( char ) , longitud , parch ); //Se escribe al archivo

    }
    fclose(parch);
    return 0;
}
*/

int mainMenu (void)
{
    char menuChoice;
    int usersChoice;

    do
    {
       /// system("cls");
        printf("\t\t\t\tMENU PRINCIPAL\n\n\n");

        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
        printf("10. Salir\n\n");
        printf("Que es lo que desea hacer? ");

        menuChoice= getche();

        switch (menuChoice)
        {

        case '1':
        {
            usersChoice=1;
            break;
        }

        case '2':
        {
            usersChoice=2;
            break;
        }

        case '3':
        {
            usersChoice=3;
            break;
        }

        case '4':
        {
            usersChoice=4;
            break;
        }
        case '5':
        {
            usersChoice=5;
            break;
        }
        case '6':
        {
            usersChoice=6;
            break;
        }
        case '7':
        {
            usersChoice=7;
            break;
        }
        case '8':
        {
            usersChoice=8;
            break;
        }
        case '9':
        {
            usersChoice=9;
            break;
        }
        case 'S':
        {
            usersChoice=10;
            break;
        }
        default :
        {
            break;
        }

        }

    }
    while (usersChoice<1 || usersChoice>10);

    return usersChoice;
}

///**************************************************************************************************
