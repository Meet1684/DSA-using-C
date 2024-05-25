#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    // head->next = NULL; // empty Singly Linked List

    head->data = 47;
    head->next = second;

    second->data = 89;
    second->next = third;

    third->data = 34;
    third->next = NULL;

    traverse(head);
    return 0;
} 