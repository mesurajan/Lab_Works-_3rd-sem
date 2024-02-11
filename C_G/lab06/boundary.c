//// Implementation of filling algorithm for boundary fill

#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
void boundary_fill(int x, int y, int fill_color, int boundary_color, int default_color)
{
    int current_color = getpixel(x, y);
    if (current_color != boundary_color && current_color != fill_color)
    {
        delay(5);
        putpixel(x, y, fill_color);
        boundary_fill(x + 1, y, fill_color, boundary_color, default_color);
        boundary_fill(x - 1, y, fill_color, boundary_color, default_color);
        boundary_fill(x, y + 1, fill_color, boundary_color, default_color);
        boundary_fill(x, y - 1, fill_color, boundary_color, default_color);
    }
}
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
    boundary_fill(h, k, 3, 15, 0);
    getch();
    return 0;
}
