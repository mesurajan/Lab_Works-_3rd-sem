// Program to display a circle as output
#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    circle(80, 80, 80);

    getch();
    closegraph();

    return 0;
}