#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int d) {
    struct node *t = malloc(sizeof(struct node));
    t->data = d;
    t->right = NULL;
    t->left = NULL;
    return t;
}

struct node* inorderPred(struct node *root) {
    if (root == NULL || root->left == NULL)
        return NULL;
    
    struct node *predParent = root;
    struct node *pred = root->left;
    while (pred->right != NULL) {
        predParent = pred;
        pred = pred->right;
    }

    return predParent;
}

struct node* delete(int x, struct node *root) {
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = delete(x, root->left);
    else if (x > root->data)
        root->right = delete(x, root->right);
    else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct node *predParent = inorderPred(root);
            struct node *pred = predParent->right;

            root->data = pred->data;
            predParent->right = pred->left;
            free(pred);
        }
    }
    return root;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node *root = createNode(100);
    root->left = createNode(90);
    root->right = createNode(120);
    delete(100, root);
    inorder(root);
  
}
