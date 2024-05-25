#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct queue * q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct queue * q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

void traverse(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty !\n");
    } else {
        for (int i = q->f + 1; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

void enqueue(struct queue * q, int element){ // O(1)
    if(isFull(q)){
        printf("Queue is Full !\n");
    }
    else{
        q->r++;
        q->arr[q->r] = element;
    }
}

int dequeue(struct queue * q){ // O(1)
    if(isEmpty(q)){
        printf("Queue is Empty !\n");
        return -1;
    }
    else{
        q->f++;
        return q->arr[q->f];
    }
}

int main(){
    struct queue * explored = (struct queue *) malloc(sizeof(struct queue));
    explored->size = 400;
    explored->f = 0;
    explored->r = 0;
    explored->arr = (int *) malloc(explored->size * sizeof(int));

    int u;
    int i = 4;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a [7][7] = {
    //   0  1  2  3  4  5  6
        {0, 1, 1, 1, 0, 0, 0}, // 0
        {0, 0, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 0}, // 2
        {1, 0, 1, 0, 1, 0, 0}, // 3
        {0, 0, 1, 1, 0, 1, 1}, // 4
        {0, 0, 0, 0, 1, 0, 0}, // 5
        {0, 0, 0, 0, 1, 0, 0}  // 6
    };
 // in the array 'a' each row defines the connectivity withs nodes
    printf("%d", i);
    visited[i] = 1;
    enqueue(explored, i);
    while(!isEmpty(explored)){
        int node = dequeue(explored);
        for(int j=0; j<7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(explored, j);
            }
        }
    }
    return 0;
}