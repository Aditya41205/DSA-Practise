#include <stdio.h>
 #include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertNode(struct Node** head, int data);
void displayReverse(struct Node* head);
int main() {
    struct Node* head = NULL;
    int n, data;
printf("Enter the number of nodes: ");
    scanf("%d", &n);
for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }
  printf("The linked list in reverse order is: ");
    displayReverse(head);
    printf("\n");
return 0;
}
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
if (*head == NULL) {
        *head = newNode;
        return;
    }
struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void displayReverse(struct Node* head) {
if (head == NULL) {
        return;
    }
    displayReverse(head->next); // Recursive call
    printf("%d ", head->data); // Print data during backtracking
}


 