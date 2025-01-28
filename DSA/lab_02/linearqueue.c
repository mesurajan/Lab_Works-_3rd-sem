#include <stdio.h>
#define n 5
int main()
{
    int c, rear = -1, front = 0, new_data, temp, i, myqueue[n];
    do
    {
        printf("\nMenu\n1.Enque\n2.DEque\n3.Display\n4.Exit\nEnter your choice\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            if (rear == n - 1)
            {
                printf("queue overflow");
            }

            else if (rear == -1)
            {
                front = 0;
                rear = 0;
                printf("Enter the element you want to push  in queue:\n");
                scanf("%d", &new_data);
                myqueue[rear] = new_data;
            }
            else
            {
                rear++;
                printf("Enter the datat to be pushed ");
                scanf("%d", &new_data);
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
                front = -1;
                rear = -1;
                temp = myqueue[front];
                printf("deleted element is:%d ", temp);
            }
            else
            {
                front++;
                temp = myqueue[front];
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