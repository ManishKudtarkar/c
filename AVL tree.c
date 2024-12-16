#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    int ht;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Function to get the height of a node
int height(struct node *p) {
    if (p == NULL)
        return 0;
    return p->ht;
}

// Function to update the height of a node
void updateHeight(struct node *p) {
    if (p != NULL)
        p->ht = 1 + (height(p->left) > height(p->right) ? height(p->left) : height(p->right));
}

// Function to calculate balance factor
int balanceFactor(struct node *p) {
    if (p == NULL)
        return 0;
    return height(p->left) - height(p->right);
}

// Right rotation
struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation
struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Balancing the tree
struct node *balance(struct node *p) {
    int bf = balanceFactor(p);

    if (bf > 1 && balanceFactor(p->left) >= 0) {
        // Left-Left case
        return rightRotate(p);
    }
    if (bf > 1 && balanceFactor(p->left) < 0) {
        // Left-Right case
        p->left = leftRotate(p->left);
        return rightRotate(p);
    }
    if (bf < -1 && balanceFactor(p->right) <= 0) {
        // Right-Right case
        return leftRotate(p);
    }
    if (bf < -1 && balanceFactor(p->right) > 0) {
        // Right-Left case
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }

    return p;
}

// Function to create a new node
struct node *createNode(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->ht = 1; // New node is initially at height 1
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert function
struct node *insert(struct node *p, int val) {
    if (p == NULL)
        return createNode(val);

    if (val < p->val)
        p->left = insert(p->left, val);
    else if (val > p->val)
        p->right = insert(p->right, val);
    else
        return p; // Duplicate values are not allowed

    updateHeight(p);
    return balance(p);
}

// Inorder traversal
void inorder(struct node *p) {
    if (p == NULL)
        return;
    inorder(p->left);
    printf("%d (h: %d bf: %d)\t", p->val, p->ht, balanceFactor(p));
    inorder(p->right);
}

int main() {
    int A[9] = {20, 10, 30, 5, 12, 25, 35, 37, 39};
    for (int i = 0; i < 9; i++) {
        root = insert(root, A[i]);
    }

    printf("Inorder traversal after insertion:\n");
    inorder(root);
    printf("\n");

    return 0;
}
