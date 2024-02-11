// implementation of simphons 3/8 rule
/*
Algorithms:
1.start
2.eclare the necessary variable and define the function f(x) where f(x)=(cos(x)/(1+x*x))
3.Input the lower limit andupper limit as a and b respectively
4.Input the number of strips as n n where n is a multiple of 3.
5.Compute the value of strip width as h=(b-a)/n.
6.Compute the integer value
I=(3h/8)*(f(a)+f(b)+3(f(a+h)+f(a+2h)+f(a+4h)+......+2*f(a+3h)+f(a+6h)+f(a+9h)+.......))
7.Display the integral value is I.
8.stop


*/

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return (cos(x) / (1 + x * x));
}

double simpsons_38(double a, double b, int n)
{

    double h = (b - a) / n;

    double sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            sum += 3 * f(a + i * h);
        }
        else if (i % 3 == 1)
        {
            sum += 2 * f(a + i * h);
        }
        else
        {
            sum += 3 * f(a + i * h);
        }
    }
    double I = (3 * h / 8) * (f(a) + f(b) + sum);

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

    double integral_value = simpsons_38(a, b, n);

    printf("The integral value is: %.6lf\n", integral_value);

    return 0;
}