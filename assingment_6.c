#include <stdio.h>
#include <stdlib.h>

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

struct Node* reverselinkedlist(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}



void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int val1, val2, val3;
    printf("Enter the value of 1st node: ");
    scanf("%d", &val1);
    printf("Enter the value of 2nd node: ");
    scanf("%d", &val2);
    printf("Enter the value of 3rd node: ");
    scanf("%d", &val3);

    struct Node* head = createNode(val1);
    head->next = createNode(val2);
    head->next->next = createNode(val3);

    printf("Original linked list: ");
    printList(head);

    head = reverselinkedlist(head);
    printf("Reversed linked list: ");
    printList(head);

    



    return 0;
}
