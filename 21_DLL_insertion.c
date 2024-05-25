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

struct Node * insert1(struct Node *head, int data){ // O(1)
    //Insert at the beginning
    struct Node * p = (struct Node *) malloc(sizeof(struct Node *));
    p->data = data;
    p->prev = NULL;
    p->next = head;
    head->prev = p;
    return p;
}

struct Node * insert2(struct Node *head, int data, int index){ // O(n)
    //Insert in between
    struct Node * p = head;
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node *));
    struct Node * q = head->next;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    ptr->data = data;
    ptr->prev = p;
    ptr->next = q;
    p->next = ptr;
    q->prev = ptr;

    return head;
}

struct Node * insert3(struct Node *head, int data){ // O(n)
    //Insert at the end
    struct Node * p = head;
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node *));
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

struct Node * insert4(struct Node *head, int data, struct Node * value){ // O(n)
    //Insert after node
    struct Node * p = head;
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node *));
    struct Node * q = head->next;
    while(p != value){
        p = p->next;
        q = q->next;
    }
    p->next = ptr;
    q->prev = ptr;
    ptr->data = data;
    ptr->prev = p;
    ptr->next = q;
    return head;
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
    head = insert1(head, 20);
    head = insert2(head, 40, 2);
    head = insert3(head, 40);
    head = insert4(head, 95, second);
    traverse(head);
    return 0;
} 