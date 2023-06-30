#include <format>
#include <iostream>


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
    while (head->next != NULL) {
        std::cout << head->value << std::endl;
        head = head->next;
    }
}

void deleteOperation(struct Node *head, int itemTBDeleted) {
    while (head->next != NULL) {
        if (head->next->value == itemTBDeleted) {
            head->next = head->next->next;
            break;
        }
        head = head->next;
    }
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


int main() {
}
