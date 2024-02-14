#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int info;
    struct SLL *next;
};

struct SLL *head = NULL;

int main()
{
    int choice, data, d;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a particular node\n");
        printf("4. Insert before a particular node\n");
        printf("5. Delete first node\n");
        printf("6. Delete last node\n");
        printf("7. Delete particular node\n");
        printf("8. Delete SLL at position\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            // Insert at beginning
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            struct SLL *ptr1 = (struct SLL *)malloc(sizeof(struct SLL));
            ptr1->info = data;
            ptr1->next = head;
            head = ptr1;
            break;
            // Insert at end
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            struct SLL *ptr2 = (struct SLL *)malloc(sizeof(struct SLL));
            ptr2->info = data;
            ptr2->next = NULL;
            if (head == NULL)
            {
                head = ptr2;
            }
            else
            {
                struct SLL *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = ptr2;
            }
            break;
            // Insert after a particular node
        case 3:
            printf("Enter the new data to insert: ");
            scanf("%d", &data);
            printf("Enter the node data after which to insert: ");
            scanf("%d", &d);
            struct SLL *ptr3 = (struct SLL *)malloc(sizeof(struct SLL));
            ptr3->info = data;
            struct SLL *temp3 = head;
            while (temp3 != NULL && temp3->info != d)
            {
                temp3 = temp3->next;
            }
            if (temp3 == NULL)
            {
                printf("Node with key %d not found\n", d);
            }
            else
            {
                ptr3->next = temp3->next;
                temp3->next = ptr3;
            }
            break;
            // Insert before a particular node
        case 4:
            printf("Enter the new data to insert: ");
            scanf("%d", &data);
            printf("Enter the node data before which to insert: ");
            scanf("%d", &d);
            struct SLL *ptr4 = (struct SLL *)malloc(sizeof(struct SLL));
            ptr4->info = data;
            struct SLL *temp4 = head;
            struct SLL *prev4 = NULL;
            while (temp4 != NULL && temp4->info != d)
            {
                prev4 = temp4;
                temp4 = temp4->next;
            }
            if (temp4 == NULL)
            {
                printf("Node with key %d not found\n", d);
            }
            else
            {
                if (prev4 == NULL)
                {
                    ptr4->next = head;
                    head = ptr4;
                }
                else
                {
                    ptr4->next = temp4;
                    prev4->next = ptr4;
                }
            }
            break;
            // Delete first node
        case 5:
            if (head == NULL)
            {
                printf("Empty linked list\n");
            }
            else
            {
                struct SLL *temp5 = head;
                head = head->next;
                free(temp5);
            }
            break;
            // Delete last node
        case 6:
            if (head == NULL)
            {
                printf("Empty linked list\n");
            }
            else if (head->next == NULL)
            {
                free(head);
                head = NULL;
            }
            else
            {
                struct SLL *temp6 = head;
                while (temp6->next->next != NULL)
                {
                    temp6 = temp6->next;
                }
                free(temp6->next);
                temp6->next = NULL;
            }
            break;
            // Delete particular node
        case 7:
            printf("Enter the node data to delete: ");
            scanf("%d", &d);
            if (head == NULL)
            {
                printf("Empty linked list\n");
            }
            else
            {
                struct SLL *temp7 = head;
                struct SLL *prev7 = NULL;
                while (temp7 != NULL && temp7->info != d)
                {
                    prev7 = temp7;
                    temp7 = temp7->next;
                }
                if (temp7 == NULL)
                {
                    printf("Node with key %d not found\n", d);
                }
                else
                {
                    if (prev7 == NULL)
                    {
                        head = head->next;
                    }
                    else
                    {
                        prev7->next = temp7->next;
                    }
                    free(temp7);
                }
            }
            break;
            // Delete SLL at position
        case 8:
            printf("Enter the position of the SLL to delete: ");
            scanf("%d", &d);
            if (d < 1)
            {
                printf("Invalid position\n");
            }
            else if (d == 1)
            {
                struct SLL *temp8 = head;
                head = head->next;
                free(temp8);
            }
            else
            {
                struct SLL *temp8 = head;
                struct SLL *prev8 = NULL;
                int count = 1;
                while (temp8 != NULL && count != d)
                {
                    prev8 = temp8;
                    temp8 = temp8->next;
                    count++;
                }
                if (temp8 == NULL)
                {
                    printf("Position exceeds the size of the list\n");
                }
                else
                {
                    prev8->next = temp8->next;
                    free(temp8);
                }
            }
            break;
            // Display
        case 9:
            if (head == NULL)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("Elements in the list are: ");
                struct SLL *temp9 = head;
                while (temp9 != NULL)
                {
                    printf("%d ", temp9->info);
                    temp9 = temp9->next;
                }
                printf("\n");
            }
            break;

        case 10:
            exit(0); // Exit from program
        }
    } while (choice != 10);
    return 0;
}