#include <stdio.h>
#include <math.h>
#define error 0.00001
float f(float x)
{
    return (sin(x) - 3 * x + 2);
}
float g(float x)
{
    return ((sin(x) + 2) / 3);
}

int main()
{
    float x1, x2, root;
    printf("enter the intial guess:\n ");
    scanf("%f", &x1);
    do
    {
        x2 = g(x1);
        if (fabs(f(x2 - x1) / x2) >= error)
        {
            x1 = x2;
        }
        else
        {
            root = x1;
        }
    } while (fabs(f(x2)) > error);
    printf("root %f", x2);
    return 0;
}