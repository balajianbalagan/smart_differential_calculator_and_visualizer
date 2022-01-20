#include <stdio.h>
#include <stdlib.h>
struct noderec
{
    int info;
    struct noderec *next;
};
typedef struct noderec *node;
node new, temp, prev;
typedef node stack;

stack create()
{
    stack s;
    s = (struct noderec *)malloc(sizeof(struct noderec *));
    s->next = NULL;
}

int isEmpty(stack s)
{
    return (s->next == NULL);
}
void push(stack s, int x)
{
    new = (struct noderec *)malloc(sizeof(struct noderec *));
    new->info = x;
    new->next = s->next;
    s->next = new;
}
void pop(stack s)
{
    if (!isEmpty(s))
    {
        temp = s->next;
        s->next = temp->next;
        free(temp);
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
int top(stack s)
{
    if (!isEmpty(s))
    {
        return ("%d", (s->next)->info);
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
int topandpop(stack s)
{
    if (!isEmpty(s))
    {
        int t = ("%d", (s->next)->info);
        pop(s);
        return t;
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
void makeempty(stack s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
}
void disposestack(stack s)
{
    if (s != NULL)
    {
        makeempty(s);
        free(s);
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
void display(stack s)
{
    temp = s->next;
    if (!isEmpty(s))
    {
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}