#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"



/** \brief Reserves space for 1 Employee
 *
 * \param void
 * \return Employee's
 *
 */

Employee *employee_new()
{
    return (Employee*)calloc(1, sizeof(Employee));
}


Employee* employee_newParametros(char* id,char* name,char* hoursWorked,char* salary)
{///DEBERIA CHEQUEARSE Q LOS DATOS SEAN CORRECTOS CON SET!!!!!!
    Employee* pEmployee = employee_new();
    if(pEmployee != NULL)
    {
        pEmployee->id = atoi(id);
        strncpy(pEmployee->name, name, 50);
        pEmployee->hoursWorked = atoi(hoursWorked);
        pEmployee->salary = atof(salary);
    }
    return pEmployee;
}

int employee_setId(Employee* this, int id)
{
    int rtn = 0;
    if (id >= 0 && id <10000 && this != NULL)
    {
        this->id = id;
        rtn = 1;
    }
    return rtn;
}

int employee_getId(Employee* this, int* id)
{
    int rtn = 0;
    if (id != NULL && this != NULL)
    {
        *id = this->id;
        rtn = 1;
    }
    return rtn;
}

int employee_setname(Employee* this,char* name)
{
    int rtn = 0;
    if (strlen(name) > 0 && this != NULL)
    {
        strncpy(this->name, name, 50);
        rtn = 1;
    }
    return rtn;
}

int employee_getname(Employee* this,char* name)
{
    int rtn = 0;
    if (strlen(this->name) > 0 && this != NULL)
    {
        strncpy(name, this->name, 50) ;
        rtn = 1;
    }
    return rtn;
}

int employee_sethoursWorked(Employee* this, int hoursWorked)
{
    int rtn = 0;
    if(this != NULL)
    {
    if (hoursWorked>= 0 && hoursWorked<500)
    {
        this->hoursWorked= hoursWorked;
        rtn = 1;
    }
    else
    {
        printf("\n\ningreso un dato erroneo\n\n");
    }
    }
    return rtn;
}

int employee_gethoursWorked(Employee* this,int* hoursWorked)
{
    int rtn = 0;
    if (hoursWorked!= NULL && this != NULL)
    {
        *hoursWorked = this->hoursWorked;
        rtn = 1;
    }
    return rtn;
}

int employee_setsalary(Employee* this,int salary)
{
    int rtn = 0;
    if (salary>= 0  && this != NULL)
    {
        this->salary = salary;
        rtn = 1;
    }
    return rtn;
}

int employee_getsalary(Employee* this,int* salary)
{
    int rtn = 0;
    if (salary!= NULL && this != NULL)
    {
        *salary = this->salary;
        rtn = 1;
    }
    return rtn;
}

int enterId (char *id)
{
    int rtn=1, r=0;
    getString("Ingrese el Id: ", id);
    r=esNumerico(id);

    if (r==0)
    {
        printf("\n\nID incorrecto\n\n");
        rtn=0;
    }
    ///printf("\n FOO ENTERID ID:%s\n", id);

    return rtn;
}

int enterName (char *name)
{
    int rtn=1, r=0;

    getString("Ingrese el nombre: ", name);
    r=esSoloLetras(name);

    if (r==0)
    {
    printf("\n\nNombre incorrecto\n\n");
    rtn=0;
    }
    else
    {
    changeCase(name);
    }

    return rtn;
}



int enterHoursWorked (char *hoursWorked)
{
    int rtn=1, r=0;
    getString("Ingrese las horas trabajadas: ",hoursWorked);
    r=esNumerico (hoursWorked);
        if (r==0)
        {
            printf("\n\nCampo horas incorrecto\n\n");
                    rtn=0;
        }
    ///printf("\nFOO ENTERHOURS hoursWorked :%s\n", hoursWorked);
    return rtn;
}

int enterSalary(char *salary)
{
    int rtn=1, r=0;
    getString("Ingrese el salario: ",salary);
    r=esNumericoFlotante (salary);
        if (r==0)
        {
            printf("\n\nsalario incorrecto\n\n");
                    rtn=0;
        }
    ///printf("\nFOO ENTERSALARY salary:%s\n", salary);
    return rtn;
}

int employeeSortById(void* empleadoA, void* empleadoB){
    int rtn= -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        if((empA->id)<(empB->id)){
            rtn= 1 ;
        }else if((empA->id)>(empB->id)){
            rtn= -1 ;
        }else if((empA->id)==(empB->id)){
            rtn= 0;
        }
    }
    return rtn;
}

int employeeSortByName(void* empleadoA, void* empleadoB){
    int rtn= -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        rtn= strcmp(empB->name, empA->name);
    }

    return rtn;
}

int employeeSortByHours(void* empleadoA, void* empleadoB){
    int rtn= -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
                if((empA->hoursWorked)<(empB->hoursWorked)){
            rtn= 1 ;
        }else if((empA->hoursWorked)>(empB->hoursWorked)){
            rtn= -1 ;
        }else if((empA->hoursWorked)==(empB->hoursWorked)){
            rtn= 0;
        }
    }
    return rtn;
}

int employeeSortBySalary(void* empleadoA, void* empleadoB){
    int rtn= -1;
    Employee* empA;
    Employee* empB;

    if(empleadoA !=NULL && empleadoB !=NULL){
        empA = (Employee*) empleadoA;
        empB = (Employee*) empleadoB;
        if((empA->salary)<(empB->salary)){
            rtn= 1 ;
        }else if((empA->salary)>(empB->salary)){
            rtn= -1 ;
        }else if((empA->salary)==(empB->salary)){
            rtn= 0;
        }
    }
    return rtn;
}

/** \brief Generates a unique ID identifier for each ACTOR added
*
* \param NO parameters are received
* \return ID is the number of ID a rental will have
*
*/

int generates_Next_Id_Employee()
{
    static int id = 1000;
    id ++;
    return id;
}
