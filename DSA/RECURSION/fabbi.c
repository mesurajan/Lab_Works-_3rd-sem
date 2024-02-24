#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int fabi(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return (fabi(num - 1) + fabi(num - 2));
    }
}
int main(int num, int i)
{
    printf("Enter the total number of series :");
    scanf("%d", &num);
    printf("The series is :\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\t", fabi(i));
    }
}
