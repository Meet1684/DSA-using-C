#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traverse(struct Node * ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct Node * delete1(struct Node * head){ // O(1)
    // Delete the first element
    struct Node * ptr = head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node * delete2(struct Node * head, int index){ // O(n)
    // Delete in between
    struct Node * q;
    struct Node * p = head;
    for(int i=0; i< index-1; i++){
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node * delete3(struct Node * head){ // O(n)
    // Delete the last element
    struct Node * q = head->next;
    struct Node * p = head;
    while((q->next) != NULL){
        p=p->next;
        q=q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * delete4(struct Node * head, int value){ // O(n)
    // Delete using value
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data != value && q->next != NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

struct Node * delete5(struct Node * head, struct Node * node){
    // Delete after node
    struct Node * p = head;
    struct Node * q = head->next;;
    while(p->next != node){
        p=p->next;
        q=q->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

int main(){
    struct Node * head, * second, * third, * forth, * fifth;
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    forth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));

    head->data = 47;
    head->next = second;

    second->data = 52;
    second->next = third;

    third->data = 28;
    third->next = forth;

    forth->data = 34;
    forth->next = fifth;

    fifth->data = 79;
    fifth->next = NULL;

    traverse(head);
    head = delete1(head);
    head = delete2(head, 2);
    head = delete3(head);
    head = delete4(head, 34);
    head = delete5(head, third);
    traverse(head);

    return 0;
}