#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// O(n)-O(n^2) (avg-worst)
int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

// O(n log n)-O(n^2) (avg-worst)
void quickSort(int *a, int low, int high)
{ // Not stable
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        // printArray(a, 6); // print the changes evetytime swap happens
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}