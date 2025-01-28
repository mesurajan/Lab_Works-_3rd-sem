// Implementation of queue
#include <stdio.h>
#include <stdlib.h>
#define n 5
int main()
{
    int c, rear = -1, myqueue[n], new_data, temp, i, front = -1;
    do
    {
        printf("Enter your choice\n1.Enque\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if (rear == n - 1)
            {
                printf("\nQueue overflow\n");
            }
            else if (rear == -1)
            {
                printf("\n Enter the new data to be Pushed\n");
                scanf("%d", &new_data);
                front = 0;
                rear = 0;
                myqueue[rear] = new_data;
            }
            else
            {
                printf("\n Enter new data to be pushed\n");
                scanf("%d", &new_data);
                rear++;
                myqueue[rear] = new_data;
            }
            break;
        case 2:
            if (front == -1)
            {
                printf("\n underflow");
            }
            else if (front == rear)

            {
                temp = myqueue[front];
                printf("\n Deleted Element=%d\n", temp);
                front = -1;
                rear = -1;
            }
            else
            {
                temp = myqueue[front];
                front++;
                printf("\n Deleted Elements=%d\n", temp);
            }
            break;
        case 3:
            if (rear == -1)
            {
                printf("\n Queue underflow\n");
            }
            else
            {
                for (i = front; i <= rear; i++)
                {
                    printf("%d\t", myqueue[i]);
                }
            }
        default:
            printf("\n Enter the value again");
        }
    } while (c < 4);
    return 0;
}