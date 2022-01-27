#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void printInorder(struct tree *node)
{
    if (node == NULL)
        return;
    else
    {
        printInorder(node->leftchild);
        printf("%c ", node->info);

        /* now recur on rightchild child */
        printInorder(node->rightchild);
    }
}

void push(struct tree *x)
{
    if (head == NULL)
        head = x;
    else
    {
        (x)->next = head;
        head = x;
    }
}
struct tree *pop()
{
    struct tree *p = head;
    head = head->next;
    return p;
}
int main()
{
    char s[] = {'A', 'B', 'C', '*', '+', 'D', '/'};
    int l = sizeof(s) / sizeof(s[0]);
    struct tree *x, *y, *z;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            z = newNode(s[i]);
            x = pop();
            y = pop();
            z->leftchild = y;
            z->rightchild = x;
            push(z);
        }
        else
        {
            z = newNode(s[i]);
            push(z);
        }
    }
    printf(" The Inorder Traversal of Expression Tree: ");
    printInorder(z);
    return 0;
}