#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traverse(struct Node * ptr){
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insert1(struct Node *head, int data){ // O(1)
    //Insert at the beginning
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct Node * insert2(struct Node *head, int data, int index){ // O(n)
    //Insert in between
    if(index==0){
        printf("\nUse Insert at the beginning instead\n");
    }
    else{
        struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
        struct Node * p = head;
        int i = 0;
        while(i != index-1){
            p = p->next;
            i++;
        };
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;

        return head;
    }
}

struct Node * insert3(struct Node *head, int data){ // O(n)
    //Insert at the end
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    while((p->next)!=NULL){
        p = p->next; 
    }
    p->next = ptr;
    
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

struct Node * insert4(struct Node *head, struct Node *prevNode, int data){ // O(1)
    //Insert after a node
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main(){
    struct Node * head, * second, * third;
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 47;
    head->next = second;
    second->data = 52;
    second->next = third;
    third->data = 62;
    third->next = NULL;

    head = insert1(head, 56);
    head = insert2(head, 83, 2);
    head = insert3(head, 100);
    head = insert4(head, second, 95);
    traverse(head);
    return 0;
} 