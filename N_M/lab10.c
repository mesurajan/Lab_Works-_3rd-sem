// Guass jordan method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void swap_rows(double a[][100], int i, int j, int n)
{
    double temp;
    for (int k = 0; k < n; k++)
    {
        temp = a[i][k];
        a[i][k] = a[j][k];
        a[j][k] = temp;
    }
}

void guass_jordan(double a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i][i] == 0)

        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j][i] != 0)
                {
                    swap_rows(a, i, j, n);
                    break;
                }
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            double ratio = a[j][i] / a[i][i];
            for (int k = 0; k < n + 1; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
}

int main()
{
    int n, i, j, k;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    double a[100][100];
    double x[100];

    printf("Enter the augmented matrix coefficients:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }

    guass_jordan(a, n);

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