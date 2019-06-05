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
    Employee* pEmployee=NULL;
    char name [50], id [5], hoursWorked [4], salary [10];
    system ("cls");
    printf("\n\t\t\t ALTA DE EMPLEADO\n\n");
    ///EL ID DEBE SER AUTOGENERADO
    enterId (id);
///        indexIs=controller_findEmployee(pArrayListEmployee, atoi(id));
    enterName (name);
///DEBE TOMAR UNA ACCION SI EL NOMBRE ESTA MAL INGRESADO
    enterHoursWorked (hoursWorked);
///DEBE TOMAR UNA ACCION SI EL NOMBRE ESTA MAL INGRESADO
    enterSalary(salary);
    pEmployee=employee_newParametros(id,name,hoursWorked,salary);
    ll_add( pArrayListEmployee, pEmployee);

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
    int rtn=-1, id=-1, indexIs=-1, choice=-1;
    char name[30], hoursWorked [5], salary [10];
    Node *EmployeeData=NULL;
    void *pElement=NULL;

    if (pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        id=getInt("\nIngrese el Id del registro a modificar: ");
        indexIs=controller_findEmployee(pArrayListEmployee, id);
        controller_ListsSingleEmployee(pArrayListEmployee, indexIs);
///printf("AAAAAAAACCCCCCCCCCCCCCCCCCAAAAAAAAAAAAAA"); system("pause");
        choice=getInt("\nQue desea modificar?:  1-Nombre   2Hs Trabajadas  3-Salario");

        switch (choice)
        {
        case 1:
        {
            enterName(name);
             EmployeeData=test_getNode(pArrayListEmployee, indexIs);
             pElement=EmployeeData->pElement;
            employee_setname(pElement,name);
            break;
        }
        case 2:
        {
            enterHoursWorked(hoursWorked);
            break;
        }
        case 3:
        {
            enterSalary(salary);
            break;
        }
        default:
        {
            break;
        }
        }


        rtn=1;
    }
    else
    {
        printf("LA LINK LIST ESTA VACIA");


    }
    return rtn;
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
    Employee *pEmpleado=employee_new();
    int i, rtn = 1;
    system("cls");
    printf(" ID  Nombre Hs Trabajadas   Salario\n",pEmpleado->id,pEmpleado->name,pEmpleado->hoursWorked,pEmpleado->salary);

    for (i=0; i < ll_len(pArrayListEmployee); i++)
    {
        pEmpleado = ll_get(pArrayListEmployee, i);
        printf("%d %20s %3d %6.2f\n",pEmpleado->id,pEmpleado->name,pEmpleado->hoursWorked,pEmpleado->salary);
    }
    printf("\n");
    return rtn;
}

int controller_ListsSingleEmployee(LinkedList* pArrayListEmployee, int id)
{
    Employee *pEmpleado;
    int rtn = 1;
    system("cls");
    pEmpleado = ll_get(pArrayListEmployee, id);
    printf(" ID  Nombre Hs Trabajadas   Salario\n",pEmpleado->id,pEmpleado->name,pEmpleado->hoursWorked,pEmpleado->salary);
    printf(" %d %s %d %f\n",pEmpleado->id,pEmpleado->name,pEmpleado->hoursWorked,pEmpleado->salary);

//   printf("%d %20s %3d %6.2f\n",pEmpleado->id,pEmpleado->name,pEmpleado->hoursWorked,pEmpleado->salary);
    printf("\n");
    return rtn;
}









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
