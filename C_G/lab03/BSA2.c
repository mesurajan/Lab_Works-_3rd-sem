// Implementation of bSA line drawing algorithm having -ve slope
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
int main()
{
    int x, y, p, x0, y0, x1, y1, dx, dy, yend;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    printf("Enter the left end points:\n");
    scanf("%d%d", &x0, &y0);
    printf("Enter the right end points:\n");
    scanf("%d%d", &x1, &y1);
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    p = 2 * dx - dy;

    if (y1 > y0)
    {
        x = x0;
        y = y0;
        yend = y1;
    }
    else
    {
        x = x1;
        y = y1;
        yend = y0;
    }
    putpixel(x, y, WHITE);
    while (y < yend)
    {
        y++;
        if (p < 0)
        {
            p = p + 2 * dx;
        }
        else
        {
            x++;
            p = p + 2 * dx - 2 * dy;
        }
        putpixel(x, y, WHITE);
    }
    getch();
    closegraph();
    return 0;
}
