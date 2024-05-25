#include<stdio.h>

void display(int a[], int n){
    //traversal
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

// O(n)
int insert(int a[], int size, int element, int capacity, int index){ //Insert an element at index and shift other elements
    if(size>=capacity){
        return -1;
    } else if(index>=capacity){
        return -1;
    } 
    else{
        for(int i=size; i>=index; i--){
            a[i+1] = a[i];
        }
        a[index] = element;
    }
    return 0;
}

int main(){
    int arr[10] = {7, 8, 12, 27, 88};
    printf("\nOld Array\n");
    display(arr, 10);

    int size = 5, element = 45, index = 0;
    int result = insert(arr, size, element, 10, index);
    if(result == 0){
        size += 1;
        printf("\nElement inserted successfully\n");
        printf("\nNew Array\n");
        display(arr, 10);
        printf("\nNew Size : %d", size);
    }
    else{
        printf("\nError inserting an element !\n");
    }
    return 0;
}