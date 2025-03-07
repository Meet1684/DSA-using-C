#include<stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// O(n^2)
void insertionSort(int *a, int n){// Adaptive Insertion Sort algorithm
    int key, j;
    for(int i=1; i<n-1; i++){
        printf("Pass %d\n", i);
        key = a[i];
        j = i-1;
        while(j>=0 && a[j] > key){ // a[j] < key descending order
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(){
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(arr)/sizeof(int);

    insertionSort(arr, n); // maintains order of elements
    printArray(arr, n);
    return 0;
}