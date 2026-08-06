/*
Q2.(a) Implement a program to insert an ITEM into a Singly Linked List (SLL) 
2. At the end
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display()
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int n, value, newValue, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(value);
    }

    printf("\nOriginal List:\n");
    display();

    printf("\nEnter new item to insert at end: ");
    scanf("%d", &newValue);

    insertEnd(newValue);

    printf("\nUpdated List:\n");
    display();

    return 0;
}
