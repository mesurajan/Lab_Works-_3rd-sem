#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void drawEllipse(int, int, int, int);
int main()
{
    long xc, yc, rx, ry, x, y, p, p1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter the center(x,y) of the ellipse:");
    scanf("%ld%ld", &xc, &yc);
    printf("Enter the major and minor radius(rx,ry) of the ellipse:");
    scanf("%ld%ld", &rx, &ry);
    x = 0;
    y = ry;
    drawEllipse(x, y, xc, yc);

    p = (ry * ry) - (rx * rx * ry) + (rx * rx * (1 / 4));
    while ((2 * ry * ry * x) < (2 * rx * rx * y))

    {

        if (p < 0)
        {
            x = x + 1;
            y = y;
            p = p + (2 * ry * ry * x) + (ry * ry);
            drawEllipse(x, y, xc, yc);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + (2 * ry * ry * x) + (ry * ry) - (2 * rx * rx * y);
            drawEllipse(x, y, xc, yc);
        }
    }
    p1 = (ry * ry) * ((float)(x + 0.5)) * ((float)(x + 0.5)) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx * ry * ry);

    while (y > 0)
    {
        if (p1 > 0)
        {
            x = x + 1;
            y = y - 1;
            p1 = p1 - (2 * rx * rx * y) + (rx * rx * y);
            drawEllipse(x, y, xc, yc);
        }

        else
        {
            x = x + 1;
            y = y - 1;

            p1 = p1 + (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
            drawEllipse(x, y, xc, yc);
        }
    }

    getch();
    closegraph();
    return 0;
}
void drawEllipse(int x, int y, int xc, int yc)
{
    putpixel(xc + x, yc + y, 4);

    putpixel(xc + x, yc - y, 4);
    putpixel(xc - x, yc + y, 4);
    putpixel(xc - x, yc - y, 4);
}