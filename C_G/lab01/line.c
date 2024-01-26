// Program to display a line as output
#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    line(50, 50, 100, 120);

    getch();
    closegraph();

    return 0;
}