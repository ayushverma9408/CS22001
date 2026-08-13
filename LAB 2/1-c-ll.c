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

void deleteBefore(int num)
{
    struct node *p, *q, *r;

    if(head == NULL || head->next == NULL)
    {
        printf("Deletion not possible\n");
        return;
    }
 
    if(head->data == num)
    {
        printf("No node exists before %d\n", num);
        return;
    }
 
    if(head->next->data == num)
    {
        q = head;
        head = head->next;
        free(q);
        return;
    }

    r = head;
    q = head->next;
    p = q->next;

    while(p != NULL)
    {
        if(p->data == num)
        {
            r->next = p;
            free(q);
            return;
        }

        r = q;
        q = p;
        p = p->next;
    }

    printf("Node %d not found\n", num);
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
    int n, x, num, i;

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

    printf("\nEnter NUM: ");
    scanf("%d", &num);

    deleteBefore(num);

    printf("\nAfter deletion:\n");
    display();

    return 0;
}
