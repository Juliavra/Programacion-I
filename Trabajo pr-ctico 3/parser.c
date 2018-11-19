#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = employee_new();
    int r, i = 0;
    char auxId[50],auxName[50],auxHoursWorked[50],auxSalary[50];
    if(pFile == NULL)
    {
        return -1;
    }
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxName,auxHoursWorked,auxSalary);  ///PASADA PARA LEER TITULOS
    while(!feof(pFile))
    {
                r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxName,auxHoursWorked,auxSalary);
        if(r==4){
                auxEmployee  = employee_newParametros(auxId ,auxName, auxHoursWorked, auxSalary);
                ll_add(pArrayListEmployee, auxEmployee );
                i++;
                }
        else
            {
            break;
            }
    }

    printf("\n\n%d empleados cargados OK!\n", i);

    return i;
}
///****************************************************************************************************************************************************
///****************************************************************************************************************************************************
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
