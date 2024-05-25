#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverse(struct Node *head){
    struct Node * p = head;
    while(p != NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    // head->prev = NULL; // empty circular Linked List
    // head->next = NULL; // empty circular Linked List

    head->data = 47;
    head->prev = NULL;
    head->next = second;

    second->data = 89;
    second->prev = head;
    second->next = third;

    third->data = 34;
    third->prev = second;
    third->next = NULL;

    traverse(head);
    return 0;
} 