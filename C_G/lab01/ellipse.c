// Program to display an ellipse as output
#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:/TURBOC3/BGI");
    ellipse(70, 100, 0, 360, 90, 60);

    getch();
    closegraph();

    return 0;
}