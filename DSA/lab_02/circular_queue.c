// Implementation of circular queue
#include <stdio.h>
#include <conio.h>
#define max 5
int main()
{
    int n1, rear = -1, front = -1, n2, myqueue[max], temp, front_temp, rear_temp, i;
    do
    {
        printf("\n Enter the task you want to perform\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit:\n");
        scanf("%d", &n1);
        switch (n1)
        {
        case 1:
            if ((front == 0 && rear == max - 1) || (front == (rear + 1) % max))
            {
                printf("Queue Overflow........\n");
                break;
            }
            else if (front == -1 && rear == -1)
            {
                front = 0;
                rear = 0;
                printf("Enter the number you want to enqueue:\n");
                scanf("%d", &n2);
                myqueue[rear] = n2;
            }
            else
            {
                rear = (rear + 1) % max;
                printf("Enter the number you want to enqueue:\n");
                scanf("%d", &n2);
                myqueue[rear] = n2;
            }
            break;
        case 2:
            if (front == -1 && rear == -1)
            {
                printf("Queue Underflow..........\n");
                break;
            }
            else if (front == rear)
            {
                temp = myqueue[front];
                front = -1;
                rear = -1;
                printf("The deleted data is %d\n", temp);
            }
            else
            {
                temp = myqueue[front];
                front = (front + 1) % max;
                printf("The deleted data is %d\n", temp);
            }
            break;
        case 3:
            front_temp = front;
            rear_temp = rear;
            if (front_temp != -1)
            {
                if (front_temp <= rear_temp)
                {
                    printf("Item at Circular Queue\n");
                    for (i = front_temp; i <= rear_temp; i++)
                    {
                        printf("%d\t", myqueue[i]);
                    }
                }
                else
                {
                    for (i = front_temp; i < max; i++)
                    {
                        printf("%d\t", myqueue[i]);
                    }
                    for (i = 0; i <= rear_temp; i++)
                    {
                        printf("%d\t", myqueue[i]);
                    }
                }
            }
            printf("Queue Underflow............\n");
        }
    } while (n1 != 4);
    return 0;
}
