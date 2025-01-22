#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head);
int isEmpty(struct Node* head);
void insertAtPosition(struct Node** head, int data, int position);
void deleteAtPosition(struct Node** head, int position);
int countNodes(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Position\n");
        printf("2. Delete at Position\n");
        printf("3. Traverse List\n");
        printf("4. Check if List is Empty\n");
        printf("5. Count Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (0 for beginning, -1 for end, or any other position): ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;

            case 2:
                printf("Enter position to delete (0 for beginning, -1 for end, or any other position): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 3:
                traverse(head);
                break;

            case 4:
                if (isEmpty(head)) {
                    printf("The list is empty.\n");
                } else {
                    printf("The list is not empty.\n");
                }
                break;

            case 5:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to traverse the linked list
void traverse(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to check if the list is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Function to insert a node at a certain position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < -1) {
        printf("Invalid position. Please try again.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) { // Insert at beginning
        newNode->next = *head;
        *head = newNode;
        return;
    }

    if (position == -1) { // Insert at end
        if (*head == NULL) {
            *head = newNode;
            return;
        }

        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return;
    }

    // Insert at any other position
    struct Node* current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds. Node not inserted.\n");
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete a node at a certain position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty. No node to delete.\n");
        return;
    }

    if (position < -1) {
        printf("Invalid position. Please try again.\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 0) { // Delete from beginning
        *head = temp->next;
        free(temp);
        return;
    }

    if (position == -1) { // Delete from end
        struct Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *head = NULL;
        }

        free(temp);
        return;
    }

    // Delete from any other position
    struct Node* prev = NULL;
    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds. No node deleted.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to count the total number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
