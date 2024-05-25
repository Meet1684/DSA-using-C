#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int maximum(int a[], int n){
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

void countSort(int *a, int n){ // O(m+n)
    int i, j;
    int max = maximum(a, n);
    int * count = (int *) malloc((max+1) * sizeof(int));

    for(i=0; i<=max; i++){
        count[i] = 0;
    }

    for(i=0; i<n; i++){
        count[a[i]] = count[a[i]]+1;
    }
    i=0;
    j=0;
    while(i <= max){
        if(count[i] > 0){
            a[j] = i;
            j++;
            count[i]--;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 7, 23, 23, 9};
    int n = sizeof(arr) / sizeof(int);

    countSort(arr, n);
    printArray(arr, n);
    return 0;
}
