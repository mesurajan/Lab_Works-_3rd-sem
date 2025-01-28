#include <stdio.h>

int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];

    // Accept array elements
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        }

    int target;
    printf("Enter the element to search using Binary Search: ");
    scanf("%d", &target);

    // Sort the array before binary search (Bubble Sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Binary Search function implemented inside main
    int l = 0, r = n - 1, index = -1;
    while (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
        {
            index = mid; // Element found at index mid
            break;
        }

        if (arr[mid] > target)
        {
            r = mid - 1; // Search in the left subarray
        }
        else
        {
            l = mid + 1; // Search in the right subarray
        }
    }

    // Print the sorted array (for clarity)
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the result
    if (index != -1)
    {
        printf("Element %d found at index %d\n", target, index);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
