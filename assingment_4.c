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

struct Node* swapKthAndKPlus1(struct Node* head, int k) {
    if (k < 1 || head == NULL || head->next == NULL) {
        printf("Invalid position or insufficient nodes.\n");
        return head;
    }

    if (k == 1) {
        struct Node* first = head;
        struct Node* second = head->next;
        first->next = second->next;
        second->next = first;
        head = second;
        return head;
    }

    struct Node* prev = NULL;
    struct Node* curr = head;
    for (int i = 1; i < k && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL) {
        printf("Swapping not possible. Position out of range.\n");
        return head;
    }

    
    struct Node* kthNode = curr;
    struct Node* kPlus1Node = curr->next;

    prev->next = kPlus1Node;
    kthNode->next = kPlus1Node->next;
    kPlus1Node->next = kthNode;

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

    printf("Enter the value of k: ");
    int k;
    scanf("%d", &k);

    head = swapKthAndKPlus1(head, k);

    printf("Linked list after swapping: ");
    printList(head);

    return 0;
}
