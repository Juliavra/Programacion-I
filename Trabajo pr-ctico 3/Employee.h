#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    float salary;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salaryStr);

void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setname(Employee* this,char* name);
int employee_getname(Employee* this,char* name);

int employee_sethoursWorked(Employee* this,int hoursWorked);
int employee_gethoursWorked(Employee* this,int* hoursWorked);

int employee_setsalary(Employee* this,float salary);
int employee_getsalary(Employee* this,int* salary);

int enterId (char *id);
int enterName (char *name);
int enterHoursWorked (char *hoursWorked);
int enterSalary(char *salary);

int employeeSortById(void* empleadoA, void* empleadoB);
int employeeSortByName(void* empleadoA, void* empleadoB);
int employeeSortByHours(void* empleadoA, void* empleadoB);
int employeeSortBySalary(void* empleadoA, void* empleadoB);


int generates_Next_Id_Employee();
#endif // employee_H_INCLUDED
