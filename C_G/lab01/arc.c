// Program to display an arc as output
#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    arc(200, 230, 0, 90, 270);

    getch();
    closegraph();

    return 0;
}