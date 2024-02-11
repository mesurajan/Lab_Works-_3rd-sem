// Implementation of filling algorithm
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>

void fill(int, int, int, int);
int main()
{
    int h, k, xc, yc, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter the center of circle:\n ");
    scanf("%d%d", &h, &k);
    printf("Enter the radius of circle:\n ");
    scanf("%d", &r);
    circle(h, k, r);
    fill(h, k, 4, 0);

    getch();
    return 0;
}
void fill(int x, int y, int fill_color, int default_color)
{
    if (getpixel(x, y) == default_color)
    {
        delay(5);
        putpixel(x, y, fill_color);
        fill(x + 1, y, fill_color, default_color);
        fill(x - 1, y, fill_color, default_color);
        fill(x, y + 1, fill_color, default_color);
        fill(x, y - 1, fill_color, default_color);
    }
}
// points to be 200 300 20