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

struct Node * delete1(struct Node * head){ // O(1)
    // Delete the first element
    struct Node * p = head;
    head=head->next;
    head->prev=NULL;
    free(p);
    return head;
}

struct Node * delete2(struct Node * head, int index){ // O(n)
    // Delete in between
    struct Node * p = head;
    struct Node * q = head->next;
    int i = 0;
    for(int i=0; i< index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    (q->next)->prev = p;
    free(q);
    return head;
}

struct Node * delete3(struct Node * head){ // O(n)
    // Delete the last element
    struct Node * p = head;
    while(head->next != NULL){
        head = head->next;
    }
    (head->prev)->next=NULL;
    free(head);
    return p;
}

struct Node * delete4(struct Node * head, int value){ // O(n)
    // Delete with value
    struct Node * p = head;
    while(p->data != value){
        p = p->next;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);

    return head;
}

struct Node * delete5(struct Node * head, struct Node * node_to_delete){ // O(1)
    // Delete a specific node
    if (head == NULL || node_to_delete == NULL)
        return head;

    // If the node to delete is the head node
    if (head == node_to_delete) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(node_to_delete);
        return head;
    }

    // Adjust pointers to skip over the node to delete
    if (node_to_delete->prev != NULL)
        node_to_delete->prev->next = node_to_delete->next;
    if (node_to_delete->next != NULL)
        node_to_delete->next->prev = node_to_delete->prev;

    free(node_to_delete);
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;
    struct Node *fifth;
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    forth = (struct Node*) malloc(sizeof(struct Node));
    fifth = (struct Node*) malloc(sizeof(struct Node));
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
    third->next = forth;

    forth->data = 23;
    forth->prev = third;
    forth->next = fifth;

    fifth->data = 48;
    fifth->prev = forth;
    fifth->next = NULL;

    traverse(head);
    // head = delete1(head);
    // head = delete2(head, 2);
    // head = delete3(head);
    // head = delete4(head, 23);
    head = delete5(head, third);
    traverse(head);
    return 0;
} 