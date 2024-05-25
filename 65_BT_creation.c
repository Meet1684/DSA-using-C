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

int main(){
    struct Node * root = createNode(2);
    struct Node * p1 = createNode(1);
    struct Node * p2 = createNode(4);

    root->left = p1;
    root->right = p2;
    printf("\t%d\n", root->data);
    printf("%d", root->left->data);
    printf("\t\t%d", root->right->data);
    return 0;
}