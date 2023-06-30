#include <iostream>


struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};


void inOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->value << std::endl;
    inOrderTraversal(root->right);
}

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
    struct Node *head = NULL;
    head = insertNode(head, 4);
    insertNode(head, 43);
    insertNode(head, 23);
    insertNode(head, 12);
    insertNode(head, 443);
    insertNode(head, 424);
    inOrderTraversal(head);
}
