#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

int isEmpty(struct Node * top){
    if(top == NULL){
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

struct Node * push(struct Node * top, int element){ // O(1)
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(isFull(n)){
        printf("\nStack Overflow !\n");
    }
    else{
        n->data = element;
        n->next = top;
        top = n;
    }
    return top;
}

 // O(1)
int pop(struct Node ** top){  // Difference
    if(isEmpty(*top)){
        printf("\nStack Underflow !\n");
        return -1;
    }
    else{
        struct Node * n = *top;
        *top = (*top)->next; // Difference
        int popped = n->data;
        free(n);
        return popped;
    }
}

 // O(1)
int peek(struct Node * top, int pos){
    if(isEmpty(top)){
        printf("\nStack Underflow !\n");
        return -1;
    }
    else{
        struct Node * ptr = top;
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
    struct Node * top = NULL; // empty stack

    top = push(top, 40);
    top = push(top, 57);
    top = push(top, 39);
    top = push(top, 469);
    top = push(top, 359);
    printf("Element %d popped", pop(&top)); // Difference
    traverse(top);
    printf("\n%d", peek(top, 1));
    return 0;
}