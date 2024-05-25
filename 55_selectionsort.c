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
void selectionSort(int * a, int n){ // not adaptive
    int min, temp;
    for(int i=0; i<n-1; i++){
        printf("Pass %d\n", i+1);
        min = i;
        for(int j = i+1; j<n; j++){
            if(a[j] <a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main(){
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(arr)/sizeof(int);

    selectionSort(arr, n); // order of elements is not maintained
    printArray(arr, n);
    return 0;
}