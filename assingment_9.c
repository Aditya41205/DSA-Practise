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

struct Node* countkeys(struct Node* head, int key) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    printf("The number of times %d is present in the linked list is: %d\n", key, count);
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
    int val1, val2, val3, val4;
    printf("Enter the value of 1st node: ");
    scanf("%d", &val1);
    printf("Enter the value of 2nd node: ");
    scanf("%d", &val2);
    printf("Enter the value of 3rd node: ");
    scanf("%d", &val3);
    printf("Enter the value of 4th node: ");
    scanf("%d", &val4);

    struct Node* head = createNode(val1);
    head->next = createNode(val2);
    head->next->next = createNode(val3);
    head->next->next->next = createNode(val4);

    printf("Original linked list: ");
    printList(head);

    int key;
    printf("Enter the key to count: ");
    scanf("%d", &key);
    head = countkeys(head, key);

    return 0;
}