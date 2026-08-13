/*
 
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int x)
{
    struct node *nn, *p;

    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = x;
    nn->next = NULL;

    if(head == NULL)
    {
        head = nn;
        return;
    }

    p = head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = nn;
}

void deleteEnd()
{
    struct node *p, *t;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    p = head;

    while(p->next->next != NULL)
    {
        p = p->next;
    }

    t = p->next;
    p->next = NULL;

    free(t);
}

void display()
{
    struct node *p = head;

    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }

    printf("NULL\n");
}

int main()
{
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }

    printf("\nOriginal List:\n");
    display();

    deleteEnd();

    printf("\nAfter deleting from end:\n");
    display();

    return 0;
}