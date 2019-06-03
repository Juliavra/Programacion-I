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
{
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
    if (hoursWorked>= 0 && hoursWorked<500 && this != NULL)
    {
        this->hoursWorked= hoursWorked;
        rtn = 1;
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

int enterName (char *name)
{
    int rtn=1, r=0;
    getString("Ingrese el nombre: ", name);
    r=esSoloLetras(name);

    if (r==0)
    {
        printf("Nombre incorrecto\n");
        rtn=0;
    }
    changeCase(name);
    printf("\n FOO ENTERNAME name:%s\n", name);

    return rtn;
}

int enterHoursWorked (char *hoursWorked)
{
    int rtn=1, r=0;
    getString("Ingrese las horas trabajadas: ",hoursWorked);
    r=esNumerico (hoursWorked);
        if (r==0)
        {
            printf("horas incorrecto");
                    rtn=0;
        }
    printf("FOO ENTERHOURS hoursWorked :%s", hoursWorked);
    return rtn;
}


int enterSalary(char *salary)
{
    int rtn=1, r=0;
    getString("Ingrese el salario: ",salary);
    r=esNumericoFlotante (salary);
        if (r==0)
        {
            printf("salario incorrecto");
                    rtn=0;
        }
    printf("FOO ENTERSALARY salary:%s", salary);
    return rtn;
}


