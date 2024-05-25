#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
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

    if(isEmpty(s)){
        printf("Stack is Empty\n");
    }

    s->arr[0] = 48;
    s->top++;
    s->arr[1] = 84;
    s->top++;
    s->arr[2] = 24;
    s->top++;
    s->arr[3] = 42;
    s->top++;
    s->arr[4] = 68;
    s->top++;

    if(isFull(s)){
        printf("Stack is Full\n");
    }
    
    return 0;
}
