// Implementation of midpoint  circle algorithms x-sampling
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
    y = rd;
    p0 = 1 - rd;
    while (x <= y)
    {
        x = x + 1;

        putpixel(x + h, y + k, RED);
        putpixel(-x + h, y + k, RED);
        putpixel(x + h, -y + k, RED);
        putpixel(-x + h, -y + k, RED);

        putpixel(y + h, x + k, RED);
        putpixel(-y + h, x + k, RED);
        putpixel(y + h, -x + k, RED);
        putpixel(-y + h, -x + k, RED);
        if (p0 < 0)
        {
            p0 = p0 + 2 * x + 1;
            x = x + 1;
        }
        else
        {
            p0 = p0 + 2 * x + 1 - 2 * y;
            y = y - 1;
        }
    }
    getch();
    closegraph();
}
