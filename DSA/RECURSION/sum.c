#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int sum(int num)
{
    if (num != 0)
    {
        return num + sum(num - 1);
    }
    else
    {
        return 0;
    }
}
int main(int num, int i)
{
    printf("Enetr the number :");
    scanf("%d", &num);

    printf("The sum of natural number %d is :%d", num, sum(num));

    return 0;
}