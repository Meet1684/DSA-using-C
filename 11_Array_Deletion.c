#include<stdio.h>

void display(int a[], int n){
    //traversal
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

//O(n)
int delete(int a[], int size, int capacity, int index){ //Insert an element at index and shift other elements
    if(index>=capacity){
        return -1;
    } 
    else{
        for(int i=index; i<size; i++){
            a[i] = a[i+1];
        }
    }
    return 0;
}

int main(){
    int arr[10] = {7, 8, 12, 27, 88};
    printf("\nOld Array\n");
    display(arr, 5);

    int size = 5, element = 45, index = 1;
    int result = delete(arr, size, 10, index);
    if(result == 0){
        size -= 1;
        printf("\nElement deleted successfully\n");
        printf("\nNew Array\n");
        display(arr, 5);
        printf("\nNew Size : %d", size);
    }
    else{
        printf("\nError deleting an element !\n");
    }
    return 0;
}