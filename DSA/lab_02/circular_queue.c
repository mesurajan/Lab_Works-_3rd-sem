// Implementation of circular queue
#include <stdio.h>
#include <conio.h>
#define n 5
int main()
{
    int c, rear = -1, front = -1, new_data, myqueue[n], temp, front_temp, rear_temp, i;
    do
    {
        printf("\nMENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit:\n Enter the task you want to perform\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            if ((front == 0 && rear == n - 1) || (front == (rear + 1) % n))
            {
                printf("Queue Overflow........\n");
                break;
            }
            else if (front == -1 && rear == -1)
            {
                front = 0;
                rear = 0;
                printf("Enter the number you want to enqueue:\n");
                scanf("%d", &new_data);
                myqueue[rear] = new_data;
            }
            else
            {
                rear = (rear + 1) % n;
                printf("Enter the number you want to enqueue:\n");
                scanf("%d", &new_data);
                myqueue[rear] = new_data;
            }
            break;
        case 2:
            if (front = -1 && rear == -1)
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
                front = (front + 1) % n;
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
                    for (i = front_temp; i < n; i++)
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
    } while (c < 4);
    return 0;
}
