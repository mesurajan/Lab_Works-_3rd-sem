// Trapezoidal , simpson's 1/3 ,simpson's 3/8
/*
Algorithm :
1.start
2.Declare the necessary variable and define the function f(x).
3.Inputr the lower limit and upper limit as a and b respectively.
4.Input the number of strips as n.
5.Compute the value of strip width as h=(b-a)/n;
6.Compute the integeration value as
  I =(h/2)*(f(a)+f(b)+2*Summation from n-1 to i=1 of f(a+i*h))
7.Display the integral value is I
8.stop
*/

#include <stdio.h>
#include <math.h>

double f(double x)
{

    return (cos(x) / (1 + x * x));
}

double trapezoidal_rule(double a, double b, int n)
{
    double h = (b - a) / n;
    // double I = (h / 2) * (f(a) + f(b));
    double sum = 0;

    for (int i = 1; i < n; i++)
    {
        sum += f(a + i * h);
    }

    double I = (h / 2) * (2 * sum + f(a) + f(b));
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

    double integral_value = trapezoidal_rule(a, b, n);
    printf("The integral value is: %.6lf\n", integral_value);

    return 0;
}