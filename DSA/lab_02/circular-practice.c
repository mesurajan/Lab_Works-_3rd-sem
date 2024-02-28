#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define n 5
int main()
{
    int c, rear = -1, front = -1, new_data, temp, max, front_temp, rear_temp, i, myqueue[n];
    do
    {
        printf("\nMenu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:\n");
        scanf("%d", &c);

        switch (c)
        {

        case 1:
            if ((front == 0 && rear == max - 1) || (front == (rear + 1) % max))
            {

                printf("overflow\n");
            }
            else if (front == -1 && rear == -1)
            {
                printf("enter the data you wanat to enqueue:\n");
                scanf("%d", new_data);
                front = 0;
                rear = 0;
                myqueue[rear] = new_data;
            }
            else
            {
                printf("Enter ten you want to enqueue:\n");
                scanf("%d", new_data);
                rear = (rear + 1) % max;
                myqueue[rear] = new_data;
            }
            break;

        case 2:
            if (front == -1 && rear == -1)
            {
                printf("underflow\n");
            }
            else if (front == rear)
            {
                temp = myqueue[front];
                front = -1;
                rear = -1;
                printf("deleted element is:%d", temp);
            }
            else
            {
                temp = myqueue[front];
                front = (front + 1) % max;
                printf("Deleted element is :%d", temp);
            }
            break;

        case 3:
            front_temp = front;
            rear_temp = rear;
            if (front_temp != -1)

            {
                if (front_temp <= rear_temp)
                {
                    printf("Elements of circular queue\n");
                    for (i = front_temp; i <= rear_temp; i++)
                    {
                        printf("%d", myqueue[i]);
                    }
                }
                else
                {
                    for (i = front_temp; i < max; i++)
                    {
                        printf("%d", myqueue[i]);
                    }
                    for (i = 0; i <= rear_temp; i++)
                    {
                        printf("%d", myqueue[i]);
                    }
                }
            }
            printf("Underflow\n");
        }
    } while (c < 4);
    return 0;
}
