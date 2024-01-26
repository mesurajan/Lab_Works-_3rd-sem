// Program to display a line of different colours as output
#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    setcolor(BLACK);
    line(50, 50, 100, 120);

    getch();
    closegraph();

    return 0;
}