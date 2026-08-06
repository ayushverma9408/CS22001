#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

struct Node *reverseK(struct Node *head, int k)
{
    struct Node *temp = head;
    int i;

    for(i = 0; i < k; i++)
    {
        if(temp == NULL)
            return head;

        temp = temp->next;
    }

    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    int count = 0;

    while(current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(current != NULL)
        head->next = reverseK(current, k);

    return prev;
}

int main()
{
    int n, i, value, k;

    struct Node *head = NULL;
    struct Node *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        struct Node *newNode = createNode(value);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    head = reverseK(head, k);

    printf("Modified List:\n");
    display(head);

    return 0;
}