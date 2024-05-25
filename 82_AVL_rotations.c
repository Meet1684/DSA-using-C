#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    int height;
};

void preOrder(struct Node * n){
    if(n!=NULL){
        printf("%d ",n->data);
        preOrder(n->left);
        preOrder(n->right);
    }
}

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(struct Node * n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

int getBalanceFactor(struct Node * n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node * createNode(int data){
    struct Node * p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;

    return p;
}

struct Node * leftRotate(struct Node * x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return y;
}

struct Node * rightRotate(struct Node * y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return x;
}

struct Node * insertNode(struct Node * root, int data){
    if(root == NULL){
        return (createNode(data));
    }

    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    if(bf > 1 && data < root->left->data){
        return rightRotate(root);
    }

    if(bf < 1 && data > root->right->data){
        return leftRotate(root);
    }

    if(bf > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(bf < 1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main(){
    struct Node * root = NULL;
    insertNode(root, 45);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 8);
    insertNode(root, 9);
    preOrder(root);
    return 0;
}