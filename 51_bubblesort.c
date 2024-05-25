#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort1(int *a, int n) // O(n^2)
{
    // Basic Bubble Sort algorithm
    int temp;
    for (int i = 0; i < n; i++)
    {
        printf("Pass %d\n", i+1);
        for (int j = 0; j < n; j++)
        {
            if (a[j] > a[i]) // a[j] < a[i] descending order
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void bubbleSort2(int *a, int n) // O(n^2)
{
    // Adaptive Bubble Sort algorithm
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Pass %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j+1])  // a[j] < a[j+1] descending order
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

int main()
{
    int arr1[] = {12, 54, 7, 65, 7, 23, 9};
    int n1 = sizeof(arr1) / sizeof(int);
    
    bubbleSort1(arr1, n1); // maintains order of elements
    printArray(arr1, n1);

    int arr2[] = {59, 39, 69, 34, 20, 34, 60};
    int n2 = sizeof(arr2) / sizeof(int);
    
    bubbleSort2(arr2, n2);
    printArray(arr2, n2);
    return 0;
}