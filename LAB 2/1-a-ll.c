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

void deleteBeg()
{
    struct node *t;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    t = head;
    head = head->next;
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

    deleteBeg();

    printf("\nAfter deleting from beginning:\n");
    display();

    return 0;
}