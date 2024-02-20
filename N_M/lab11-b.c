// Newton's Backward Difference

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

void main()
{
    int n = 0;
    printf("Please Enter the number of values: ");
    scanf("%d", &n);
    float x[n], y[n][n];
    printf("Please enter the values of x:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Please enter the values of y:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &y[i][0]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    printf("Displaying the backward difference table.....\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%0.2f\t\t", x[i]);
        for (int j = 0; j <= i; j++)
            printf("%0.2f\t\t", y[i][j]);

        printf("\n");
    }

    float value = 0;
    printf("Please enter the value of f\n");
    scanf("%f", &value);

    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
    {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) /
                        fact(i);
    }

    printf("Value at %0.4f is %0.4f\n", value, sum);
}
/*

Please Enter the number of values: 7
Please enter the values of x:
100
150
200
250
300
350
400
Please enter the values of y:
10.63
13.03
15.04
16.81
18.42
19.9
21.27
Displaying the backward difference table.....

100.00          10.63
150.00          13.03           2.40
200.00          15.04           2.01            -0.39
250.00          16.81           1.77            -0.24           0.15
300.00          18.42           1.61            -0.16           0.08            -0.07
350.00          19.90           1.48            -0.13           0.03            -0.05           0.02
400.00          21.27           1.37            -0.11           0.02            -0.01           0.04            0.02
Please enter the value of f
410
Value at 410.0000 is 21.5352
*/