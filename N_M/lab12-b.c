// curve fitting using least square method i.e y=ax^b
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double x[100], y[100], X[100], Y[100], sumx, sumy, sumxx, sumxy, a, b;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the value of x and y for each data point:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
        X[i] = log(x[i]);
        Y[i] = log(y[i]);
    }

    sumx = sumy = sumxx = sumxy = 0;
    for (int i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += Y[i];
        sumxx += X[i] * X[i];
        sumxy += X[i] * Y[i];
    }

    a = exp((sumxy * sumx - sumxx * sumy) / (sumx * sumx - n * sumxx));
    b = (sumy - a * n) / sumx;

    printf("The value of a is: %lf\n", a);
    printf("The value of b is: %lf\n", b);

    return 0;
}
/*
Enter the number of data points: 6
Enter the value of x and y for each data point:
2
16.0
4
11.1
6
8.7
8
6.4
10
4.7
12
2.6
The value of a is: 1.395107
The value of b is: 0.079323
*/