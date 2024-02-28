#include <stdio.h>
#define n 5
int main()
{
    int c, rear = -1, front = -1, new_data, temp, i, myqueue[n];
    do
    {
        printf("\nMenu\n1.Enque\n2.DEque\n3.Display\n4.Exit\nEnter your choice\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            if (rear == n - 2)
            {
                printf("queue overflow");
            }

            else if (rear == -1)
            {
                printf("Enter the element you want to push  in queue:\n");
                scanf("%d", new_data);
                front = 0;
                rear = 0;
                myqueue[rear] = new_data;
            }
            else
            {
                printf("Enter the datat to be pushed ");
                scanf("%d", new_data);
                rear++;
                myqueue[rear] = new_data;
            }
            break;

        case 2:

            if (front == -1)
            {
                printf("queue underflow");
            }
            else if (front == rear)
            {
                temp = myqueue[front];
                front = -1;
                rear = -1;
                printf("deleted element is:%d ", temp);
            }
            else
            {
                temp = myqueue[front];
                front++;
                printf("Deleted element is :%d", temp);
            }
            break;

        case 3:

            if (rear == -1)
            {

                printf("queue underflow");
            }
            else
            {

                for (i = front; i <= rear; i++)
                {

                    printf("%d\t", myqueue[i]);
                }
            }
        default:
            printf("enter the value again");
        }
    } while (c < 4);

    return 0;
}