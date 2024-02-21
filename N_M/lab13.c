// RK-2 and RK-4 method
#include <stdio.h>
#include <math.h>

// Function to return dy/dx
double func(double x, double y)
{
    return (y - x) / (y + x); // Sample differential equation
}

// Function for numerical integration using 2nd order Runge-Kutta
void rk2(double x0, double y0, double xn, double h)
{
    double k1, k2, y = y0;

    printf("\n2nd Order Runge-Kutta Method:\n");
    printf("-----------------------------\n");
    printf("x0\t\ty0\n");
    printf("%f\t%f\n", x0, y0);

    for (double i = x0; i <= xn; i = i + h)
    {
        k1 = h * func(i, y);
        k2 = h * func(i + h / 2, y + k1 / 2);

        y = y + k2;

        printf("%f\t%f\n", i + h, y);
    }
}

// Function for numerical integration using 4th order Runge-Kutta
void rk4(double x0, double y0, double xn, double h)
{
    double k1, k2, k3, k4, y = y0;

    printf("\n4th Order Runge-Kutta Method:\n");
    printf("-----------------------------\n");
    printf("x0\t\ty0\n");
    printf("%f\t%f\n", x0, y0);

    for (double i = x0; i <= xn; i = i + h)
    {
        k1 = h * func(i, y);
        k2 = h * func(i + h / 2, y + k1 / 2);
        k3 = h * func(i + h / 2, y + k2 / 2);
        k4 = h * func(i + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        printf("%f\t%f\n", i + h, y);
    }
}

int main()
{
    double x0, y0, xn, h;

    printf("Enter x0: ");
    scanf("%lf", &x0);
    printf("Enter y0: ");
    scanf("%lf", &y0);
    printf("Enter xn: ");
    scanf("%lf", &xn);
    printf("Enter h: ");
    scanf("%lf", &h);

    rk2(x0, y0, xn, h);
    rk4(x0, y0, xn, h);

    return 0;
}
/*
Enter x0: 1
Enter y0: 2
Enter xn: 1.6
Enter h: 0.2

2nd Order Runge-Kutta Method:
-----------------------------
x0              y0
1.000000        2.000000
1.200000        2.059574
1.400000        2.105998
1.600000        2.140533
1.800000        2.164138

4th Order Runge-Kutta Method:
-----------------------------
x0              y0
1.000000        2.000000
1.200000        2.059563
1.400000        2.105966
1.600000        2.140472
1.800000        2.164043



*/