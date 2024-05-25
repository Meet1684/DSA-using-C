#include<stdio.h>
#include<stdlib.h>

struct circularQueue {
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct circularQueue * q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue * q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void traverse(struct circularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty !\n");
    } else {
        int i = (q->f + 1) % q->size; // Start from the next element after front
        int count = 0; // Track the number of elements printed
        while (count < (q->r - q->f + q->size) % q->size) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % q->size; // Move to the next element
            count++;
        }
        printf("\n");
    }
}

void enqueue(struct circularQueue * q, int element){ // O(1)
    if(isFull(q)){
        printf("Queue is Full !\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = element;
    }
}

int dequeue(struct circularQueue * q){ // O(1)
    if(isEmpty(q)){
        printf("circularQueue is Empty !\n");
        return -1;
    }
    else{
        q->f = (q->f+1)%q->size;
        return q->arr[q->f];
    }
}

int main(){
    struct circularQueue * q1 = (struct circularQueue *) malloc(sizeof(struct circularQueue));
    q1->size = 5;
    q1->f = 0; //f and r values are set to zero
    q1->r = 0; //so it will store (size-1) elements
    q1->arr = (int *) malloc(q1->size * sizeof(int));

    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);

    traverse(q1);

    dequeue(q1);
    // enqueue(q1, 50); // cannot enqueue again until queue is empty
    dequeue(q1);
    dequeue(q1);
    dequeue(q1);

    enqueue(q1, 50);
    enqueue(q1, 60);
    enqueue(q1, 70);
    enqueue(q1, 80);

    traverse(q1);
    return 0;
}