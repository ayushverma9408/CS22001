/*

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    int wl;
    struct node *next;
};

struct node *head = NULL;

void create(int id, int wl)
{
    struct node *nn, *p;

    nn = (struct node *)malloc(sizeof(struct node));

    nn->id = id;
    nn->wl = wl;
    nn->next = NULL;

    if(head == NULL)
    {
        head = nn;
        nn->next = head;
        return;
    }

    p = head;

    while(p->next != head)
    {
        p = p->next;
    }

    p->next = nn;
    nn->next = head;
}

void update(int id, int wl)
{
    struct node *p;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    p = head;

    do
    {
        if(p->id == id)
        {
            p->wl = wl;
            printf("Water level updated successfully.\n");
            return;
        }

        p = p->next;

    } while(p != head);

    printf("Tank ID not found.\n");
}

void display()
{
    struct node *p = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("Tank ID: %d, Water Level: %d liters\n",
               p->id, p->wl);

        p = p->next;

    } while(p != head);
}

int main()
{
    int n, id, wl, uid, uwl, i;

    printf("Enter number of tanks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Tank ID: ");
        scanf("%d", &id);

        printf("Enter Water Level: ");
        scanf("%d", &wl);

        create(id, wl);
    }

    printf("\nOriginal List:\n");
    display();

    printf("\nEnter Tank ID to update: ");
    scanf("%d", &uid);

    printf("Enter new water level: ");
    scanf("%d", &uwl);

    update(uid, uwl);

    printf("\nUpdated List:\n");
    display();

    return 0;
}