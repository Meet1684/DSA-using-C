#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * top = NULL; // empty stack // Difference

int isEmpty(struct Node * ptr){
    if(ptr == NULL){
        return 1;
    }
    return 0;
}

int isFull(struct Node * n){
    if(n == NULL){
        return 1;
    }
    return 0;
}

void traverse(struct Node * ptr){
    int i = 0;
    while(ptr!=NULL){
        printf("\nElement %d : %d\n", i+1, ptr->data);
        ptr=ptr->next;
        i++;
    }
}

struct Node * push(struct Node * ptr, int element){ // O(1)
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(isFull(n)){
        printf("\nStack Overflow !\n");
    }
    else{
        n->data = element;
        n->next = ptr;
        ptr = n;
    }
    return ptr;
}

 // O(1)
int pop(struct Node * ptr){ // Difference
    if(isEmpty(ptr)){
        printf("\nStack Underflow !\n");
    }
    else{
        struct Node * n = ptr;
        top = (ptr)->next; // Difference
        int popped = n->data;
        free(n);
        return popped;
    }
}

 // O(1)
int peek(struct Node * ptr, int pos){
    if(isEmpty(ptr)){
        printf("\nStack Underflow !\n");
        return -1;
    }
    else{
        for(int i=0; i<pos-1 && ptr!=NULL; i++){
            ptr = ptr->next;
        }
        if(ptr!=NULL){
            return ptr->data;
        }
        else{
            return -1;
        }
    }
}

int main(){
    top = push(top, 40);
    top = push(top, 57);
    top = push(top, 39);
    top = push(top, 469);
    top = push(top, 359);
    printf("Element %d popped\n", pop(top)); // Difference
    traverse(top);
    printf("\n%d", peek(top, 1));
    return 0;
}