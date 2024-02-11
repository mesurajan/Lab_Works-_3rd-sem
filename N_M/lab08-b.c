// implementation of simpsons 1/3 method
/*
Algorithms:
1.start
2.eclare the necessary variable and define the function f(x) where f(x)=(cos(x)/(1+x*x))
3.Input the lower limit andupper limit as a and b respectively
4.Input the number of strips as n n where n is a multiple of 3.
5.Compute the value of strip width as h=(b-a)/n.
6.Compute the integer value
 I = (h / 3) * (f(a) + f(b) + sum);
7.Display the integral value is I.
8.stop
*/
#include <stdio.h>
#include <math.h>

double f(double x)
{
    return (cos(x) / (1 + x * x));
}

double simpsons_13(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += 2 * f(a + i * h);
        }
        else
        {
            sum += 4 * f(a + i * h);
        }
    }

    double I = (h / 3) * (f(a) + f(b) + sum);
    return I;
}

int main()
{
    double a, b;
    int n;

    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);

    printf("Enter the number of strips (n): ");
    scanf("%d", &n);

    double integral_value = simpsons_13(a, b, n);
    printf("The integral value is: %.6lf\n", integral_value);

    return 0;
}