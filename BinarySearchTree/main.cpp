#include <iostream>


struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *insertNode(struct Node *root, int item) {
    if (root == NULL) {
        root = new struct Node;
        root->left = root->right = NULL;
        root->value = item;
    } else {
        if (root->value > item) {
            root->left = insertNode(root->left, item);
        } else {
            root->right = insertNode(root->right, item);
        }
    }
    return root;
}

int main() {
}
