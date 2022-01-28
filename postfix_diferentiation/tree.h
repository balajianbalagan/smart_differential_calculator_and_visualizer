#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylinkedlist.h"
struct tree
{
    char info[200];
    int tfn;
    struct tree *leftchild;
    struct tree *rightchild;
    struct tree *next;
};
struct tree *head = NULL;
struct tree *newNode(char *info, int tfn)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    strcpy(node->info, info);
    node->tfn = tfn;
    node->leftchild = NULL;
    node->rightchild = NULL;
    node->next = NULL;

    return (node);
}
char io[100];
void inorder(struct tree *node)
{
    char *nu = "\0";
    if (node == NULL)
        return;
    else
    {
        inorder(node->leftchild);
        strcat(io, node->info);

        /* now recur on rightchild child */
        inorder(node->rightchild);
    }
}
void treepush(struct tree *x)
{
    if (head == NULL)
        head = x;
    else
    {
        (x)->next = head;
        head = x;
    }
}
struct tree *treepop()
{
    struct tree *p = head;
    head = head->next;
    return p;
}
struct tree *expressiontree(node inparr)
{
    struct tree *x, *y, *z;
    node temp = inparr->rptr;
    while (temp != NULL)
    {
        if (temp->fn == 3)
        {
            z = newNode(temp->info, temp->fn);
            x = treepop();
            y = treepop();
            z->leftchild = y;
            z->rightchild = x;
            treepush(z);
        }
        else
        {
            z = newNode(temp->info, temp->fn);
            treepush(z);
        }
        temp = temp->rptr;
    }
    return z;
}