#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// f and r are global variables.
// They can be used directly in functions.
// no need to set them as parameters in functions.
// no need to use them as arguments.
struct Node * f = NULL;
struct Node * r = NULL;

int isFull(struct Node * newNode){
    if(newNode == NULL){
        return 1;
    }
    return 0;
}

int isEmpty(struct Node * f){
    if(f == NULL){
        return 1;
    }
    return 0;
}

void traverse(){
    struct Node * ptr = f;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int element){ // O(1)
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    if(isFull(newNode)){
        printf("Queue is Full !\n");
    }
    else{
        newNode->data = element;
        newNode->next = NULL;
        if(f == NULL){ // if queue is empty
            f = newNode;
            r = newNode;
        }
        else{
            r->next = newNode;
            r = newNode;
        }
    }
}

int dequeue(){ // O(1)
    if(isEmpty(f)){
        printf("Queue is Empty !\n");
        return -1;
    }
    else{
        struct Node * ptr = f;
        f = f->next;
        int val = ptr->data;
        free(ptr);
        return val;
    }
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);

    traverse();

    printf("Element %d removed from queue\n", dequeue());
    printf("Element %d removed from queue\n", dequeue());
    printf("Element %d removed from queue\n", dequeue());
    // traverse(); // queue is empty
    // dequeue(); // queue is empty
    
    return 0;
}