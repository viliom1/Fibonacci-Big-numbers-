#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ReverseArray(char *array, size_t size)
{
    int i;
    for (i = 0; i < size /2; i++)
    {
        int oldValue = *(array + i);
        *(array + i) = *((array + size - 1) - i);
        *((array  +size - 1) - i) = oldValue;

    }

}
char* Addition(char* a, char* b)
{
	/* human-like addition for manipulating big integers incoming from fibonacci function */
    char* result = malloc(100);
    int lenght = strlen(b); //b will always be the bigger number
    int overflow =0;
    int i;
    for(i = 0; i < lenght; i++ )
    {
        int add = 0;

        int bNum = b[i] - '0';
        if(i < strlen(a) && i < strlen(b))
        {
            int aNum = a[i] - '0';
            add = aNum + bNum + overflow;
            overflow = 0;
            if (add < 10)
            {
                result[i] = add + '0';
            }
            else
            {
                result[i] = (add + '0') - 10;
                overflow = overflow + 1;
            }
        }
        else
        {
            add = bNum + overflow;
            overflow = 0;
            if (add < 10)
            {
                result[i] = (add + '0');
            }
            else
            {
                result[i] = (add + '0') - 10;
                overflow = overflow + 1;
            }

        }

    }
    if (overflow != 0)
    {
        result[i] = overflow + '0';
        i++;

    }

    result[i] = '\0';
    return result;
}

void FibonacciPrnt()
{
    char* firstNumber = malloc(100);
    char* secondNumber = malloc(100);
    char* result;
    if (firstNumber && secondNumber)
    {
        firstNumber[0] = '1';
        firstNumber[1] = '\0';
        secondNumber[0] = '1';
        secondNumber[1] = '\0';
        int i; // i + 2 is fibonacci's number count ( i = 5 is 7th fibonacci number)
        for(i = 1; i<= 498; i++)
        {
            result = Addition(firstNumber , secondNumber);
            firstNumber = secondNumber;
            secondNumber = result;
        }
        ReverseArray(result,strlen(result));
		/* the array will be in reverse order, so to be human readable
		 it must be reversed first */
        for(i = 0; i< strlen(result); i++)
        {
            printf("%c", result[i]);
        }
    }

}


int main()
{

        FibonacciPrnt();



    return (EXIT_SUCCESS);
}

