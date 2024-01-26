/* find the real root cos(x)=xe^x.correct upto 4
decimal places using secant method*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#define e 0.00001
float f(float x)
{
    return (cos(x) - x * exp(x));
}
int main()
{
    float x1, x2, x3, root;
    int i = 1;
    printf("Find the real root of cos(x)=xe^x correct up to 4 decimal places using secant method.\n");
    printf("solution----> \n");
    printf("Enter the value of x1 and x2: ");
    scanf("%f%f", &x1, &x2);
    printf("i\t  x1 \t\t x2 \t\t  f(x1)\t\t  f(x2)\t\t  x3\t\t  f(x3)\n");
    do
    {
        x3 = ((x1 * f(x2)) - (x2 * f(x1))) / (f(x2) - f(x1));
        x1 = x2;
        x2 = x3;
        printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, x1, x2, f(x1), f(x2), x3, f(x3));
        i++;
    } while (fabs((x3 - x1) / x3) >= e);
    printf("The real root is %f", x3);
    return 0;
}
