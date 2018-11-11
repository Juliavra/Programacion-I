#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


///CHEKAR TODO OK

/*
///*********************************************************************
///*********************************************************************
Employee* employee_new()
  {
    Employee* this = malloc(sizeof(Employee));
    if(this !=NULL)
      {
        this->id = 0;
        strcpy(this->nombre, " ");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
      }
    return this;
}

///*********************************************************************
///*********************************************************************
int employee_setId(Employee* this,int id)
  {
    int rtn = -1;
    if(this != NULL && id > 0)
      {
        this->id = id;
        rtn = 0;
      }
    return rtn;
}

///*********************************************************************
///*********************************************************************
int employee_getId(Employee* this,int* id)
{
    if(this != NULL)
      {
        *id = this->id;
        return 0;
      }
        else
        {
        return -1;
        }
}

///*********************************************************************
///*********************************************************************

int employee_setNombre(Employee* this,char* nombre)
{
    int rtn = -1;
    if(this != NULL && nombre[0] != '\0')
      {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        rtn = 0;
      }
    return rtn;
}
///*********************************************************************
///*********************************************************************

int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL)
      {
        strcpy(this->nombre, nombre);
        return 0;
      }
      else
        {
          return -1;
        }
}
///*********************************************************************
///*********************************************************************

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int retorno = -1;
    if(this != NULL && horasTrabajadas > 0){
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

///*********************************************************************
///*********************************************************************
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        return 0;
    }
    else
    {
        return -1;
    }
}
///*********************************************************************
///*********************************************************************

int employee_setSueldo(Employee* this,int sueldo)
{
    int rtn = -1;
    if(this != NULL && sueldo > 0)
      {
        this->sueldo = sueldo;
        rtn = 0;
      }
    return rtn;
}

///*********************************************************************
///*********************************************************************
int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL)
      {
        *sueldo = this->sueldo;
        return  0;
      }
    else
    {
        return -1;
    }
}
///*********************************************************************
///*********************************************************************
*/

