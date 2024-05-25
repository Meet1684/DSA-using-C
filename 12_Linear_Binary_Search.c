#include<stdio.h>

int linear_search(int a[], int n, int e){ // O(n)
    for(int i=0;i<n;i++){
        if(a[i] == e){
            return i;
        }
    }
    return -1;
}

int binary_search(int a[], int size, int element){ // O(log n)
    int low = 0, mid, high = size;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == element){
            return mid;
        }
        else if(a[mid] < element){
            low = mid + 1;
        }
        else if(a[mid] > element){
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[5] = {5,2,7,9,8};
    int size = sizeof(arr)/sizeof(int);
    int element1 = 7;
    int index1 = linear_search(arr, 5, element1);
    printf("\n***************Linear Search***************\n");
    if(index1 != -1){
        printf("\nElement %d found at index %d\n", element1, index1);
    }
    else{
        printf("\nElement not found !\n");
    }

    int sortedarr[5] = {2,5,7,8,9};
    int element2 = 8;
    int index2 = binary_search(sortedarr, 5, element2);
    printf("\n***************Binary Search***************\n");
    if(index2 != -1){
        printf("\nElement %d found at index %d\n", element2, index2);
    }
    else{
        printf("\nElement not found !\n");
    }
    return 0;
}