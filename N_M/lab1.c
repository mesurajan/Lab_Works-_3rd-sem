// find the real root of sin(x)=1/x. using bisection method correct upto 3 decimal.

#include <stdio.h>
#include <conio.h>
#include <math.h>

#define e 0.0001

float f(float x)
{
    return sin(x) - (1 / x);
}

int main()
{
    int i = 0;
    float x1, x2, x3, root;

    do
    {
        printf("find the real root of sin(x)=1/x. using bisection method correct upto 3 decimal.\n");
        printf("Solution--->\n");
        printf("Input two initial guesses, x1 and x2:\n ");
        scanf("%f%f", &x1, &x2);
    } while (f(x1) * f(x2) > 0);

    printf("i      \t   x1       \t   x2        \t   x3        \t   f(x3)\n");

    do
    {
        x3 = (x1 + x2) / 2;
        if (f(x3) * f(x2) < 0)
        {
            x1 = x3;
        }
        else
        {
            x2 = x3;
        }
        printf("%d\t %f\t %f\t %f\t %f\n", i, x1, x2, x3, f(x3));
        i++;
    } while (fabs((x2 - x1) / x2) > e);

    root = x3;
    printf("Root = %f\n", root);

    getch();
    return 0;
}
