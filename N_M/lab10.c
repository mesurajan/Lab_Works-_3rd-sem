// Lagrange's interpolation

#include <stdio.h>
#include <conio.h>
void main()
{
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;
    /* Input Section */
    printf("Enter number of data: ");
    scanf("%d", &n);
    printf("Enter data:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    printf("Enter interpolation point: ");
    scanf("%f", &xp);
    /* Implementing Lagrange Interpolation */
    for (i = 1; i <= n; i++)
    {
        p = 1;
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }
    printf("Interpolated value at %.3f is %.3f.", xp, yp);
    getch();
}
/*
  OUTPUT :

Enter number of data: 5
Enter data:
x[1] = 5
y[1] = 150
x[2] = 7
y[2] = 392
x[3] = 11
y[3] = 1452
x[4] = 13
y[4] = 2366
x[5] = 17
y[5] = 5202
Enter interpolation point: 9
Interpolated value at 9.000 is 810.000.


*/