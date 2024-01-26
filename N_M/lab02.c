/*find the real root of sin(x)-1/x=0.
correct upto 4 decimal places using newtorn rapson method*/

#include <stdio.h>
#include <math.h>

#define e 0.0001

float f(float x)
{
    return (sin(x) - 1 / x);
}

float df(float x)
{
    return (cos(x) + 1 / (x * x));
}

int main()
{
    float x0, x1;

    printf("Find the real root of sin(x) - 1/x correct up to 4 decimal places using the Newton-Raphson method.\n");
    printf("Solution ---->\n");
    printf("Enter the initial guess x0: ");
    scanf("%f", &x0);

    printf("i\t  x0\t\t  f(x0)\t\t  f'(x0)\t  x1\n");

    int iteration = 1;

    do
    {
        float fx0 = f(x0);
        float dfx0 = df(x0);

        x1 = x0 - fx0 / dfx0;

        printf("%d\t%f\t%f\t%f\t%f\n", iteration, x0, fx0, dfx0, x1);

        x0 = x1;
        iteration++;
    } while (fabs(f(x1)) >= e);

    printf("The real root is approximately %.4f\n", x1);

    return 0;
}
