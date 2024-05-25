#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
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

int paranthesisMatch(char * exp){ // O(n)
    struct stack *s = (struct stack *)malloc (sizeof(struct stack));
    s->size = strlen(exp);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char)); // empty stack

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            push(s, '(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(s)){
                return 0;
            }
            pop(s);
        }
    }
    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{

    char * exp = "(6)*(45)";
    if(paranthesisMatch(exp)) {
        printf("\nParanthesis is matching\n");

    }
    else{
        printf("\nParanthesis is not matching !\n");
    }
    return 0;
}
