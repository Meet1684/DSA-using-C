#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node * p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preOrder(struct Node * n){
    if(n!=NULL){
        printf("%d ",n->data);
        preOrder(n->left);
        preOrder(n->right);
    }
}

int main(){
   struct Node *root = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(root);
    return 0;
}