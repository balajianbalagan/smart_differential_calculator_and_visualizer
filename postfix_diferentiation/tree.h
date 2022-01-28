#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylinkedlist.h"
// 1) inorder shld return a string
// 2) no main function shld be involved
// 3)
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
// char * inorder(struct tree *node,char *io)
// {
//     char *nu="\0";
//     if (node == NULL)
//         return nu;
//     else
//     {
//         char *l=inorder(node->leftchild,io);

//         printf( " inside==%s\n",node->info);
       
//         strcat(io, node->info);
//          printf( " io==%s\n",io);
//         /* now recur on rightchild child */
//          char *ll=inorder(node->rightchild,io);
//     }
//     printf("1\n");
//     char *tptr=io;
//     return tptr;
// }
char io[100];
void inorder(struct tree *node)
{
    char *nu="\0";
    if (node == NULL)
        return ;
    else
    {
        inorder(node->leftchild);
        strcat(io, node->info);
        printf("fns- %d \n",node->tfn);

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
struct tree* expressiontree(node inparr)
{
    struct tree *x, *y, *z;
    node temp=inparr->rptr;
    while (temp!=NULL)
    {
        if(temp->fn==3)
        {
            z = newNode(temp->info,temp->fn);
            x = treepop();
            y = treepop();
            z->leftchild = y;
            z->rightchild = x;
            treepush(z);
        }
        else{
            z = newNode(temp->info,temp->fn);
            treepush(z);
        }
        temp=temp->rptr;
    }
    return z;
    
}
// int main()
// {
//     char s[] = {'A', 'B', 'C', '*', '+', 'D', '/'};
//     int l = sizeof(s) / sizeof(s[0]);
//     struct tree *x, *y, *z;
//     for (int i = 0; i < l; i++)
//     {
//         if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
//         {
//             z = newNode(s[i]);
//             x = pop();
//             y = pop();
//             z->leftchild = y;
//             z->rightchild = x;
//             push(z);
//         }
//         else
//         {


//             z = newNode(s[i]);
//             push(z);
//         }
//     }
//     printf(" The Inorder Traversal of Expression Tree: ");
//     printInorder(z);
//     return 0;
// }