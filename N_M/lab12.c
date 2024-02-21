// curve fitting using least square method
#include <stdio.h>

int main()
{
    int n, i;
    float x[50], y[50], sumx, sumy, sumxx, sumxy, a, b;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
        sumx += x[i];
        sumy += y[i];
        sumxx += x[i] * x[i];
        sumxy += x[i] * y[i];
    }

    a = (sumxy * n - sumx * sumy) / (n * sumxx - sumx * sumx);
    b = (sumy * sumxx - sumx * sumxy) / (n * sumxx - sumx * sumx);

    printf("The values of a and b are: %.2f, %.2f\n", a, b);

    return 0;
}

/*Enter the number of data points: 5
Enter the values of x and y:
1
3
2
4
3
5
4
6
5
8
The values of a and b are: 1.20, 1.60



*/