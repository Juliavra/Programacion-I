#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* fp = fopen(path, "r");
    int rtn= 0;
    if(fp != NULL)
    {
        parser_EmployeeFromText(fp, pArrayListEmployee);
        rtn = 1;
    }
    else
    {
        printf("\n Archivo no cargado\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int rtn=-1, indexIs;
    ///  Employee* pEmployee=NULL;
  ///  Employee* auxEmployee=employee_new();
    char name [50], id [5], hoursWorked [4], salary [10];
    system ("cls");
    printf("\n\t\t\t ALTA DE EMPLEADO\n\n");
    do
    {
        ///EL ID DEBE SER AUTOGENERADO
///        fflush(stdin);
   ///     printf("Ingrese el Id: ");
      ///  fgets (id, 5, stdin);
    ///    removeLineFeed(id);
     ////   r=numbersOnly(id);
///        if (r!=1)
 ///       {
  ///          printf("Numero incorrecto");
   ////     }

        indexIs=controller_findEmployee(pArrayListEmployee, atoi(id));
    }
    while (indexIs!=-1);

 enterName (name);
 ///DEBE TOMAR UNA ACCION SI EL NOMBRE ESTA MAL INGRESADO
 enterHoursWorked (hoursWorked);
///DEBE TOMAR UNA ACCION SI EL NOMBRE ESTA MAL INGRESADO
 enterSalary(salary);
///    printf("CONTROLLER salary :%s", salary);

    return rtn;
}
///*************************************************************************************************************
///*************************************************************************************************************
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado;
    int i, rtn = 1;
    system("cls");
    for (i=0; i < ll_len(pArrayListEmployee); i++)
    {
        pEmpleado = ll_get(pArrayListEmployee, i);
        printf("%5d %20s %3d %6.2f\n",pEmpleado->id,pEmpleado->name,pEmpleado->hoursWorked,pEmpleado->salary);
    }
    printf("\n");
    return rtn;
}/**< FINALIZADO */

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}
///**************************************************************************************************************
///**************************************************************************************************************
int controller_findEmployee(LinkedList* pArrayListEmployee, int id)
{
    Employee* pEmployee;
    int i, rtn = -1;
    for (i=0; i < ll_len(pArrayListEmployee); i++)
    {
        pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
        if (id == pEmployee->id)
        {
            rtn = i;
            break;
        }
    }
    return rtn;
}
