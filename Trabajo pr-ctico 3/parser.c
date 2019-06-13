#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile Puntero al archivo con el que se trabajará
 * \param pArrayListEmployee LinkedList* pArrayListEmployee Puntero al LinkedList de empleados
 * \return int i -1 es Puntero a File Nulo  i es la cantidad de elementos parseados desde el archivo
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

    printf("\n\n%d empleados cargados en modo texto OK!\n", i);

    return i;
}
///****************************************************************************************************************************************************
///****************************************************************************************************************************************************
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param FILE* pFile Puntero al archivo con el que se trabajará
 * \param pArrayListEmployee LinkedList* pArrayListEmployee Puntero al LinkedList de empleados
 * \return int i es 0 si el Puntero a File es Nulo.  i es la cantidad de elementos parseados desde el archivo
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee employee;
    int cant, i = 0;

    cant = fread(&employee, sizeof(Employee), 1, pFile);
    while(!feof(pFile)){
        Employee* pEmployee = employee_new();
        employee_setId(pEmployee,employee.id);
        employee_sethoursWorked(pEmployee,employee.hoursWorked);
        employee_setname(pEmployee,employee.name);
        employee_setsalary(pEmployee,employee.salary);
    if(cant == 1){
            ll_add(pArrayListEmployee, pEmployee);
            fread(&employee, sizeof(Employee), 1, pFile);
            i++;
    }else{
            if(!feof(pFile)){
                printf("\n!!! - Se ha producido un error llegando al final del archivo.");
                system("pause");
                break;
            }else{
                printf("\n\n\nFinal del archivo. Empleados leidos %d\n\n ", i);
            }
        }
    }
    printf("\n\n\n%d Empleados cargados correctamente en modo binario\n", ll_len(pArrayListEmployee));
    fclose(pFile);
    return i;
}
