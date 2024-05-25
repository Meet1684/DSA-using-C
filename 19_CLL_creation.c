#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void traverse1(struct Node *head){
    struct Node * p = head;
    do{
        printf("%d", p->data);
        p = p->next;
    }
    while(p!=head);
    printf("\n");
}

void traverse2(struct Node *head){
    struct Node * p = head;
    while(p->next!=head){
        printf("%d", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    // head->next = head; // empty circular Linked List

    head->data = 47;
    head->next = second;

    second->data = 89;
    second->next = third;

    third->data = 34;
    third->next = head;

    traverse1(head);
    traverse2(head);
    return 0;
} 