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

struct Node * searchBST1(struct Node * root, int data){ // Using Recursion
    if(root!=NULL){
        if(data == root->data){
            return root;
        }
        else if(data < root->data){
            return searchBST1(root->left, data);
        }
        else if(data > root->data){
            return searchBST1(root->right, data);
        }
    }
    return NULL; // Optional
}

struct Node * searchBST2(struct Node * root, int data){ // Using Iteration
    while(root!=NULL){
        if(data == root->data){
            return root;
        }
        else if(data < root->data){
            root = root->left;
        }
        else if(data > root->data){
            root = root->right;
        }
    }
    return NULL; // Optional
}

int main(){
   struct Node *root = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct Node * s1 = searchBST1(root, 1);
    if(s1 != NULL){
        printf("Element %d Found\n", s1->data);
    }
    else{
        printf("Element Not found !\n");
    }

    struct Node * s2 = searchBST1(root, 6);
    if(s2 != NULL){
        printf("Element %d Found\n", s2->data);
    }
    else{
        printf("Element Not found !\n");
    }

    return 0;
}