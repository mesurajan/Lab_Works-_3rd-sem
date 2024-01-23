#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    char ch;
    int num1, num2;
    printf("enter the first number:");
    scanf("%d", &num1);
    printf("Enter the second number:");
    scanf("%d", &num2);
    printf("Enter the operator you want(+,-,*,/):");
    scanf("%s", &ch);
    if (ch == '+')
    {
        printf("Addition is %d", num1 + num2);
    }

    else if (ch == '-')
    {
        printf("Subtraction is %d", num1 - num2);
    }
    else if (ch == '*')
    {
        printf("Multiplication is %d", num1 * num2);
    }
    else if (ch == '/')
    {
        printf("Division is %d", num1 / num2);
    }

    else
    {
        printf("The operator not in use.................");
    }
}