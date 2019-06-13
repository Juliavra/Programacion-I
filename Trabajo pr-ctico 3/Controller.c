#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*    Puntero al path donde debe buscarse el archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int rtn retorna 0 si es Error y 1 si es correcto
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
 * \param path char*    Puntero al path donde debe buscarse el archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna 0 si es Error y 1 si es correcto
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* fp = fopen(path, "rb");
    int rtn= 0;
    if(fp != NULL)
    {
        parser_EmployeeFromBinary(fp, pArrayListEmployee);
        rtn = 1;
    }
    else
    {
        printf("\n Archivo binario no cargado\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    return rtn;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int rtn=-1, flagId = 0, isEmpty;
    Employee* pEmployee=NULL;
    char name [50], id [5], hoursWorked [4], salary [10];
    int newID=-1, rName=-1, rId=-1, rHoursWorked=-1, rSalary=-1, addedOk=-1, r;
    system ("cls");
    printf("\n\t\t\t ALTA DE EMPLEADO\n\n");

    do
    {
        newID=generates_Next_Id_Employee();
        isEmpty=controller_findEmployee(pArrayListEmployee, newID);
        if (isEmpty==-1)
        {
            itoa(newID, id, 10);
            ///printf ("%d if isEmpty", isEmpty);
        }
    }
    while (isEmpty!=-1);

    printf("\nID: %s\n\n", id);
    while (rName!=1)
    {
        rName=enterName (name);
    }
    while(rHoursWorked!=1)
    {
        rHoursWorked=enterHoursWorked (hoursWorked);
    }
    while(rSalary!=1)
    {
        rSalary=enterSalary(salary);
    }
    ///  printf("\nNEWPARAM ID: %s\n\n", id);
    pEmployee=employee_newParametros(id,name,hoursWorked,salary);

    if (pEmployee!=NULL)
    {
        addedOk=ll_add( pArrayListEmployee, pEmployee);
        if (addedOk!=0)
        {
            printf ("\n\nNo se ha podido agregar un registro con exito\n\n");
        }
        else
        {
            printf ("\n\nSe ha agregado un registro con exito\n\n");
        }
    }
    return rtn;
}

///*************************************************************************************************************
///*************************************************************************************************************
/** \brief Modificar datos de empleado
 *  
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int rtn=-1, id=-1, indexIs=-1, choice=-1;
    char name[30], hoursWorked [5], salary [10];
    int rName=-1, rHoursWorked=-1, rSalary=-1;
    Node *EmployeeData=NULL;
    void *pElement=NULL;
    pElement=employee_new();

    if (pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        ///      id=getInt("\nIngrese el Id del registro a modificar: ");
        id=getValidInt("\nIngrese el Id del registro a modificar: ","\nIngreso un Id inexistente ", 0, 100000);
        indexIs=controller_findEmployee(pArrayListEmployee, id);
        if (indexIs!=-1)
        {
            controller_ListsSingleEmployee(pArrayListEmployee, indexIs);
            choice=getInt("\nQue desea modificar?:  1-Nombre   2-Hs Trabajadas  3-Salario");
            EmployeeData=test_getNode(pArrayListEmployee, indexIs);
            pElement=EmployeeData->pElement;
            rtn=1;
            switch (choice)
            {
            case 1:
            {
                while (rName!=1)
                {
                    rName=enterName (name);
                }
                employee_setname(pElement,name);
                break;
            }
            case 2:
            {
                while(rHoursWorked!=1)
                {
                    rHoursWorked=enterHoursWorked (hoursWorked);
                }
                employee_sethoursWorked(pElement, atoi(hoursWorked));
                break;
            }
            case 3:
            {
                while(rSalary!=1)
                {
                    rSalary=enterSalary(salary);
                }
                employee_setsalary(pElement, atof(salary));
            }
            default:
            {
                printf("\nOpcion incorrecta\n");
                break;
            }
            }
        }
        else
        {
            printf("\n\nSelecciono un ID Inexistente\n\n");
        }
    }
    else
    {
        printf("La lista esta vacia");
    }
    return rtn;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int     rtn retorna -1 si es Error y 1 si es correcto
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int rtn=-1, id=-1, indexIs=-1, choice=-1, removeOk=-1;

    if (pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id=getValidInt("\nIngrese el Id del registro a borrar","\nIngreso un Id inexistente ", 1, 100000);
        indexIs=controller_findEmployee(pArrayListEmployee, id);

        if (indexIs!=-1)
        {
        controller_ListsSingleEmployee(pArrayListEmployee, indexIs);
        choice=getInt("\nEsta seguro que desea borrar? \t\t 1-Si    2-No\n\n? ");
        switch (choice)
        {
        case 1:
        {
            removeOk=ll_remove( pArrayListEmployee, indexIs);
            if (removeOk==0)
            {
                printf("\n\n\n\nSe ha borrado un archivo correctamente\n\n\n\n");
            }
            break;
        }
        case 2:
        {
            printf("\n\n\n\nNo se ha borrado ningun archivo\n\n\n\n");
            break;
        }
        default:
        {
            break;
        }
        }
    }
    else
    {
            printf("\n\nNO existe el ID\n\n");
    }

    }
    return rtn;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado=employee_new();
    int rtn = 1, i=-1;
    system("cls");
    tags();
    for (i=0; i < ll_len(pArrayListEmployee); i++)
    {
        pEmpleado = ll_get(pArrayListEmployee, i);
        printf("%3d %13s %12d %19.2f\n",pEmpleado->id,pEmpleado->name,pEmpleado->hoursWorked,pEmpleado->salary);
    }
    printf("\n");
    return rtn;
}

/** \brief Listar un empleado
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \param id int es el valor de id que debe ser impreso
* \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */

int controller_ListsSingleEmployee(LinkedList* pArrayListEmployee, int id)
{
    Employee *pEmpleado;
    int rtn = 1;
    system("cls");
    pEmpleado = ll_get(pArrayListEmployee, id);
    tags();
    printf("%3d %13s %12d %19.2f\n",pEmpleado->id,pEmpleado->name,pEmpleado->hoursWorked,pEmpleado->salary);
    printf("\n");
    return rtn;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    int option, order=0;

    printf("\n\nPor que campo desea ordenar?\n\n");
    printf("1-Id\n");
    printf("2-Nombre\n");
    printf("3-Horas trabajadas\n");
    printf("4-Salario\n");
    scanf("%d", &option);

    printf("\n\nDesea hacerlo en forma: 1-Ascendente    2-Descendente");
    scanf("%d", &order);

    switch (order)
    {
    case 1:
    {
        order=0;
        break;
    }
    case 2:
    {
        order=1;
        break;
    }
    default:
    {
        break;
    }
    }

    switch(option)
    {
    case 1:
        ll_sort(pArrayListEmployee, employeeSortById, order);
        printf("Ordenamiento por id realizado!\n");
        break;
    case 2:
        ll_sort(pArrayListEmployee, employeeSortByName, order);
        printf("Ordenamiento por nombre realizado!\n");
        break;
    case 3:
        ll_sort(pArrayListEmployee, employeeSortByHours, order);
        printf("Ordenamiento por horas trabajadas realizado!\n");
        break;
    case 4:
        ll_sort(pArrayListEmployee, employeeSortBySalary, order);
        printf("Ordenamiento por salario realizado!\n");
        break;
    default:
        printf("Opcion incorrecta\n");
        break;
    }
    return rtn;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*    Puntero al path donde debe guardarse el archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    Employee* this;
    FILE* csvFile = fopen(path, "w");

    if(csvFile==NULL)
    {
        printf("Error al guardar\n");
        return rtn;
    }
    fprintf(csvFile, "id,nombre,horasTrabajadas,sueldo\n");
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(csvFile, "%d,%s,%d,%f\n", this->id, this->name, this->hoursWorked, this->salary);
        }
        printf("\n\n\n%d Empleados guardados en modo texto OK!\n", ll_len(pArrayListEmployee));
        rtn = 1;
    }
    fclose(csvFile);
    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*    Puntero al path donde debe guardarse el archivo
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    int len = ll_len(pArrayListEmployee);
    Employee* this;
    FILE* list = fopen(path, "wb");

    if(list==NULL)
    {
        printf("Error para guardar. No se pudo abrir archivo\n");
        return rtn;
    }
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(this,sizeof(Employee),1,list);
        }
        printf("\n\nArchivo guardado conteniendo %d empleados \n", ll_len(pArrayListEmployee));
        rtn = 1;
    }
    fclose(list);
    return rtn;
}
///**************************************************************************************************************
///**************************************************************************************************************
/** \brief busca un empleado usando el ID
 *
 * \param pArrayListEmployee LinkedList*    Puntero a la lista que contiene los empleados
 * \param id int es el valor que se usa para buscar un empleado en concreto
* \return int  rtn retorna -1 si es Error y 1 si es correcto
 *
 */


int controller_findEmployee(LinkedList* pArrayListEmployee, int id) ///-1 NO LO ENCONTRO
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
///---------------------------------------------------------------------------------------------------
///---------------------------------------------------------------------------------------------------

