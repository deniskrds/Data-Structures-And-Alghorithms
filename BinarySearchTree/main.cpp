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

void preOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->value << std::endl;
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    std::cout << root->value << std::endl;
}

struct Node* insertNode(struct Node *root, int item) {
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

struct Node* search(struct Node* root, int key){
    if (root == NULL || root->value == key){
        return root;
    }
    if (root->value > key){
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
    struct Node *root = NULL;
    root = insertNode(root, 4);
    insertNode(root, 3);
    insertNode(root, 23);
    insertNode(root, 12);
    insertNode(root, 443);
    insertNode(root, 424);

    struct Node* searchedNode;
    searchedNode = search(root, 424);
    std::cout << searchedNode->value;
}
