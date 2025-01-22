#include <stdio.h>
#include <stdlib.h>
//Design algorithm/develop pseudocode/write C code to deletes the last node from the LIST.
int main() {

    struct Node {
        int data;
        struct Node* next;
    };


    struct Node* createNode(int data){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    };

    
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


    if (head == NULL) {
        printf("The list is empty!\n");
    } else if (head->next == NULL) { 
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL; 
    }

    
    printf("After deleting last node: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    
    while (head != NULL) {
        struct Node* toDelete = head;
        head = head->next;
        free(toDelete);
    }

    return 0;
}
