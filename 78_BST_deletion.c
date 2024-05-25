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

void inOrder(struct Node * n){
    if(n!=NULL){
        inOrder(n->left);
        printf("%d ", n->data);
        inOrder(n->right);
    }
}

struct Node * inOrderPredecessor(struct Node * root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct Node * deleteNode(struct Node * root, int data){
    struct Node * ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(data < root->data){
        deleteNode(root->left, data);
    }
    else if(data > root->data){
        deleteNode(root->left, data);
    }
    else if(data == root->data){
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;
        root->left = deleteNode(root->left, ipre->data);
    }
    return root;
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
    inOrder(root);
    printf("\n");
    deleteNode(root, 3);
    inOrder(root);
    return 0;
}