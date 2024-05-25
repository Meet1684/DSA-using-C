#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack * ptr, int element){ // O(1)
    if(isFull(ptr)){
        printf("\nStack Overflow !\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct stack * ptr){ // O(1)
    int popped;
    if(isEmpty(ptr)){
        printf("\nStack Underflow !\n");
        return -1;
    }
    else{
        popped = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        return popped;
    }
}

int peek(struct stack * ptr, int pos){ // O(1)
    int index;
    if(ptr->top-pos+1<0){
        printf("Invalid Index",index);
        return -1;
    }
    else{
        if(isEmpty(ptr)){
        printf("\nStack Underflow !\n");
            return -1;
        }
        else{
            return ptr->arr[ptr->top-pos+1]; // ptr->arr[ptr->4-3+1]
        }
    }
}

void printStack(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("\nStack Underflow !\n");
    }
    else{
        for(int i=1; i<=ptr->top+1; i++){
            printf("Element %d : %d\n", i, peek(ptr, i));
        }
    }
}

int stackTop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("\nStack Underflow !\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top];
    }
}

int stackBottom(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("\nStack Underflow !\n");
        return -1;
    }
    else{
        return ptr->arr[0];
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
 
    struct stack *s = (struct stack *)malloc (sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int)); // empty stack

    // printStack(s); // stack underflow
    // pop(s); // stack underflow
    push(s, 30);
    push(s, 58);
    push(s, 29);
    push(s, 47);
    push(s, 10);
    printf("Element %d popped out of array\n", pop(s));
    push(s, 95);
    // push(s, 28); // stack overflow

    printStack(s);
    // printf("\nTop : %d", stackTop(s));
    // printf("\nBottom : %d", stackBottom(s));
    return 0;
}
