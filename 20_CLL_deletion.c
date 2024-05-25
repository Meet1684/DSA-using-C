#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traverse1(struct Node *head){
    struct Node * p = head;
    do{
        printf("%d ", p->data);
        p = p->next;
    }
    while(p!=head);
    printf("\n");
}

void traverse2(struct Node *head){
    struct Node * p = head;
    while(p->next!=head){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

struct Node * delete1(struct Node * head){ // O(n)
    // Delete the first element
    struct Node * p = head;
    if(p->next == head){ // if only one element
        free(head);
        return NULL;
    }
    struct Node * last = head;
    while(last->next != head){
        last = last->next;
    }
    p = p->next;
    last->next = p;
    free(head);
    return p;
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
    while((q->next) != head){
        p=p->next;
        q=q->next;
    }
    p->next = head;
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

struct Node * delete5(struct Node * head, struct Node * node){ // O(n)
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
    fifth->next = head;

    traverse1(head);
    head = delete1(head);
    head = delete2(head, 2);
    head = delete3(head);
    head = delete4(head, 34);
    head = delete5(head, third);
    traverse1(head);

    return 0;
}