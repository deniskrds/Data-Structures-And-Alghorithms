#include <format>
#include <iostream>
#include "string"

struct Node {
    int value;
    struct Node *next;
};

int findLengthOperation(struct Node *head) {
    int i = 0;
    while (head->next != NULL) {
        i++;
        head = head->next;
    }
    return i;
}

void searchOperation(struct Node *head, int searchItem) {
    int i = 1;
    while (head->next != NULL) {
        if (head->value == searchItem) {
            char buffer[100];
            snprintf(buffer, 100, "element found on %dth node", i);
            std::cout << buffer;
            break;
        }
        head = head->next;
        i++;
    }
}


void printOperation(struct Node *head) {
    while (head != NULL) {
        std::cout << head->value << std::endl;
        head = head->next;
    }
}

struct Node *deleteOperation(struct Node *head, int itemTBDeleted) {
    struct Node *tail = head;
    while (head != NULL && head->value == itemTBDeleted) {
        head = head->next;
    }
    while (tail != NULL) {
        struct Node *nextNode;
        nextNode = tail->next;
        if (nextNode != NULL && nextNode->value == itemTBDeleted) {
            tail->next = nextNode->next;
        }else{
            tail = tail->next;
        }
    }
    return head;
}


struct Node *reverseOperation(struct Node *head) {
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void insertOperation(struct Node *head, int i) {
    struct Node *tempPtr = new Node;
    struct Node *last = head;
    tempPtr->value = i;
    while (last != NULL) {
        if (last->next == NULL) {
            last->next = tempPtr;
            break;
        }
        last = last->next;
    }
    head = last;
}


int binaryToDecimal(struct Node *head) {
    std::string binaryNumber = "";
    while (head != NULL) {
        binaryNumber += std::to_string(head->value);
        head = head->next;
    }
    int binaryNumberAsInt = std::stoi(binaryNumber, nullptr, 2);
    return binaryNumberAsInt;
}


int main() {
}
