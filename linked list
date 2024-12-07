#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct node {
    int data;             // Data stored in the node
    struct node *next;    // Pointer to the next node
};

// Function to create a new node with the given data
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct node *head = NULL, *tail = NULL;
    int data;

    // Read integers from input, separated by commas
    while (scanf("%d,", &data) == 1) {
        struct node *newNode = createNode(data);

        // Append the new node to the linked list
        if (head == NULL) {
            head = tail = newNode; // Initialize head and tail for the first node
        } else {
            tail->next = newNode; // Link the new node to the end of the list
            tail = newNode;       // Update the tail pointer
        }
    }

    // Print the linked list
    printf("Linked List: ");
    for (struct node *temp = head; temp != NULL; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");

    // Free allocated memory
    struct node *temp = head;
    while (temp != NULL) {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}

