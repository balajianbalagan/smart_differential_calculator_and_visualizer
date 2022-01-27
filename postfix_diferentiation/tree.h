#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct treenode
{
    char info[200];
    int tfn;
    struct treenode *leftchild;
    struct treenode *rightchild;
    struct treenode *next;
};
struct treenode *head = NULL;
struct treenode *newNode(char *info, int tfn)
{
    struct treenode *node = (struct treenode *)malloc(sizeof(struct treenode));
    strcpy(node->info, info);
    node->tfn = tfn;
    node->leftchild = NULL;
    node->rightchild = NULL;
    node->next = NULL;

    return (node);
}
void printInorder(struct treenode *node)
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

void push(struct treenode *x)
{
    if (head == NULL)
        head = x;
    else
    {
        (x)->next = head;
        head = x;
    }
}
struct treenode *pop()
{
    struct treenode *p = head;
    head = head->next;
    return p;
}
int main()
{
    char s[] = {'A', 'B', 'C', '*', '+', 'D', '/'};
    int l = sizeof(s) / sizeof(s[0]);
    struct treenode *x, *y, *z;
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