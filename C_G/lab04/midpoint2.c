// Implementation of midpoint  circle algorithms y-sampling
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
void main()
{
    int rd, h, k, x = 0, y, p0;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    printf("Enter the radius of circle:\n");
    scanf("%d", &rd);
    printf("Enter the centre of the circle(h,k):\n");
    scanf("%d%d", &h, &k);
    x = rd;
    p0 = 1 - rd;
    while (x >= y)
    {
        y = y + 1;

        putpixel(x + h, y + k, WHITE);
        putpixel(-x + h, y + k, WHITE);
        putpixel(x + h, -y + k, WHITE);
        putpixel(-x + h, -y + k, WHITE);

        putpixel(y + h, x + k, WHITE);
        putpixel(-y + h, x + k, WHITE);
        putpixel(y + h, -x + k, WHITE);
        putpixel(-y + h, -x + k, WHITE);
        if (p0 < 0)
        {
            p0 = p0 + 2 * y + 1;
        }
        else
        {
            p0 = p0 + 2 * y + 1 - 2 * x;
            x = x - 1;
        }
    }
    getch();
    closegraph();
}
