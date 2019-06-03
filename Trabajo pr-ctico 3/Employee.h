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

int employee_setsalary(Employee* this,int salary);
int employee_getsalary(Employee* this,int* salary);


int enterName (char *name);
int enterHoursWorked (char *hoursWorked);
int enterSalary(char *salary);

#endif // employee_H_INCLUDED
