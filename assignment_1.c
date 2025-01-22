#include <stdio.h>
#include <stdlib.h>

//Design algorithm/develop pseudocode/write C code to add a given value K to each element in the list
struct node{
    int data;
    struct node *next;
};
int main(){

    int data1,data2,data3,data4;
    struct node *ptr;
   struct node *head = (struct node*)malloc(sizeof(struct node));
      struct node *first = (struct node*)malloc(sizeof(struct node));
   struct node *second = (struct node*)malloc(sizeof(struct node));

   printf("Enter the data for the first node: ");
    scanf("%d",&data1);
    head->data=data1;
    head->next=first;

    printf("Enter the data for the second node: ");
    scanf("%d",&data2);
    first->data=data2;
    first->next=second;

    printf("Enter the data for the third node: ");
    scanf("%d",&data3);
    second->data=data3;
    second->next=NULL;

    printf("the values of linked list before modification are:\n");
    ptr=head;
while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
};



    printf("Enter the value to be added to the data of linkedlist:\n ");
    scanf("%d\n",&data4);

    printf("the values of linked list after modification are:\n");
    ptr=head;
while(ptr!=NULL){
    ptr->data=ptr->data+data4;
    printf("%d\n",ptr->data);
    ptr=ptr->next;
};

    return 0;

   
}