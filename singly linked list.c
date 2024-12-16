#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *getNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head_ref, int new_data) {
    struct Node *new_node = getNode(new_data);
    new_node->next = *head_ref; 
    *head_ref = new_node; 
}

void append(struct Node **head_ref, int new_data) {
    struct Node *new_node = getNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void traverse(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    append(&head, 10);
    append(&head, 20);
    insertAtBeginning(&head, 5); 

    printf("Created linked list: ");
    traverse(head);

    return 0;
}
