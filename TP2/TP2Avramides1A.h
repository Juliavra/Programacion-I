///PROTOTYPES

typedef struct
{
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

///AUXILIAR STRUCT

typedef struct
{
    int idAux;
    char nameAux [51];
    char lastNameAux [51];
    float salaryAux;
    int sectorAux;
    int isEmptyAux;
} EmployeeAux;


/// INITIALIZE FUNCTIONS

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee list [], int len,int id);
int menu (void);
int initEmployees(Employee list [], int length);
int obtainFreeSpace(Employee *employees, int ELEMENTS);
int printEmployees (Employee *employees, int id);
int lettersOnly (char auxiliarInput[]);
int printsEmployee (Employee *employees, int i);
int removeEmployee(Employee* list, int len, int id);
float salaryAverage(Employee *employees, int ELEMENTS);
int overAverage(Employee *employees, int ELEMENTS);
void tags (void);
int numbersOnly (char auxiliarInput[]);
void chanceCase  (char auxiliarInput[]);
int sortEmployees (Employee *employees,int len, int order);
int generatesNextId();
float salaryTotal (Employee *employees, int ELEMENTS);

