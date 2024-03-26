#include <stdio.h>

// Function prototypes
void quickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void bubbleSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Original array\n");
        printf("2. Quick Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Selection Sort\n");
        printf("6. Insertion Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Original array: ");
            printArray(arr, n);
            break;
        case 2:
        {
            int arr1[n];
            for (int i = 0; i < n; i++)
                arr1[i] = arr[i];
            quickSort(arr1, 0, n - 1);
            printf("Quick sorted array: ");
            printArray(arr1, n);
            break;
        }
        case 3:
        {
            int arr2[n];
            for (int i = 0; i < n; i++)
                arr2[i] = arr[i];
            bubbleSort(arr2, n);
            printf("Bubble sorted array: ");
            printArray(arr2, n);
            break;
        }
        case 4:
        {
            int arr3[n];
            for (int i = 0; i < n; i++)
                arr3[i] = arr[i];
            mergeSort(arr3, 0, n - 1);
            printf("Merge sorted array: ");
            printArray(arr3, n);
            break;
        }
        case 5:
        {
            int arr4[n];
            for (int i = 0; i < n; i++)
                arr4[i] = arr[i];
            selectionSort(arr4, n);
            printf("Selection sorted array: ");
            printArray(arr4, n);
            break;
        }
        case 6:
        {
            int arr5[n];
            for (int i = 0; i < n; i++)
                arr5[i] = arr[i];
            insertionSort(arr5, n);
            printf("Insertion sorted array: ");
            printArray(arr5, n);
            break;
        }
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}

// Quick Sort
void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi - 1); // Before pi
        quickSort(arr, pi + 1, r); // After pi
    }
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return (i + 1);
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
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
}

// Merge Sort
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
