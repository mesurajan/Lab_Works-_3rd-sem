// Guass
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    int n, i, j, k;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    double a[n][n + 1];
    double x[n];

    printf("Enter the augmented matrix coefficients:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }

    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (i > j)
            {
                double c = a[i][j] / a[j][j];
                for (k = 0; k < n + 1; k++)
                {
                    a[i][k] = a[i][k] - c * a[j][k];
                }
            }
        }
    }

    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        double sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    printf("Solution for the system of equations:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %.4lf\n", i + 1, x[i]);
    }

    return 0;
}
