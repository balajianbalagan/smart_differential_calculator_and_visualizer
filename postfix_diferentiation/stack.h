#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct snoderec
{
    char info[300];
    int sfn;
    struct snoderec *next;
};
typedef struct snoderec *snode;
snode temp, prev, snew;
typedef snode stack;

stack create()
{
    stack s;
    s = (struct snoderec *)malloc(sizeof(struct snoderec *));
    s->next = NULL;
}

int isEmpty(stack s)
{
    return (s->next == NULL);
}
void push(stack s, char *x, int sfnval)
{
    snew = (struct snoderec *)malloc(sizeof(struct snoderec *));
    strcpy(snew->info, x);
    snew->sfn = sfnval;
    // strcpy(s->next,snew);
    // snew->info = x;
    snew->next = s->next;
    s->next = snew;
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
char *top(stack s)
{
    char *res;
    if (!isEmpty(s))
    {
        res = (s->next)->info;
        return res;
    }
    else
    {
        printf("\nList is already Empty\n");
        return "\0";
    }
}

int topfn(stack s)
{
    if (!isEmpty(s))
    {
        return (s->next)->sfn;
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}
// char *topandpop(stack s)
// {
//     if (!isEmpty(s))
//     {
//         char *t = (s->next)->info;
//         pop(s);
//         return t;
//     }
//     else
//     {
//         printf("\nList is already Empty\n");
//     }
// }
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
void displaystack(stack s)
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
