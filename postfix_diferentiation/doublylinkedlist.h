#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct noderec
{
    char info[200];
    int fn; //0-numbers 1-functions(sin,cos) 2-variable (x) 3-operators 4-open brackets 5-close brackets404-not defined yet
    struct noderec *lptr;
    struct noderec *rptr;
};
typedef struct noderec *node;
typedef node header;
node createlist()
{
    header l;
    l = (node)malloc(sizeof(struct noderec));
    l->lptr = NULL;
    l->rptr = NULL;
    return l;
}
int isEmptydllist(header l)
{
    if (l->lptr == NULL && l->rptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insertBeg(header l, char *x, int fnval)
{
    node dnew;
    dnew = (node)malloc(sizeof(struct noderec));
    dnew->fn = fnval;
    strcpy(dnew->info, x);
    if (isEmptydllist(l))
    {
        dnew->rptr = NULL;
        dnew->lptr = l;
        l->rptr = dnew;
    }
    else
    {
        dnew->rptr = l->rptr;
        dnew->lptr = l;
        (l->rptr)->lptr = dnew;
        l->rptr = dnew;
    }
}
void insertEnd(header l, char *x, int fnval)
{
    node dnew, temp;
    dnew = (node)malloc(sizeof(struct noderec));
    strcpy(dnew->info, x);
    dnew->fn = fnval;
    if (isEmptydllist(l))
    {
        dnew->rptr = NULL;
        dnew->lptr = l;
        l->rptr = dnew;
    }
    else
    {
        dnew->rptr = NULL;
        temp = l->rptr;
        while (temp->rptr != NULL)
        {
            temp = temp->rptr;
        }
        dnew->lptr = temp;
        temp->rptr = dnew;
    }
}
void display(header l)
{
    node temp;
    if (isEmptydllist(l))
    {
        printf("List is empty No elements\n");
    }
    else
    {
        temp = l->rptr;
        printf("The elements are : ");
        while (temp != NULL)
        {
            printf(" %s ", temp->info);
            temp = temp->rptr;
        }
        printf("\n");
    }
}
char optstring[100];
void convertostring(header l)
{
    node temp;
    if (isEmptydllist(l))
    {
        printf("List is empty No elements\n");
    }
    else
    {
        temp = l->rptr;
        printf("The elements are : ");
        while (temp != NULL)
        {
            // printf(" %s %d \n",temp->info,temp->fn);
            strcat(optstring, temp->info);
            temp = temp->rptr;
        }
    }
}

void displaywithoutspace(header l)
{
    node temp;
    if (isEmptydllist(l))
    {
        printf("List is empty No elements\n");
    }
    else
    {
        temp = l->rptr;
        printf("The elements are : ");
        while (temp != NULL)
        {
            // printf(" %s %d \n",temp->info,temp->fn);
            printf("%s", temp->info);
            temp = temp->rptr;
        }
        printf("\n");
    }
}
