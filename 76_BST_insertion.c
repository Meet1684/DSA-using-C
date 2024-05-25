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

void insertNode(struct Node * root, int data){
    struct Node * prev = NULL;
    struct Node * ptr;
    while(root!=NULL){
        prev = root;
        if(data == root->data){
            printf("Already in BST !\n");
            return;
        }
        else if(data > prev->data){
            root = root->right;
        }
        else if(data < prev->data){
            root = root->left;
        }
    }
    struct Node * new = createNode(data);
    if(data < prev->data){
        prev->left = new;
        printf("Inserted at left of %d\n", prev->data);
    }
    else if(data > prev->data){
        prev->right = new;
        printf("Inserted at right of %d\n", prev->data);
    }
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
    insertNode(root, 7);
    return 0;
}