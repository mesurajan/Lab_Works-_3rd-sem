// Program to display a rectangle as output
#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    rectangle(50, 450, 350, 450);

    getch();
    closegraph();

    return 0;
}