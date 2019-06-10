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
    ///int mainMenuSelection, isTxtLoaded=0, isBinLoaded=0;
    int isTxtLoaded=0, isBinLoaded=0;
    char mainMenuSelection;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        /// system("cls");
        // mainMenuSelection=mainMenu();

                 system("cls");
        printf("\t\t\t\tMENU PRINCIPAL\tJULIAN\n\n\n");

        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
        printf("S. Salir\n\n");
        printf("Que es lo que desea hacer? ");


        mainMenuSelection=getche();

        switch (mainMenuSelection)
        {
        case '1':
        {

            if (isTxtLoaded==0 && isBinLoaded!=1)
            {
                controller_loadFromText("data.csv",listaEmpleados);
                isTxtLoaded=1;
            }
            else
            {
                printf("\n\nYa se han cargado los datos anteriormente\n\n");
            }
            system("pause");
            break;
        }
        case '2':
        {
            if (isTxtLoaded!=1 && isBinLoaded==0)
            {
                controller_loadFromBinary("data.bin",listaEmpleados);
                isBinLoaded=1;
            }
            else
            {
                printf("\n\nYa se han cargado los datos anteriormente\n\n");
            }
            system("pause");
            break;
        }
        case '3':
        {
            if(isTxtLoaded == 1 || isBinLoaded == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '4':
        {
            if(isTxtLoaded == 1 || isBinLoaded == 1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '5':
        {
            if(isTxtLoaded == 1 || isBinLoaded == 1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '6':
        {
            if(isTxtLoaded == 1 || isBinLoaded == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '7':
        {
            if(isTxtLoaded == 1 || isBinLoaded == 1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }
            system("pause");
            break;
        }
        case '8':
        {
             if(isTxtLoaded == 1 || isBinLoaded == 1)
             {
                    controller_saveAsText("data.csv",listaEmpleados);
             }
             else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }

            system("pause");
            break;
        }
        case '9':
        {
                         if(isTxtLoaded == 1 || isBinLoaded == 1)
             {
                    controller_saveAsBinary("data.bin",listaEmpleados);
             }
             else
            {
                printf("\n\nNo se han cargado datos aun. Debes cargar un archivo primero.\n\n\n\n");
            }

            system("pause");
            break;
        }
        case 's':
        {
            printf("\n\nUd Eligio Salir\n\n");
            system("pause");
            break;
        }
        case 'S':
        {
            printf("\n\nUd Eligio Salir\n\n");
            system("pause");
            break;
        }
        default:
        {
            break;
        }
        }
    }
    while (mainMenuSelection!='s' && mainMenuSelection!='S');

    return 0;

}
///*******************************************************************************************************************************************************************
///*******************************************************************************************************************************************************************

//
//int mainMenu (void)
//{
//    char menuChoice;
//    int usersChoice;
//
//    do
//    {
//         system("cls");
//        printf("\t\t\t\tMENU PRINCIPAL\tJULIAN\n\n\n");
//
//        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
//        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
//        printf("3. Alta de empleado\n");
//        printf("4. Modificar datos de empleado\n");
//        printf("5. Baja de empleado\n");
//        printf("6. Listar empleados\n");
//        printf("7. Ordenar empleados\n");
//        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
//        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
//        printf("S. Salir\n\n");
//        printf("Que es lo que desea hacer? ");
//
//        menuChoice= getche();
//
//        switch (menuChoice)
//        {
//
//        case '1':
//        {
//            usersChoice=1;
//            break;
//        }
//
//        case '2':
//        {
//            usersChoice=2;
//            break;
//        }
//
//        case '3':
//        {
//            usersChoice=3;
//            break;
//        }
//
//        case '4':
//        {
//            usersChoice=4;
//            break;
//        }
//        case '5':
//        {
//            usersChoice=5;
//            break;
//        }
//        case '6':
//        {
//            usersChoice=6;
//            break;
//        }
//        case '7':
//        {
//            usersChoice=7;
//            break;
//        }
//        case '8':
//        {
//            usersChoice=8;
//            break;
//        }
//        case '9':
//        {
//            usersChoice=9;
//            break;
//        }
//        case 'S':
//        {
//            usersChoice=10;
//            break;
//        }
//        case 's':
//        {
//            usersChoice=10;
//            break;
//        }
//        default :
//        {
//            break;
//        }
//
//        }
//    }
//    while (usersChoice<1 || usersChoice>10);
//
//    return usersChoice;
//}
//
/////**************************************************************************************************
