#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct noderec
{
    char info[300];
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
void push(stack s, char x[])
{
    new = (struct noderec *)malloc(sizeof(struct noderec *));
    strcpy(new->info,x);
    // strcpy(s->next,new);
    // new->info = x;
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
char* top(stack s)
{
    char *res;
    if (!isEmpty(s))
    {
        res= (s->next)->info;
        return res;
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
char* topandpop(stack s)
{
    if (!isEmpty(s))
    {
        char *t =  (s->next)->info;
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
            printf("%s ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
