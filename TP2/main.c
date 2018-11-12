#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "TP2headers.h"

#define EMPLOYEESMAX 3   /// EMPLOYEESMAX Represents the quantity of employees that can be added


int main()
{
    int menuChoice;     /// Contains value for user selection inside menu
    int addedFirst;     /// addFirst is flag, not to allow any menu option until 1 employee is added (0= Already added / 1=no Adds yet  )
    char printSelection;
    float totalPayroll;
    int order;                  /// order selection for Sort of employees
    char orderOption;
    float average;
    int employeesOverAverage;
    char endOfProgram;

    eSector sectors[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    eEmployee employees [EMPLOYEESMAX];

    initEmployees(employees, EMPLOYEESMAX);

     intro ();

    do
    {
        menuChoice= menu () ;   /// calls menu to the screen

        switch (menuChoice)
        {

        case 1:
        {
            addedFirst= addsEmployee(employees, EMPLOYEESMAX);
            break;
        }

        case 2:
        {
            system("cls");
            if (addedFirst==0)
            {
                removeEmployee(employees, EMPLOYEESMAX, sectors);
            }
            else
            {
                printf("\n\n Debes Hacer un alta antes de poder dar de baja un empleado\n\n\n\n");
            }

            break;
        }

        case 3:
        {
            system("cls");

            if (addedFirst!=0)
            {
                printf("\n\n Debes Hacer un alta antes de poder modificar un legajo\n\n\n\n");
            }
            else
            {
                modifyEmployee(employees, EMPLOYEESMAX, sectors);
            }
            break;
        }

        case 4:
        {
            system("cls");
            if (addedFirst!=0)
            {
                printf("\n\n Debes Hacer un alta antes de poder mostrar el listado de empleados\n\n\n\n");
            }
            else
            {
                system("cls");
                printf("\n\n\n");
                printf("\t\t\t Que desea imprimir?\n\n");
                printf("\t1-Empleados activos\t\t");
                printf("2-Total Sueldos\n\n");
                printf("\t3-Promedio Sueldos\t\t");
                printf("4-Empleados sobre el promedio\n\n");
                printf("? ");

                fflush(stdin);
                printSelection=getche ();

                while (printSelection<'1'||printSelection>'4')
                {
                    fflush(stdin);
                    printSelection=getche ();
                }

                switch(printSelection)
                {
                case '1':
                {
                    printf("\n\nDe que forma desea ordenarlos?\n\n");
                    printf("\t1- Ascendente\t\t2-Descendente");
                    printf("\n\n\? ");
                    fflush(stdin);
                    orderOption=getche ();

                    while (orderOption<'1'||orderOption>'2')
                    {
                        fflush(stdin);
                        orderOption=getche ();
                    }
                    switch(orderOption)
                    {
                    case '1':
                    {
                        order=1;
                        break;
                    }
                    case '2':
                    {
                        order=0;
                        break;
                    }
                    }

                    tags ();
                    sortEmployees (employees,EMPLOYEESMAX, order);
                    printEmployees (employees, EMPLOYEESMAX);
                    break;
                }

                case '2':
                {
                    totalPayroll=salaryTotal (employees, EMPLOYEESMAX);
                    printf("\n\nTotal de sueldos: %.2f\n\n",totalPayroll);
                    break;
                }

                case '3':
                {
                    average=salaryAverage(employees, EMPLOYEESMAX);

                    printf("\n\nPromedio sueldos: %.2f\n\n",average);

                    break;
                }

                case '4':
                {
                    employeesOverAverage=overAverage(employees, EMPLOYEESMAX);

                    printf("\n\nCAntidad de empleados que cobran mas que el promedio: %d\n\n",employeesOverAverage);

                    break;
                }

                }
            }
            break;///CASE 4 MOSTRAR
        }

        case 5:
        {
            printf("\n\n\n\n UD ELIGIO SALIR.\n\n");
            printf("\n\n Esta seguro que desea SALIR?");
            printf("\n\n 'Y'es \t\t 'N'o  \n\n");
            printf("? ");
            endOfProgram=getche ();

            while (endOfProgram!='y' && endOfProgram!='Y' && endOfProgram!='n' && endOfProgram!='N' )
            {
                printf("\n\n\t 'Y'es \t\t 'N'o  \n\n");
                printf("? ");
                endOfProgram=getche ();
            }

            if (endOfProgram=='n' ||endOfProgram=='N')
            {
                system("cls");
                menuChoice=1;
            }

            break;
        }

        case 6:
        {
            hardCodedEmployees (employees);
            break;
        }
        }///CLOSES SWITCH

    }
    while (menuChoice!=5);

    return 0; ///MAIN FUNCTION RETURN
}///MAIN FUNCTION CLOSES

