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

void push(struct stack * ptr, char element){
    if(isFull(ptr)){
        printf("\nStack Overflow !\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

char pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("\nStack Underflow !\n");
        return -1;
    }
    else{
        char popped = ptr->arr[ptr->top];
        ptr->top = ptr->top-1;
        return popped;
    }
}

char stackTop(struct stack * ptr){
    return ptr->arr[ptr->top];
}

int isOperator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char a){
    if(a == '+' || a == '-'){
        return 2;
    }
    else if(a == '*' || a == '/'){
        return 3;
    }
    else{
        return 0;
    }
}

char * infixToPostfix(char * infix){ // O(n)
    struct stack * ptr = (struct stack *) malloc(sizeof(struct stack));
    ptr->size = strlen(infix); 
    ptr->top = -1;
    ptr->arr = (char *) malloc(ptr->size * sizeof(char));
    char * postFix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postFix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(ptr))){
                push(ptr, infix[i]);
                i++;
            }
            else{
                postFix[j] = pop(ptr);
                j++;
            }
        }
    }
    while (!isEmpty(ptr))    
    {
        postFix[j] = pop(ptr);
        j++;
    }
    postFix[j] = '\0';
    return postFix;
}

int main()
{
    char * infix = "x-y*a/b";
    printf("\nPostfix : %s\n", infixToPostfix(infix));
    return 0;
}
