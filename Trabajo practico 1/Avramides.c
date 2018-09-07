/** \brief Adds first and second number entered by user
 *
 * \param op1 1st number to add
 * \param op2 2nd number to add
 * \return Result of adding op1 & op2
  */

int addition (int op1,int op2)
{
    int additionResult;

    additionResult= op1+op2;

    return additionResult;
}

/** \brief Subtracts second number from first number entered by user
 *
 * \param op1 is minuend
 * \param op2 is subtrahend
 * \return Result of subtract op1 - op2
  */

int subtraction(int op1,int op2)
{
    int subtractionResult;

    subtractionResult=op1-op2;

    return subtractionResult;
}

/** \brief Multiplies op1 and op2
 *
 * \param op1 1st number to be multiplied
 * \param op2 2nd number to be multiplied
 * \return Result of multiplying op 1 * op2
  */

int multiply (int op1,int op2)
{
    int multiplicationResult;

    multiplicationResult=op1*op2;

    return multiplicationResult;
}

/** \brief Divides 1st number from 2nd number entered by user
 *
 * \param op1 is the dividend
 * \param op2 is the divisor
 * \return Result of dividing op1 / op2
  */

float division(int op1,int op2)
{
    float divisionResult;

    divisionResult=(float) op1/op2;

    return divisionResult;
}

/** \brief Calculates Factorial of a given number
 *
 * \param op1 is the given number to calculate its factorial
 * \return Result of given number factorial
  */

int factorial (int op1)
{
    int i=1;
    int Factorialresult=1;

    if (op1==0 || op1==1)
    {
        Factorialresult=1;
    }
    else

        for (i=1; i<=op1; i++)
        {
            Factorialresult=Factorialresult*i;
        }

    return Factorialresult;
}

