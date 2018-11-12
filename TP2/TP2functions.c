#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "TP2headers.h"

/** \brief Initializes all position in the ArrayEmployees to Empty.
 *isEmpty=0 FALSE (POSITION TAKEN) / isEmpty=1  TRUE (EMPTY ARRAY POSITION)
 * \param eEmployee  list [], Pointer to Array of employees
 * \param len int length of the Array of employees
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(eEmployee  list [], int len)
{
    int rtn=-1;
    if (list!=NULL && len >0)
    {
        for (int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        rtn=0;
    }
    return rtn;
}


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param eEmployee  *list: Pointer to Array of employees
* \param len int: length of the Array of employees
* \param id int: Unique identifier for each employee
* \param name[] char: Contains employee name
* \param lastName[] char: Contains employee last name
* \param salary float: Contains employee salary
* \param sector int: Contains employee sector
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int savesEmployee(eEmployee * list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int rtn=-1;
    int freeIndex;

    freeIndex= obtainFreeSpace(list, len);

    if (freeIndex!=-1)
    {
        if (list!=NULL && len >0)
        {
            list[freeIndex].id=id;
            strcpy (list[freeIndex].name, name);
            strcpy (list[freeIndex].lastName,lastName);
            list[freeIndex].salary=salary;
            list[freeIndex].sector=sector;
            list[freeIndex].isEmpty=0;

            rtn=0;
        }
    }
    return rtn;
}

/** \brief find an employee by Id and returns the index position in employees array
 *
 * \param eEmployee  *list: Pointer to Array of employees
 * \param len int: length of the Array of employees
 * \param id int: Unique identifier for each employee
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */


int findEmployeeById(eEmployee * list, int len,int id)
{
    int index=-1;

    for (int i=0; i<len; i++)
    {
        if (list[i].id==id && list[i].isEmpty==0)
        {
            index=i;
            break;
        }

    }
    return index;
}


/** \brief Remove a eEmployee  by Id (put isEmpty Flag in 1)
*
* \param eEmployee  *list: Pointer to Array of employees
* \param len int: length of the Array of employees
* \param id int: Unique identifier for each employee
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int removeEmployee(eEmployee * employees, int EMPLOYEESMAX, eSector* sectors)

{
    int id;
    int confirmErase;
    int indexIs=-1;

    printf("\t\t\t BAJAS\n\n");
    printf("\n\n\n Ingrese el Numero de Legajo a eliminar:\n\n");
    scanf("%d", &id);

    indexIs=findEmployeeById(employees, EMPLOYEESMAX,id);

    if (indexIs==-1)
    {
        printf("\nEl legajo no existe");
    }
    else
    {
        system("cls");
        tags();
        printsEmployee(employees,indexIs, sectors);

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
            employees[indexIs].isEmpty=1;
            printf("\n\n Legajo %d: ha sido eliminado!\n\n", id);
        }
        else
        {
            printf("\n\n Ningun Legajo ha sido eliminado!\n\n");
        }
    }

    return 0;           /// EL RETURN NO SIRVE PA NADA

}///CIERRA FUNCION


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param eEmployee  *list: Pointer to Array of employees
* \param len int: length of the Array of employees
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int sortEmployees (eEmployee* list, int len, int order)
{
    int rtn = -1;
    eEmployee  auxEmployees;

    if (list != NULL && len > 0)
    {
        if(order == 1)
        {
            for(int i =0 ; i<len-1 ; i ++)
            {

                for(int j= i+1 ; j<len; j++)
                {
                    if(strcmp(list[j].lastName,list[i].lastName)<0 && list[j].isEmpty==0 && list[i].isEmpty==0)
                    {
                        auxEmployees = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployees;
                    }
                    else if(strcmp(list[j].lastName,list[i].lastName) ==0 && list[j].isEmpty==0 && list[i].isEmpty==0)
                    {
                        auxEmployees = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployees;
                    }
                }
            }
        }
        else if(order == 0)
        {
            for(int i =0 ; i<len-1 ; i ++)
            {

                for(int j= i+1 ; j<len; j++)
                {
                    if(strcmp(list[j].lastName,list[i].lastName)>0 && list[j].isEmpty==0 && list[i].isEmpty==0)
                    {
                        auxEmployees = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployees;
                    }
                    else if(strcmp(list[j].lastName,list[i].lastName) ==0 && list[j].isEmpty==0 && list[i].isEmpty==0)
                    {
                        auxEmployees = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployees;
                    }
                }
            }
        }
        else
        {
            printf("No hay legajos que ordenar\n");
        }
        rtn = 0;
    }
    return rtn;
}


/** \brief Prints all active employees on screen
 *
 * \param eEmployee  *list: Pointer to Array of employees
 * \param len int: length of the Array of employees
 * \return int to verify correct output
 *
 */

int printEmployees (eEmployee *list, int len)
{

    if (list != NULL && len > 0)
    {

        for (int i=0; i<len; i++)
        {
            if (list[i].isEmpty==0)
            {
                printf("\n\n  %d", list[i].id);
                printf("\t%s\t", list[i].name);
                printf("%s\t", list[i].lastName);
                printf("\t%.2f\t", list[i].salary);
                printf("\t%d\t", list[i].sector);
            }
        }
    }
    else
    {
        printf("No hay empleados que mostrar");
    }

    return 1;
}


/** \brief Prints one employee on screen
 *
 * \param eEmployee  *list: Pointer to Array of employees
 * \param i int: index of the employee to be printed
 * \return int to verify correct output
 *
 */

int printsEmployee (eEmployee *employees, int i, eSector* sectors)
{
    char sectorDescription [20];

    printf("\n\n  %d", employees[i].id);
    printf("\t%s\t", employees[i].name);
    printf("%s\t", employees[i].lastName);
    printf("\t%.2f\t", employees[i].salary);
    printf("\t%d\t", employees[i].sector);

///    sectorDescription= findsSectorDescription (employees, i, sectors);

/*
    for (int j=0;j<5;j++)           ///EN LUGAR DE 5 VA EMPLOYEESMAX
    {

     if (employees[i].sector==sectors[j].id)
    {
        printf("\t%s\t", sectors[j].description);
    }


    }///closes for J
*/
    return 1;
}

/*
    char findsSectorDescription (eEmployee  *employees, int i, eSector* sectors)
  {
      int j;
      char auxSectorDescription[20];

    for (j=0;j<5;j++)           ///EN LUGAR DE 5 VA sectorsmax
    {
      if (employees[i].sector==sectors[j].id)
    {
        printf("\t%s\t", sectors[j].description);
    }
   strcpy(auxSectorDescription, sectors[j].description);

    }
    return auxSectorDescription;
    }///closes for J

*/








/** \brief Prints tags for the columns
 *
 * \param NO parameters are received
 * \return VOID function
 *
 */

void tags (void)
{
    printf("\n\nLegajo\t");
    printf("Name\t");
    printf("lastName\t");
    printf("salary\t");
    printf("\tsector");
}


/** \brief introduction
*
* \param NO parameters are received
* \return VOID function
*
*/

void intro (void)
{
    printf("\t\t\t\tBienvenido al ABM!!");
    printf("\n\n\t\t\t   Hecho por Avramides Julian 1A\n\n");
   /// printf("\n\n\t\t\t   NO gracias al CodeBlocks");
    printf("\n\n\n\n\n");
    system("pause");
}




/** \brief Generates a unique ID identifier for each employee added
*
* \param NO parameters are received
* \return ID is the number of ID an employee will have
*
*/

int generatesNextId()
{
    static int id = 0;
    id ++;
    return id;
}


/** \brief Main Menu
 *
 * \param NO parameters are received
 * \return usersChoice Contains users selection
 *
 */

int menu (void)
{
    char menuChoice;
    int usersChoice;

    do
    {
        printf("\n\n\n");
        printf("1-Alta\t\t");
        printf("2-Baja\t\t");
        printf("3-Modifica\t");
        printf("4-Mostrar\t");
        printf("5-SALIR\n\n");
        printf("6-HarCode\n\n");
        printf("Que es lo que desea hacer? ");

        menuChoice= getche();

        switch (menuChoice)
        {

        case 49:
        {
            usersChoice=1;
            break;
        }

        case 50:
        {
            usersChoice=2;
            break;
        }

        case 51:
        {
            usersChoice=3;
            break;
        }

        case 52:
        {
            usersChoice=4;
            break;
        }
        case 53:
        {
            usersChoice=5;
            break;
        }
        case 54:
        {
            usersChoice=9;
            break;
        }



        default :
        {
            break;
        }

        }

    }
    while (usersChoice<1 || usersChoice>6);  ///lo que no quiero

    return usersChoice;
}





/** \brief Returns the first free index in the employees array
*
* \param eEmployee  *list: Pointer to Array of employees
* \param EMPLOYEESMAX int: length of the Array of employees
*\return rtn int returns first free position in the employees array
*
*/

int obtainFreeSpace (eEmployee *employees, int EMPLOYEESMAX)
{
    int i;
    int rtn = -1;

    for(i=0; i<EMPLOYEESMAX; i++)
    {
        if(employees[i].isEmpty == 1)
        {
            rtn = i;
            break;
        }
    }
    return rtn;
}

/** \brief Calculates how many employees's salary is above average
 *
 * \param eEmployee *list: Pointer to Array of employees
 * \param EMPLOYEESMAX int: length of the Array of employees
 * \return overAverage int Total amount of employees above average salary
 *
 */

int overAverage(eEmployee *employees, int EMPLOYEESMAX)
{
    float totalPayroll=0;
    int accumulatesEmployees=0;
    int overAverage=0;
    float salaryAverage;

    for (int i=0; i<EMPLOYEESMAX; i++)
    {
        if (employees[i].isEmpty==0)
        {
            totalPayroll=totalPayroll+employees[i].salary;
            accumulatesEmployees=accumulatesEmployees+1;
            salaryAverage=totalPayroll/accumulatesEmployees;

        }
    }

    for (int i=0; i<EMPLOYEESMAX; i++)
    {
        if (employees[i].salary>salaryAverage)
        {
            overAverage=overAverage+1;
        }
    }
    return overAverage;
}


/** \brief Calculates  employees's salary average
 *
 * \param eEmployee *list: Pointer to Array of employees
 * \param EMPLOYEESMAX int: length of the Array of employees
 * \return salaryAverage float salary average
 *
 */

float salaryAverage(eEmployee *employees, int EMPLOYEESMAX)
{
    float totalPayroll=0;
    int accumulatesEmployees=0;
    int employeesOverAverage=0;
    float salaryAverage;

    for (int i=0; i<EMPLOYEESMAX; i++)
    {
        if (employees[i].isEmpty==0)
        {
            totalPayroll=totalPayroll+employees[i].salary;
            accumulatesEmployees=accumulatesEmployees+1;
            salaryAverage=totalPayroll/accumulatesEmployees;

        }
    }

    for (int i=0; i<EMPLOYEESMAX; i++)
    {
        if (employees[i].salary>salaryAverage)
        {
            employeesOverAverage=employeesOverAverage+1;
        }
    }
    return salaryAverage;
}



/** \brief Calculates employees's total salary amount
 *
 * \param eEmployee *list: Pointer to Array of employees
 * \param EMPLOYEESMAX int: length of the Array of employees
 * \return totalPayroll float total salary amount
 *
 */

float salaryTotal (eEmployee *employees, int EMPLOYEESMAX)
{
    float totalPayroll=0;

    for (int i=0; i<EMPLOYEESMAX; i++)
    {
        if (employees[i].isEmpty==0)
        {
            totalPayroll=totalPayroll+employees[i].salary;
        }
    }
    return totalPayroll;
}

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



/** \brief validates that input char contains only numbers
 *
 * \param auxiliarInput[] char input user received from main
 * \return numbersOnlyChar int validation result
 *
 */

int numbersOnly (char auxiliarInput[])
{
    int isdigit_result;              /// HOLDS RESULT OF ISALPHA FUNCTION
    int array_length;               ///HOLDS LENGTH OF TEXT ARRAY
    int numbersOnlyChar=1;     ///if=0 INVALID VALUE // IF=1 VALID VALUE

    array_length=strlen (auxiliarInput);
    for (int i=0; i<array_length-1; i++)
    {
        isdigit_result=isdigit(auxiliarInput[i]);

        if (auxiliarInput[i]==46)
        {
            /// Condition used to prevent if(isdigit_result==0)
            /// transform numbersOnlyChar=0 because of a dot
        }

        else if (isdigit_result==0)
        {
            numbersOnlyChar=0;
            break;
        }
    }
    return numbersOnlyChar;         ///if=0 INVALID VALUE // IF=1 VALID VALUE
}



/** \brief changes case to Name Lastname
 *
 * \param auxiliarInput[] char input user received from main
 * \return VOID function
 *
 */

void chanceCase (char auxiliarInput[])
{
    /*   int length;

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
    */
}









int addsEmployee(eEmployee* employees, int EMPLOYEESMAX)

///int addsEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

    int addOne;                           /// Verifies user wants to Add eEmployee
    int indexIs;                      /// se carga el return de obtener espacio libre
    char auxiliarInput [100];
    int validationResult;             /// holds result brought by function called
    int validationSalary;            /// holds result brought by function called validation salary
    char sectorSelection;       /// holds value from sector
    int id;
    float salary;
    int sector;
    ///int savedEmployeeOK;
    int rtn=-1;
    ///int freeIndex;


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
        indexIs= obtainFreeSpace(employees, EMPLOYEESMAX);

        if (indexIs !=-1)
        {
            if (employees!=NULL && EMPLOYEESMAX>0)
            {
                id= generatesNextId();

                printf("\n\n\n Legajo: %d", id);
                employees[indexIs].id=id;

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
                strcpy (employees[indexIs].name, auxiliarInput);

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
                strcpy (employees[indexIs].lastName,auxiliarInput);

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
                employees[indexIs].salary=salary;

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
                printf("\n\n Sector: %d", sector);

                employees[indexIs].sector=sector;
                employees[indexIs].isEmpty=0;
                ///addedFirst= 1;
                rtn=0;
            }///if NULL
        }///CIERRA FREE SPACE
        else
        {
            system("cls");
            printf("\n\n No hay espacio libre para realizar un alta\n\n");
        }

    }///CIERRQA IF ADDONE
    return rtn;
}/// CIERRA FUNCION



int modifyEmployee (eEmployee* employees, int EMPLOYEESMAX, eSector* sectors)
{
    int indexIs;
    int modifyselected;
    char auxiliarInput [100];
    int validationResult;             /// holds result brought by function called
    int validationSalary;
    int modifyId;

    printf("\t\tMODIFICA\n\n ");
    printf("\n\nIngrese Nro de Legajo: ");
    scanf("%d", &modifyId);

    indexIs=findEmployeeById(employees, EMPLOYEESMAX,modifyId);

    if (indexIs==-1)
    {
        printf("\nEl legajo no existe");
    }
    else
    {
        system("cls");
        tags();
        printsEmployee(employees,indexIs, sectors);

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
    return 0;           ///RETURN SIN VALOR
}


void hardCodedEmployees (eEmployee* employees)
{
    eEmployee hcd[]=
    {
        {2, "Aldous", "Huxley", 200, 2, 0},
        {3, "George", "Orwell", 300, 3, 0},
        {4, "Jorge", "Borges", 400, 4, 0},
        {5, "Ray", "Loriga", 500, 1, 0},
        {6, "Ernesto", "Sabato", 600, 1, 0},
        {7, "Carlos", "Chernov", 800, 1, 0},
        {8, "William", "Gibson", 900, 1, 0},

    };
    for(int i=0; i<8; i++)
    {
        employees[i] = hcd[i];
        printf("nombre; %s", employees[i].name);
    }
}
