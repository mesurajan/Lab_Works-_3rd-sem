/*
searching ion dsa using c language:
*Linear searching
*Binary searching

*/
#include <stdio.h>

void acceptArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];
    acceptArray(arr, n);

    int choice;
    while (1)
    {
        printf("\n1. Linear Search\n2. Binary Search\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int target;
            printf("Enter the element to search using Linear Search: ");
            scanf("%d", &target);

            int result = linearSearch(arr, n, target);
            if (result != -1)
                printf("Element %d found at index %d\n", target, result);
            else
                printf("Element %d not found in the array\n", target);
        }
        else if (choice == 2)
        {
            int left = 0, right = n - 1;
            int target_sorted;
            printf("Enter the element to search using Binary Search: ");
            scanf("%d", &target_sorted);

            // Sort the array before binary search
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            // Perform Binary Search after sorting the array
            int index = binarySearch(arr, left, right, target_sorted);
            if (index != -1)
                printf("Sorted array: Element %d found at index %d\n", target_sorted, index);
            else
                printf("Sorted array: Element %d not found in the array\n", target_sorted);
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            printf("Invalid choice! Please choose from the given options.\n");
        }
    }

    return 0;
}