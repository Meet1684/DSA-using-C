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
    struct queue * q1 = (struct queue *) malloc(sizeof(struct queue));
    q1->size = 10;
    q1->f = -1;
    q1->r = -1;
    q1->arr = (int *) malloc(q1->size * sizeof(int));

    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);
    enqueue(q1, 50);

    traverse(q1);

    dequeue(q1);

    traverse(q1);
    return 0;
}