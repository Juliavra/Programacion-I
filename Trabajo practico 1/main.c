//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "Avramides.h"

//funciones
int main()
{
    int option;                     // Menu selection container
    int op1 = 0, op2 = 0;           //First and second number

    int additionResult=0;           // Initialize variables
    int subtractionResult=0;        // to contain
    int multiplicationResult=0;     // results,
    float divisionResult=0;         // returned
    int factorialAResult=0;         // by
    int factorialBResult=0;         // functions

    int flagFirst=0;               //0=number not yet loaded / 1= number loaded already
    int flagSecond=0;              //0=number not yet loaded / 1= number loaded already
    int flagResults=0;             //0=Results not yet calculated/ 1=Results calculated already
    int flagDivideByZero=0;        //0=second number is not zero/ 1=second number is zero

    printf("\n\n                         Bienvenido a 'La Calculadora'");
    printf("\n\n                            TP 01 de 1A Turno Maniana");
    printf("\n\n                                Julian Avramides");
    printf("\n\n                                    (107.975)");



    printf("\n\n Menu");
    printf("\n\n 1. Ingresar primer operando (A)");
    printf("\n\n 2. Ingresar segundo operando (B)");
    printf("\n\n 3. Calcular todas las operaciones ");
    printf("\n\n 4. Informar resultados ");
    printf("\n\n 5. Salir ");

    do
    {
        printf("\n\n Seleccione opcion: ");
        scanf("%d", &option);

        switch(option)                                          // Checks option selected by user
        {
        case 1:                                                 // Loads first number
        {
            printf("\n\n 1. Ingresar primer operando A = ");
            scanf("%d", &op1);
            flagFirst=1;                                        //Sets flag first number loaded

            break;
        }
        case 2:                                                 // Loads second number
        {
            printf("\n\n 2. Ingresar segundo operando B = ");
            scanf("%d", &op2);
            if (op2==0)
            {
                flagDivideByZero=1;                             //Sets flag second number equals zero
            }
            flagSecond=1;                                       //Sets flag second number loaded
            break;
        }
        case 3:                                                 // Calculates results
        {
            if (flagFirst==0)                                   //if==0 ask to load first numbrer
            {
                printf("\n\n No puedes calcular resultados sin ingresar operandos!!");
                printf("\n\n Debes ingresar primer operando A = ");
                scanf("%d", &op1);
                printf("\n Primer operando ingresado A = %d",op1);
                flagFirst=1;                                     //Sets flag first number  loaded
            }
            else if (flagSecond==0)                             //if==0 ask to load second numbrer
            {
                printf("\n\n No puedes calcular resultados sin ingresar operandos!!");
                printf("\n\n Debes ingresar segundo operando B = ");
                scanf("%d", &op2);
                if (op2==0)
                {
                    flagDivideByZero=1;                        //Sets flag second number equals zero
                }
                flagSecond=1;                                  //Sets flag second number loaded

            }

            additionResult= addition (op1,op2);             //  Assigns to each variable

            subtractionResult=subtraction(op1,op2);         // the result returned by each function

            multiplicationResult= multiply (op1,op2);       //  op1 is the first number user loaded

            divisionResult=division (op1,op2);              // op2 is the second number user loaded

            factorialAResult= factorial (op1);              //

            factorialBResult= factorial (op2);              //


            flagResults=1;                                  //Sets flag to 1, meaning results have been calculated

            break;
        }
        case 4:
        {
            if (flagResults==0)                             //Checks if results have been calculated,
                // if not asks user to do that
            {
                printf("\n Debes realizar los calculos antes de mostrar los resultados");

            }
            else if (flagSecond==0)                         //Checks if second number have been loaded,
                                                            // if not asks user to do that
            {
                printf("\nDebes ingresar el segundo operando antes de continuar");
            }
            else if (flagFirst==0)                          //Checks if first number have been loaded,
                // if not asks user to do that
            {
                printf("\nDebes ingresar el primer operando antes de continuar");
            }
            else if (flagDivideByZero==1)            //Prints results with a message
                // that it is impossible to divide by zero

            {
                printf("\n\n---------------------Resultados-----------------");
                printf("\n\n Primer operando  = %d",op1);
                printf("\n\n Segundo operando = %d",op2);
                printf("\n\n %d", op1);
                printf(" + %d", op2);
                printf(" = %d\n", additionResult);

                printf("\n %d", op1);
                printf(" - %d", op2);
                printf(" = %d\n", subtractionResult);

                printf("\n %d", op1);
                printf(" * %d", op2);
                printf(" = %d\n", multiplicationResult);                // prints results

                printf("\n %d", op1);
                printf(" / %d", op2);
                printf(" = No es posible dividir por cero\n");

                printf("\n A!= %d", op1);
                printf("!= %d\n",factorialAResult);

                printf("\n B!= %d", op2);
                printf("!= %d",factorialBResult);

                printf("\n\n------------------------------------------------");

                flagDivideByZero=0;             //sets flags to zero
                flagFirst=0;                    //To avoid the chance of error
                flagSecond=0;                   //when you want to calculate a division by zero,
                flagResults=0;                  //after you calculated a non zero division
            }

            else if (flagDivideByZero==0)       //Prints results
            {
                printf("\n\n---------------------Resultados-----------------");
                printf("\n\n Primer operando  = %d",op1);
                printf("\n\n Segundo operando = %d",op2);
                printf("\n\n %d", op1);
                printf(" + %d", op2);
                printf(" = %d\n", additionResult);

                printf("\n %d", op1);
                printf(" - %d", op2);
                printf(" = %d\n", subtractionResult);

                printf("\n %d", op1);
                printf(" * %d", op2);
                printf(" = %d\n", multiplicationResult);

                printf("\n %d", op1);
                printf(" / %d", op2);
                printf(" = %.2f\n", divisionResult);

                printf("\n A!= %d", op1);
                printf("!= %d\n",factorialAResult);

                printf("\n B!= %d", op2);
                printf("!= %d",factorialBResult);

                printf("\n\n------------------------------------------------");


            }
            break;
        }
        case 5:                             // Thank You message and Exit
        {
            printf("\n\n Gracias por utilizar la Calculadora\n\n");
            break;
        }
        default:                            // incorrect option message
            printf("\n\n Ha ingresado una opcion incorrecta.");

            break;
        }

    }
    while (option !=5 );         // keeps calculating unless you choose 5, then exits


    return 0;

}
