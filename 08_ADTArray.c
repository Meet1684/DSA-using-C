#include<stdio.h>
#include<stdlib.h>

struct myArray {
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tsize, int usize){
    printf("\n*************createArray*************\n");
    // (*a).total_size = tsize;
    // (*a).used_size = usize;
    // (*a).ptr = (int *) malloc(tsize * sizeof(int));
    
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *) malloc(tsize * sizeof(int));
}

void setValue(struct myArray *a){ // O(n)
    printf("\n*************setValue*************\n");
    int n;
    for(int i=0;i<a->used_size;i++){
        printf("\nEnter Element %d : ", i+1);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void show(struct myArray *a){
    printf("\n*************show*************\n");
    for(int i=0;i<a->used_size;i++){
        printf("%d\n ",a->ptr[i]);
    }
}

int main(){
    struct myArray marks;
    createArray(&marks, 10, 5);
    setValue(&marks);
    show(&marks);
    insert(&marks, 2, 100);
    return 0;
}