// Implementation of DDA line drawing algorithms
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
void drawLineDDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;
    float x = x1, y = y1;
    int i;
    for (i = 0; i <= steps; i++)
    {
        putpixel(x, y, WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}
void main()
{
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 150, y2 = 180;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");

    drawLineDDA(x1, y1, x2, y2);
    getch();
    closegraph();
}