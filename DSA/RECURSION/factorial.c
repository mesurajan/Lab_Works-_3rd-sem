#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int fact(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * fact(num - 1);
    }
}
int main(int num)
{
    printf("Enter the number to find factrorial of :");
    scanf("%d", &num);
    printf("The factorial of %d is :%d", num, fact(num));
    return 0;
}