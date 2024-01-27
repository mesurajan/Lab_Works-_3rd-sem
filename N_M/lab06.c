// power method to find largest eigen value and corresponding eigen value
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10

void matrixVectorMultiply(double A[MAX_SIZE][MAX_SIZE], double X[MAX_SIZE], double result[MAX_SIZE], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        result[i] = 0;
        for (j = 0; j < n; j++)
        {
            result[i] += A[i][j] * X[j];
        }
    }
}
int findMaxIndex(double array[MAX_SIZE], int n)
{
    int i, maxIndex = 0;
    for (i = 1; i < n; i++)
    {
        if (fabs(array[i]) > fabs(array[maxIndex]))
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main()
{
    int n, i, j, maxIndex;
    double A[MAX_SIZE][MAX_SIZE], X[MAX_SIZE], Y[MAX_SIZE], eigenvalue, epsilon, kn, kn_minus_1;

    // Input size of the matrix
    printf("Enter the size of the matrix (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Input matrix A
    printf("Enter the matrix A:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter initial eigenvalue (kn): ");
    scanf("%lf", &kn);
    printf("Enter stopping criteria (epsilon): ");
    scanf("%lf", &epsilon);

    do
    {
        matrixVectorMultiply(A, X, Y, n);

        maxIndex = findMaxIndex(Y, n);

        kn_minus_1 = kn;
        kn = Y[maxIndex];
        for (i = 0; i < n; i++)
        {
            X[i] = Y[i] / kn;
        }

    } while (fabs(kn - kn_minus_1) > epsilon);

    printf("\nDominant Eigenvalue: %lf\n", kn);
    printf("Corresponding Eigenvector: [");
    for (i = 0; i < n; i++)
    {
        printf("%lf ", X[i]);
    }
    printf("]\n");

    return 0;
}
// time to push data in git repo