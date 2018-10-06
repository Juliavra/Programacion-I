#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "TP2headers.h"

#define ELEMENTS 1000   /// ELEMENTS Represents the quantity of employees that can be added


int main()
{
    int menuChoice;     /// Contains value for user selection inside menu
    int addedFirst;     /// addFirst is flag, not to allow any menu option until 1 employee is added (0= Already added / 1=no Adds yet  )
    int modifyId;
    char modifyselected;
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int addOne;                 /// Verifies user wants to Add Employee
    int freespace;              /// se carga el return de obtener espacio libre
    int validationSalary;       /// holds result brought by function called validation salary
    char sectorSelection;       /// holds value from sector
    char auxiliarInput [100];   /// this char is used to get all input from user
    int validationResult;       /// holds result brought by function called
    int indexIs;
    char printSelection;
    float totalPayroll;
    int order;                  /// order selection for Sort of employees
    char orderOption;
    float average;
    int employeesOverAverage;
    char exit;

    Employee employees [ELEMENTS];

    initEmployees(employees, ELEMENTS);

    intro ();

    do
    {
        menuChoice= menu () ;   /// calls menu to the screen

        switch (menuChoice)
        {

        case 1:
        {
            printf("\n\n Desea dar de alta un nuevo Empleado?");
            printf("\n\n\t 1-Si \t\t 2-No  \n\n");
            printf("?");
            addOne=getche ();

            while (addOne<49||addOne>50)
            {
                addOne=getche ();
            }

            if (addOne==49)
            {
                freespace= obtainFreeSpace(employees, ELEMENTS);

                if (freespace !=-1)
                {
                    id= generatesNextId();

                    printf("\n\n\n Legajo: %d", id);

                    printf("\n\n Ingrese el nombre del empleado: ");
                    fflush(stdin);
                    fgets(auxiliarInput, 50, stdin);
                    validationResult= lettersOnly(auxiliarInput);

                    while (validationResult==0)
                    {
                        printf("\n Nombre INVALIDO\n\nIngrese nombre nuevamente: ");
                        fflush(stdin);
                        fgets(auxiliarInput, 50, stdin);
                        validationResult= lettersOnly(auxiliarInput);
                    }

                    chanceCase (auxiliarInput);
                    strcpy (name, auxiliarInput);

                    printf("\n\n Ingrese el apellido del empleado: ");
                    fflush(stdin);
                    fgets(auxiliarInput, 50, stdin);
                    validationResult= lettersOnly(auxiliarInput);

                    while (validationResult==0)
                    {
                        printf("\n Apellido INVALIDO\n\nIngrese apellido nuevamente:");
                        fgets(auxiliarInput, 50, stdin);
                        validationResult= lettersOnly(auxiliarInput);
                    }

                    chanceCase (auxiliarInput);
                    strcpy (lastName, auxiliarInput);

                    printf("\n\n Ingrese el salario del empleado: ");
                    fflush(stdin);
                    fgets(auxiliarInput, 8, stdin);
                    validationSalary= numbersOnly(auxiliarInput);

                    while (validationSalary==0)
                    {
                        printf("\n Salario INVALIDO \n\n Ingrese salario nuevamente: ");
                        fgets (auxiliarInput, 8, stdin);
                        validationSalary= numbersOnly(auxiliarInput);
                    }

                    salary =  atof (auxiliarInput);

                    printf("\n\n Ingrese el sector al que pertenece el empleado: \n");
                    printf("\n 1-Administracion \t 2-Contaduria \t 3-Recursos Humanos \t 4-Sistemas \t \n\n? ");

                    sectorSelection=getche ();

                    while (sectorSelection<49||sectorSelection>52)
                    {
                        printf("\n\n Sector erroneo ");
                        printf("\n\n Ingrese el sector al que pertenece el empleado: ");
                        sectorSelection=getche ();
                    }
                    sector=sectorSelection-48;

                    addedFirst= addEmployee(employees, ELEMENTS, id, name, lastName,salary,sector);
                }///CIERRA FREE SPACE
                else
                {
                    system("cls");
                    printf("\n\n No hay espacio libre para realizar un alta\n\n");
                }

            }

            break;

        }

        case 2:
        {
            system("cls");
            if (addedFirst==0)
            {
                int id;
                int confirmErase;
                int erase;

                printf("\n\n\n Ingrese el Numero de Legajo a eliminar:\n\n");
                scanf("%d", &id);

                indexIs=findEmployeeById(employees, ELEMENTS,id);

                if (indexIs==-1)
                {
                    printf("\nEl legajo no existe");
                }
                else
                {
                    system("cls");
                    tags();
                    printsEmployee(employees,indexIs);

                    printf("\n\n\n Esta seguro que desea eliminar el Legajo %d\n\n",id);
                    printf("\n\t 1-Si \t\t 2-No  \n\n? ");

                    confirmErase=getche();

                    while (confirmErase!=49&&confirmErase!=50)
                    {
                        printf("? ");
                        confirmErase=getche();
                    }

                    if (confirmErase==49)
                    {
                        erase=removeEmployee(employees,ELEMENTS, id);

                        if (erase==0)
                        {
                            printf("\n\n Legajo %d: ha sido eliminado!\n\n", id);
                        }
                    }
                    else
                    {
                        printf("\n\n Ningun Legajo ha sido eliminado!\n\n");
                    }
                }
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

                printf("\n\nIngrese Nro de Legajo: ");
                scanf("%d", &modifyId);

                indexIs=findEmployeeById(employees, ELEMENTS,modifyId);

                if (indexIs==-1)
                {
                    printf("\nEl legajo no existe");
                }
                else
                {
                    system("cls");
                    tags();
                    printsEmployee(employees,indexIs);

                    printf("\n\n\n\nIngrese lo q desea modificar: ");
                    printf("\n\n1-Nombre\t2-Apellido\t3-Salario\t4-Sector\t5-SALIR");
                    printf("\n\n\n? ");
                    modifyselected=getche();

                    switch (modifyselected)
                    {
                    case '1':
                    {
                        printf("\n\ningrese el nuevo Nombre: ");
                        fflush(stdin);
                        fgets(auxiliarInput, 50, stdin);
                        validationResult= lettersOnly(auxiliarInput);

                        while (validationResult==0)
                        {
                            printf("\tIngrese nombre nuevamente: ");
                            fgets(auxiliarInput, 50, stdin);
                            validationResult= lettersOnly(auxiliarInput);
                        }

                        chanceCase (auxiliarInput);
                        strcpy (employees[indexIs].name, auxiliarInput);
                        break;
                    }

                    case '2':
                    {
                        printf("\n\nIngrese el nuevo Apellido: ");
                        fflush(stdin);
                        fgets(auxiliarInput, 50, stdin);
                        validationResult= lettersOnly(auxiliarInput);

                        while (validationResult==0)
                        {
                            printf("\tIngrese apellido nuevamente: ");
                            fgets(auxiliarInput, 50, stdin);
                            validationResult= lettersOnly(auxiliarInput);
                        }

                        chanceCase (auxiliarInput);
                        strcpy (employees[indexIs].lastName, auxiliarInput);
                        break;
                    }
                    case '3':
                    {
                        printf("\nIngrese el nuevo Salario: ");
                        fflush(stdin);
                        fgets(auxiliarInput, 8, stdin);

                        validationSalary= numbersOnly(auxiliarInput);

                        while (validationSalary==0)
                        {
                            printf("\n\n\n salario INVALIDO \n\n Ingrese salario nuevamente: ");
                            fgets (auxiliarInput, 8, stdin);
                            validationSalary= numbersOnly(auxiliarInput);
                        }
                        employees[indexIs].salary=  atof (auxiliarInput);
                        break;
                    }

                    case '4':
                    {
                        int sectorSelection;
                        printf("\ningrese el nuevo Sector");
                        printf("\n 1-Administracion \t 2-Contaduria \t 3-Recursos Humanos \t 4-Sistemas \t \n? ");
                        sectorSelection=getche ();

                        while (sectorSelection<'1'||sectorSelection>'4')
                        {
                            printf("\n\n Sector erroneo ");
                            printf("\n\n Ingrese el sector al que pertenece el empleado: ");
                            sectorSelection=getche ();
                        }

                        employees[indexIs].sector=sectorSelection-48;
                        employees[indexIs].isEmpty=0;
                        break;
                    }

                    case '5':
                    {
                        break;
                    }

                    default :
                    {
                        printf("\n\n\n Ud no esta aqui ;-P ");
                        break;
                    }

                    }
                }
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
                    sortEmployees (employees,ELEMENTS, order);
                    printEmployees (employees, ELEMENTS);
                    break;
                }

                case '2':
                {
                    totalPayroll=salaryTotal (employees, ELEMENTS);
                    printf("\n\nTotal de sueldos: %.2f\n\n",totalPayroll);
                    break;
                }

                case '3':
                {
                    average=salaryAverage(employees, ELEMENTS);

                    printf("\n\nPromedio sueldos: %.2f\n\n",average);

                    break;
                }

                case '4':
                {
                    employeesOverAverage=overAverage(employees, ELEMENTS);

                    printf("\n\nCAntidad de empleados que cobran mas que el promedio: %d\n\n",employeesOverAverage);

                    break;
                }


                default:
                {
                    printf("Tu nunca llegaras aqui ;-P");

                    break;
                }
                }
            }
            break;
        }

        case 5:
        {
            printf("\n\n\n\n UD ELIGIO SALIR.\n\n");
            printf("\n\n Esta seguro que desea SALIR?");
            printf("\n\n 'Y'es \t\t 'N'o  \n\n");
            printf("? ");
            exit=getche ();

            while (exit!='y' && exit!='Y' && exit!='n' && exit!='N' )
            {
                printf("\n\n\t 'Y'es \t\t 'N'o  \n\n");
                printf("? ");
                exit=getche ();
            }

            if (exit=='n' ||exit=='N')
            {
                system("cls");
                menuChoice=1;
            }

            break;
        }

        }

    }
    while (menuChoice!=5);

    return 0; ///MAIN FUNCTION RETURN
}///MAIN FUNCTION CLOSES

