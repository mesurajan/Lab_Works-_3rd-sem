// scaling

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int gd = DETECT, gm, i, j, k, x_1, y_1, x_2, y_2, X, Y;
    int x1 = 0, y1 = 0, x2 = 100, y2 = 100;
    float transform_matrix[3][3] = {2, 0, 0, 0, 2, 0, 0, 0, 1};
    float actual_pts[3][2] = {x1, x2, y1, y2, 1, 1};
    float transformed_pts[3][2] = {0};
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    X = getmaxx();
    Y = getmaxy();
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transformed_pts[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                transformed_pts[i][j] = transformed_pts[i][j] + transform_matrix[i][k] * actual_pts[k][j];
            }
        }
    }
    x_1 = int(transformed_pts[0][0]);
    y_1 = int(transformed_pts[1][0]);
    x_2 = int(transformed_pts[0][1]);
    y_2 = int(transformed_pts[1][1]);
    setcolor(RED);
    line(0, Y / 2, X, Y / 2);
    line(X / 2, 0, X / 2, Y);
    setcolor(15);
    rectangle(x1 + X / 2, y1 + Y / 2, x2 + X / 2, y2 + Y / 2);
    setcolor(3);
    rectangle(x_1 + X / 2, y_1 + Y / 2, x_2 + X / 2, y_2 + Y / 2);
    getch();
    closegraph();
}