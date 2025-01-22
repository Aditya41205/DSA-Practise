#include <stdio.h>
#include <stdlib.h>
// Design algorithm/develop pseudocode/write C code to delete the 1st node from the list.
int main() {
    
    struct Node {
        int data;
        struct Node* next;
    };

    
    struct Node* createNode(int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    
    printf("Original list: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    
    int position;
    printf("Enter the position to delete (1-based index): ");
    scanf("%d", &position);

    if (head == NULL) {
        printf("The list is empty!\n");
    } else if (position == 1) {
        
        struct Node* toDelete = head;
        head = head->next;
        free(toDelete);
    } else {

        struct Node* prev = NULL;
        temp = head;
        int currentPosition = 1;

        while (temp != NULL && currentPosition < position) {
            prev = temp;
            temp = temp->next;
            currentPosition++;
        }

        if (temp == NULL) {
            printf("Invalid position! No node to delete.\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }

    printf("After deletion: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

  
    return 0;
}
