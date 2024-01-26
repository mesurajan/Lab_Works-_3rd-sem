// Implementation of bSA line drawing algorithm having +ve slope
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
int main()
{
    int x, y, p, x0, y0, x1, y1, dx, dy, xend;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    printf("Enter the left end points:\n");
    scanf("%d%d", &x0, &y0);
    printf("Enter the right end points:\n");
    scanf("%d%d", &x1, &y1);
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    p = 2 * dy - dx;

    if (x1 > x0)
    {
        x = x0;
        y = y0;
        xend = x1;
    }
    else
    {
        x = x1;
        y = y1;
        xend = x0;
    }
    putpixel(x, y, WHITE);
    while (x < xend)
    {
        x++;
        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        putpixel(x, y, WHITE);
    }
    getch();
    closegraph();
    return 0;
}
