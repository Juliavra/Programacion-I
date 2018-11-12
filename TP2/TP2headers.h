///PROTOTYPES


///EMPLOYEE STRUCT
typedef struct
{
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;


///AUX EMPLOYEE STRUCT
typedef struct
{
    int idAux;
    char nameAux [51];
    char lastNameAux [51];
    float salaryAux;
    int sectorAux;
    int isEmptyAux;
} EmployeeAux;


/// SECTOR STRUCT
typedef struct
{
    int id;
    char description[20];
} eSector;


///MEAL DESCRIPTION
typedef struct
{
    int id;
    char description [51];
    int isEmptyAux;
} eMealDescription;

///MEAL DESCRIPTION + EMPLOYEE
typedef struct
{
    int idEmployee;
    int idMealDescription;
    int isEmptyAux;
} eMealDescriptionEmployee;


/// INITIALIZE FUNCTIONS

int addsEmployee(eEmployee* employees, int EMPLOYEESMAX);
int savesEmployee (eEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(eEmployee list [], int len,int id);
int menu (void);
int initEmployees(eEmployee list [], int length);
int obtainFreeSpace(eEmployee *employees, int EMPLOYEESMAX);
int printEmployees (eEmployee *employees, int id);
int lettersOnly (char auxiliarInput[]);


///int printsEmployee (eEmployee *employees, int i);
int printsEmployee (eEmployee  *employees, int i, eSector* sectors);

///int removeEmployee(eEmployee* list, int len);
int removeEmployee(eEmployee * employees, int EMPLOYEESMAX, eSector* sectors);

char findsSectorDescription (eEmployee  *employees, int i, eSector* sectors);

float salaryAverage(eEmployee *employees, int EMPLOYEESMAX);
int overAverage(eEmployee *employees, int EMPLOYEESMAX);
void tags (void);
int numbersOnly (char auxiliarInput[]);
void chanceCase  (char auxiliarInput[]);
int sortEmployees (eEmployee *employees,int len, int order);
int generatesNextId();
float salaryTotal (eEmployee *employees, int V);
void intro (void);
void hardCodedEmployees (eEmployee* employees);
int modifyEmployee (eEmployee* employees, int EMPLOYEESMAX, eSector* sectors);
