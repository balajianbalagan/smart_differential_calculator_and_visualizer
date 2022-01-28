#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void differentiate(struct tree *etree, node diff)
{

    if (etree->tfn == 0)
    {
        insertEnd(diff, "0", 0);
    }
    else if (etree->tfn == 2)
    {
        insertEnd(diff, "1", 0);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "+") == 0)
    {
        insertEnd(diff, "(", 4);
        differentiate(etree->leftchild, diff);
        insertEnd(diff, "+", 3); //0-numbers 1-functions(sin,cos) 2-variable (x) 3-operators 4-open brackets 5-close brackets404-not defined yet
        differentiate(etree->rightchild, diff);
        insertEnd(diff, ")", 5);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "-") == 0)
    {
        insertEnd(diff, "(", 4);
        differentiate(etree->leftchild, diff);
        insertEnd(diff, "-", 3);
        differentiate(etree->rightchild, diff);
        insertEnd(diff, ")", 5);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "*") == 0)
    {
        insertEnd(diff, "(", 4);
        insertEnd(diff, "(", 4);
        strcpy(io, "\0");
        inorder(etree->leftchild);
        insertEnd(diff, io, 1);
        insertEnd(diff, "*", 3);
        differentiate(etree->rightchild, diff);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "+", 3);
        insertEnd(diff, "(", 4);
        strcpy(io, "\0");
        inorder(etree->rightchild);
        insertEnd(diff, io, 1);
        insertEnd(diff, "*", 3);
        differentiate(etree->leftchild, diff);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "/") == 0)
    {
        insertEnd(diff, "(", 4);
        insertEnd(diff, "(", 4);
        insertEnd(diff, "(", 4);
        strcpy(io, "\0");
        inorder(etree->leftchild);
        insertEnd(diff, io, 1);
        insertEnd(diff, "*", 3);
        differentiate(etree->rightchild, diff);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "-", 3);
        insertEnd(diff, "(", 4);
        strcpy(io, "\0");
        inorder(etree->rightchild);
        insertEnd(diff, io, 1);
        insertEnd(diff, "*", 3);
        differentiate(etree->leftchild, diff);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "/", 3);
        insertEnd(diff, "(", 4);
        strcpy(io, "\0");
        inorder(etree->rightchild);
        insertEnd(diff, io, 1);
        insertEnd(diff, "^", 3);
        insertEnd(diff, "2", 0);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "^") == 0)
    {
        int val = atoi(etree->rightchild->info);
        char str[50];
        sprintf(str, "%d", val - 1);
        insertEnd(diff, "(", 4);
        insertEnd(diff, "(", 4);
        insertEnd(diff, etree->rightchild->info, 1);
        insertEnd(diff, "*", 3);
        insertEnd(diff, "(", 4);
        insertEnd(diff, etree->leftchild->info, 1);
        insertEnd(diff, "^", 4);
        insertEnd(diff, "(", 4);
        insertEnd(diff, str, 1);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "*", 3);
        differentiate(etree->leftchild, diff);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
    }
}
