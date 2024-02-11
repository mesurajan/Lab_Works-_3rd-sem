// implementation of DLL
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct DLL
{
    int info;
    struct DLL *next, *prev;
};
struct DLL *head = NULL, *tail = NULL;
void main()
{
    int choice, data, d;
    struct DLL *ptr, *temp;
    do
    {
        printf("\n1.insert at the beginning\n2.insert at the end \n3.insert after a particular node\n4.insert before a particular node\n5.delete first node\n6.delete last node\n7.delete particular node\n8.display\n9.exit\n");
        printf("\n\nMENU :\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {

            // Insert at the beginning
        case 1:
            printf("Enter the data :");
            scanf("%d", &data);
            ptr = (struct DLL *)malloc(sizeof(struct DLL));
            ptr->info = data;
            ptr->next = NULL;
            ptr->prev = NULL;
            if (head == NULL)
            {
                head = ptr;
                tail = ptr;
            }
            else
            {
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
            }
            break;

            // Insert at the end

        case 2:
            printf("Enter your choice :");
            scanf("%d", &data);
            ptr = (struct DLL *)malloc(sizeof(struct DLL));
            ptr->info = data;
            ptr->next = NULL;
            ptr->prev = NULL;
            if (head == NULL)
            {
                head = ptr;
                tail = ptr;
            }
            else
            {
                tail->next = ptr;
                ptr->prev = tail;
                tail = ptr;
            }
            break;

            // Insert at particular node
        case 3:
            printf("Enter your new data to insert :");
            scanf("%d", &data);
            ptr = (struct DLL *)malloc(sizeof(struct DLL));
            ptr->info = data;
            ptr->next = NULL;
            ptr->prev = NULL;

            printf("Enter  the position to insert the node\n");
            scanf("%d", &d);

            temp = head;
            while (temp->info != d && temp != NULL)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("node doesn't exist\n");
            }
            else if (temp->next == NULL)
            {
                temp->next = ptr;
                ptr->prev = temp;
                tail = ptr;
            }
            else
            {
                ptr->next = temp->next;
                temp->next->prev = ptr;
                ptr->prev = temp;
                temp->next = ptr;
            }
            break;
            // Insert before a particular node

        case 4:
            printf("Enter your new data to insert :");
            scanf("%d", &data);
            ptr = (struct DLL *)malloc(sizeof(struct DLL));
            ptr->info = data;
            ptr->next = NULL;
            ptr->prev = NULL;

            printf("Enter  the position before which to insert the node\n");
            scanf("%d", &d);

            temp = head;
            while (temp->info != d && temp != NULL)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("node doesn't exist\n");
            }
            else if (temp == head)
            {
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
            }
            else
            {
                ptr->next = temp;
                ptr->prev = temp->prev;
                temp->prev->next = ptr;
                temp->prev = ptr;
            }
            break;

            // Delete first node
        case 5:
            temp = head;
            if (temp == NULL)
            {
                printf("empty linked list------\n");
            }
            else if (temp->next == NULL)
            {
                head = NULL;
                tail = NULL;
                free(temp);
            }
            else
            {
                head = head->next;
                head->prev = NULL;
                free(temp);
            }
            break;

            // Delete last node
        case 6:
            temp = tail;
            if (temp == NULL)
            {
                printf("empty linked list\n");
            }
            else if (head->next == NULL)
            {
                head = NULL;
                tail = NULL;
                free(temp);
            }
            else
            {
                tail = tail->prev;
                tail->next = NULL;
                free(temp);
            }
            break;

            // Delete particular node
        case 7:
            printf("enter the node you want to delete\n");
            scanf("%d", &d);
            temp = head;
            while (temp->info != d && temp != NULL)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("particular node doesn't exist\n");
            }
            else if (temp == head && temp == tail)
            {
                head = NULL;
                tail = NULL;
                free(temp);
            }
            else if (temp->prev == NULL)
            {
                head = head->next;
                head->prev = NULL;
                free(temp);
            }
            else
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(temp);
            }
            break;

        case 8:
            if (head == NULL)
            {
                printf("\nList is empty\n");
            }
            else
            {
                temp = head;
                while (temp != NULL)
                {
                    printf("<-%d->", temp->info);
                    temp = temp->next;
                }
            }
        }
    } while (choice != 9);
}