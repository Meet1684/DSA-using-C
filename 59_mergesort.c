#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// O(n)
void MS(int a[], int low, int mid, int high)
{
    int i, j, k;
    i = low, j = mid + 1, k = low;
    int b[100];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }
    while(j <= high){
        b[k] = a[j];
        j++;
        k++;
    }
    for(int i=low; i<=high; i++){
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high) // O(n log n);
{
    int mid;
    if (low < high)
    {
        mid = (low+high)/2;
        mergeSort(a, low, mid); // sorting left subarray
        mergeSort(a, mid+1, high); // sorting right subarray
        MS(a, low, mid, high); // merging both subarrays
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 7, 23, 23, 9};
    int n1 = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n1-1);
    printArray(arr, n1);
    return 0;
}
