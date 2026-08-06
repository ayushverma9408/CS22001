#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAfter(int key, int value)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            struct Node *newNode;

            newNode = (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }

        temp = temp->next;
    }

    printf("Node not found.\n");
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
    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);

    printf("Original List:\n");
    display();

    insertAfter(20, 25);

    printf("After Insertion:\n");
    display();

    return 0;
}