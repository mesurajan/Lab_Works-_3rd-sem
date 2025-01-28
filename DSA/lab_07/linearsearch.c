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
    printf("Enter the element to search using Linear Search: ");
    scanf("%d", &target);

    // Perform linear search!
    int result = -1; // Assume not found
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            result = i; // Element found at index i
            break;
        }
    }

    // Print the result
    if (result != -1)
    {
        printf("Element %d found at index %d\n", target, result);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
