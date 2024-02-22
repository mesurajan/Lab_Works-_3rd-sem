// implementation of circular linked list
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Cll
{
    int info;
    struct Cll *next, *previous;
};
struct Cll *head = NULL, *tail = NULL;

int main()
{
    int num, data, d;
    struct Cll *ptr, *temp;

    // Main loop for input
    do
    {
        printf("\n1. Insert at the beginning\n2. Insert at the end \n3. Delete first node\n4. Delete last node\n5. Display\n6. Exit\n");
        printf("Enter the number of the operation: ");
        scanf("%d", &num);

        switch (num)
        {

            // Insert at beginning
        case 1:
            printf("Enter the data you want to insert (from the beginning): ");
            scanf("%d", &data);

            ptr = (struct Cll *)malloc(sizeof(struct Cll));
            ptr->info = data;
            ptr->next = ptr;
            ptr->previous = ptr;

            if (head == NULL)
            {
                head = ptr;
                tail = ptr;
            }
            else
            {
                ptr->next = head;
                head->previous = ptr;
                head = ptr;
                head->previous = tail;
                tail->next = head;
            }
            break;
            // insert at the end
        case 2:
            printf("Enter the data you want to insert (from the end): ");
            scanf("%d", &data);

            ptr = (struct Cll *)malloc(sizeof(struct Cll));
            ptr->info = data;

            if (head == NULL)
            {
                head = ptr;
                tail = ptr;
                head->next = head;
                head->previous = head;
                tail->next = head;
                tail->previous = tail;
            }
            else
            {
                ptr->previous = tail;
                tail->next = ptr;
                tail = ptr;
                head->previous = tail;
                tail->next = head;
            }
            break;
            // Delete first node
        case 3:

            if (head == NULL)
            {
                printf("List is empty\n");
                return 0;
            }

            if (head == tail) // Check if there is only one node in the list
            {
                free(head);
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp = head;
                head = head->next;
                head->previous = tail;
                tail->next = head;
                free(temp);
            }
            break;
            // Delete last node
        case 4:

            if (head == NULL)
            {
                printf("List is empty\n");
                return 0;
            }
            if (head == tail) // Check if there is only one node in the list
            {
                free(head);
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp = tail;
                tail = tail->previous;
                tail->next = head;
                head->previous = tail;
                free(temp);
            }
            break;
            // Display
        case 5:
            if (head == NULL)
            {
                printf("List is empty\n");
                return 0;
            }

            ptr = head;
            do
            {
                printf("<--%d--> ", ptr->info);
                ptr = ptr->next;
            } while (ptr != head);
            printf("\n");
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid operation\n");
            break;
        }
    } while (num != 6);

    return 0;
}