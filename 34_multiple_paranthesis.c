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

int push(struct stack * ptr, int element){
    if(isFull(ptr)){
        printf("\nStack Overflow !\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct stack * ptr){
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

int match(char a, char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    else if(a == '[' && b == ']'){
        return 1;
    }
    else if(a == '{' && b == '}'){
        return 1;
    }
}

int paranthesisMatch(char * exp){ // O(n)
    struct stack *s = (struct stack *)malloc (sizeof(struct stack));
    s->size = strlen(exp);
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char)); // empty stack

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(s, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(isEmpty(s)){
                return 0;
            }
            char popped = pop(s);
            if(!match(popped, exp[i])){
                return 0;
            }
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

    char * exp = "{(9*9)-[5+7]}";
    if(paranthesisMatch(exp)) {
        printf("\nParanthesis is matching\n");

    }
    else{
        printf("\nParanthesis is not matching !\n");
    }
    return 0;
}
