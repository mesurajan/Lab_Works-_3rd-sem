// Implementation of stack
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define n 5
int main()
{
    int c, tos = -1, mystack[n], new_data, temp, i;
    do
    {
        printf("Enter your choice\n1.Push \n2.Pop \n3.Display \n4.Exit \n");
        printf("----------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if (tos == n - 1)
            {
                printf("\n Stack Overflow\n");
            }

            else
            {
                printf("\n Enter new data to be punished\n");
                scanf("%d", &new_data);
                tos++;
                mystack[tos] = new_data;
            }
            break;
        case 2:
            if (tos == -1)
            {
                printf("\n Stack underflow");
            }
            else
            {
                temp = mystack[tos];
                tos--;
                printf("\n Popped element =%d\n", temp);
            }
            break;
        case 3:
            if (tos == -1)
            {
                printf("\n Stack undreflow\n");
            }
            else
            {
                for (i = tos; i >= 0; i++)
                {
                    printf("%d\t", mystack[i]);
                }
            }
        default:
            printf("\n Enter the value again");
        }
    } while (c < 4);
    return 0;
}