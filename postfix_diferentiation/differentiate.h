#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// #include "doublylinkedlist.h"
// #include "tree.h"
void differentiate(struct tree *etree, node diff)
{
    printf("info===%s\n",etree->info);
    
    if (etree->tfn == 0)
    {
        insertEnd(diff, "0", 0);
        printf("oo\n");
        display(diff);
    }
    else if (etree->tfn == 1)
    {
        // node diff = createlist();
    }
    else if (etree->tfn == 2)
    {
        insertEnd(diff, "1", 0);
             printf("@@@@\n");
         display(diff);
       
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "+")==0)
    {
        printf("inside going...\n");
        differentiate(etree->leftchild, diff);
        display(diff);
        insertEnd(diff, "+", 3); //0-numbers 1-functions(sin,cos) 2-variable (x) 3-operators 4-open brackets 5-close brackets404-not defined yet
        printf("!!!!!\n");
         display(diff);
        differentiate(etree->rightchild, diff);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "-")==0)
    {
        differentiate(etree->leftchild, diff);
        insertEnd(diff, "-", 3);
        differentiate(etree->rightchild, diff);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "*")==0)
    {
        strcpy(io,"\0");
        inorder(etree->leftchild);
        insertEnd(diff, io, 1);
        insertEnd(diff, "*", 3);
        differentiate(etree->rightchild, diff);
        insertEnd(diff, "+", 3);
        strcpy(io,"\0");
        inorder(etree->rightchild);
        insertEnd(diff,io , 1);
        insertEnd(diff, "*", 3);
        differentiate(etree->leftchild, diff);

    }
    else if (etree->tfn == 3 && strcmp(etree->info, "/")==0)
    {
        strcpy(io,"\0");
        inorder(etree->leftchild);
        insertEnd(diff, io, 1);
        differentiate(etree->rightchild, diff);
        insertEnd(diff, "-", 3);
        strcpy(io,"\0");
        inorder(etree->rightchild);
        insertEnd(diff,io, 1);
        differentiate(etree->leftchild, diff);
        insertEnd(diff, "/", 3);
        insertEnd(diff, "(", 4);
        strcpy(io,"\0");
        inorder(etree->rightchild);
        insertEnd(diff,io , 1);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "^", 3);
        insertEnd(diff, "2", 0);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "^")==0)
    {
        insertEnd(diff, etree->rightchild->info, 1);
        insertEnd(diff, "*", 3);
        insertEnd(diff, "(", 4);
        insertEnd(diff, etree->leftchild->info, 1);
        insertEnd(diff, "(", 4);
        insertEnd(diff, etree->rightchild->info - 1, 1);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "*", 3);
        differentiate(etree->leftchild, diff);
    }
    printf("last---");display(diff);printf("\n");
}
