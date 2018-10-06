#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "TP2headers.h"

/** \brief Initializes all position in the ArrayEmployees to Empty.
 *isEmpty=0 FALSE (POSITION TAKEN) / isEmpty=1  TRUE (EMPTY ARRAY POSITION)
 * \param Employee list [], Pointer to Array of employees
 * \param len int length of the Array of employees
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(Employee list [], int len)
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
* \param Employee *list: Pointer to Array of employees
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

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
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
 * \param Employee *list: Pointer to Array of employees
 * \param len int: length of the Array of employees
 * \param id int: Unique identifier for each employee
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */


    int findEmployeeById(Employee* list, int len,int id)
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


    /** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
 * \param Employee *list: Pointer to Array of employees
 * \param len int: length of the Array of employees
 * \param id int: Unique identifier for each employee
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

    int removeEmployee(Employee* list, int len, int id)

    {
        int index=-1;

        index= findEmployeeById(list, len,id);
        if (index==-1)
        {
            return -1;
        }
        else
        {
            list[index].isEmpty=1;
            return 0;
        }
    }


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param Employee *list: Pointer to Array of employees
* \param len int: length of the Array of employees
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

  int sortEmployees (Employee* list, int len, int order)
    {
        int rtn = -1;
        Employee auxEmployees;

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
 * \param Employee *list: Pointer to Array of employees
 * \param len int: length of the Array of employees
 * \return int to verify correct output
 *
 */

  int printEmployees (Employee *list, int len)
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
 * \param Employee *list: Pointer to Array of employees
 * \param i int: index of the employee to be printed
 * \return int to verify correct output
 *
 */

int printsEmployee (Employee *employees, int i)
    {
        printf("\n\n  %d", employees[i].id);
        printf("\t%s\t", employees[i].name);
        printf("%s\t", employees[i].lastName);
        printf("\t%.2f\t", employees[i].salary);
        printf("\t%d\t", employees[i].sector);

        return 1;
    }


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
        printf("\n\n\n\n\n");
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
            default :
            {
                break;
            }

            }

        }
        while (usersChoice<1 || usersChoice>5);  ///lo que no quiero

        return usersChoice;
    }





/** \brief Returns the first free index in the employees array
*
* \param Employee *list: Pointer to Array of employees
* \param ELEMENTS int: length of the Array of employees
*\return rtn int returns first free position in the employees array
*
*/

    int obtainFreeSpace (Employee *employees, int ELEMENTS)
    {
        int i;
        int rtn = -1;

        for(i=0; i<ELEMENTS; i++)
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
 * \param Employee *list: Pointer to Array of employees
 * \param ELEMENTS int: length of the Array of employees
 * \return overAverage int Total amount of employees above average salary
 *
 */

int overAverage(Employee *employees, int ELEMENTS)
    {
        float totalPayroll=0;
        int accumulatesEmployees=0;
        int overAverage=0;
        float salaryAverage;

        for (int i=0; i<ELEMENTS; i++)
        {
            if (employees[i].isEmpty==0)
            {
                totalPayroll=totalPayroll+employees[i].salary;
                accumulatesEmployees=accumulatesEmployees+1;
                salaryAverage=totalPayroll/accumulatesEmployees;

            }
        }

        for (int i=0; i<ELEMENTS; i++)
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
 * \param Employee *list: Pointer to Array of employees
 * \param ELEMENTS int: length of the Array of employees
 * \return salaryAverage float salary average
 *
 */

    float salaryAverage(Employee *employees, int ELEMENTS)
    {
        float totalPayroll=0;
        int accumulatesEmployees=0;
        int employeesOverAverage=0;
        float salaryAverage;

        for (int i=0; i<ELEMENTS; i++)
        {
            if (employees[i].isEmpty==0)
            {
                totalPayroll=totalPayroll+employees[i].salary;
                accumulatesEmployees=accumulatesEmployees+1;
                salaryAverage=totalPayroll/accumulatesEmployees;

            }
        }

        for (int i=0; i<ELEMENTS; i++)
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
 * \param Employee *list: Pointer to Array of employees
 * \param ELEMENTS int: length of the Array of employees
 * \return totalPayroll float total salary amount
 *
 */

float salaryTotal (Employee *employees, int ELEMENTS)
    {
        float totalPayroll=0;

        for (int i=0; i<ELEMENTS; i++)
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







