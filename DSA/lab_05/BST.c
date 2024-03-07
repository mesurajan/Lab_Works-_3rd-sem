#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int info;
    struct BST *right, *left;
};
struct BST *root = NULL;

void insert(struct BST **root, int data)
{
    if (*root == NULL)
    {
        *root = (struct BST *)malloc(sizeof(struct BST));
        (*root)->info = data;
        (*root)->left = (*root)->right = NULL;
    }
    else if (data <= (*root)->info)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);
}

void inorder(struct BST *r)
{
    if (r == NULL)
        return;

    inorder(r->left);
    printf("%d ", r->info);
    inorder(r->right);
}

void preorder(struct BST *r)
{
    if (r == NULL)
        return;

    printf("%d ", r->info);
    preorder(r->left);
    preorder(r->right);
}

void postorder(struct BST *r)
{
    if (r == NULL)
        return;

    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->info);
}

int main()
{
    int num, data;
    struct BST *ptr;

    do
    {
        printf("\n Menu :\n1.Insert in the tree :\n2.Inorder Traversal : \n3.Preorder Treversal : \n4.Postorder Treversal:\n5.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(&root, data);
            break;

        case 2:
            if (root == NULL)
            {
                printf("The tree is empty\n");
                break;
            }

            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            if (root == NULL)
            {
                printf("The tree is empty\n");
                break;
            }

            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            if (root == NULL)
            {
                printf("The tree is empty\n");
                break;
            }

            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}