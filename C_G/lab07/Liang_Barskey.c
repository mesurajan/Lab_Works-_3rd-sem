#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

int main()
{
    int x1, x2, y1, y2, xmin, ymin, xmax, ymax, xx1, yy1, xx2, yy2, dx, dy, i;
    float t1, t2, p[4], q[4], temp;

    printf("Enter the coordinates of the starting point of the line (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the ending point of the line (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the bottom-left corner of the clipping window (xmin ymin): ");
    scanf("%d %d", &xmin, &ymin);
    printf("Enter the coordinates of the top-right corner of the clipping window (xmax ymax): ");
    scanf("%d %d", &xmax, &ymax);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(x1, y1, x2, y2);
    rectangle(xmin, ymax, xmax, ymin);

    dx = x2 - x1;
    dy = y2 - y1;
    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    for (i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] == 0)
            {
                if (i < 2)
                {
                    if (y1 < ymin)
                    {
                        y1 = ymin;
                    }
                    if (y2 > ymax)
                    {
                        y2 = ymax;
                    }
                }
                else
                {
                    if (x1 < xmin)
                    {
                        x1 = xmin;
                    }
                    if (x2 > xmax)
                    {
                        x2 = xmax;
                    }
                }
                setcolor(RED);
                line(x1, y1, x2, y2);
            }
        }
    }

    t1 = 0;
    t2 = 1;
    for (i = 0; i < 4; i++)
    {
        temp = q[i] / p[i];
        if (p[i] < 0)
        {
            if (t1 <= temp)
            {
                t1 = temp;
            }
        }
        else
        {
            if (t2 >= temp)
            {
                t2 = temp;
            }
        }
    }

    if (t1 < t2)
    {
        xx1 = x1 + t1 * p[1];
        xx2 = x1 + t2 * p[1];
        yy1 = y1 + t1 * p[3];
        yy2 = y1 + t2 * p[3];
        setcolor(RED);
        line(xx1, yy1, xx2, yy2);
    }

    getch();
    closegraph();
    return 0;
}
/*
(x1,y1)=60,100
(y2,y2)=140,250
(xmin,ymin)=0,0
(xmax,ymax)=150,150
*/