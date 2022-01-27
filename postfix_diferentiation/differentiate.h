#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "tree.h"

node differentiate(struct tree *etree, node findiff)
{
    node diff = createlist();
    if (etree->tfn == 0)
    {
        insertEnd(diff, "0", 0);
    }
    else if (etree->tfn == 1)
    {
        // node diff = createlist();
    }
    else if (etree->tfn == 2)
    {
        if (strcmp("x", etree->info))
        {
            insertEnd(diff, "1", 0);
        }
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "+"))
    {
        insertEnd(diff, differentiate(etree->leftchild));
        insertEnd(diff, "+", 3); //0-numbers 1-functions(sin,cos) 2-variable (x) 3-operators 4-open brackets 5-close brackets404-not defined yet
        insertEnd(diff, differentiate(etree->rightchild));
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "-"))
    {
        insertEnd(diff, differentiate(etree->leftchild), 1);
        insertEnd(diff, "-", 3);
        insertEnd(diff, differentiate(etree->rightchild), 1);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "*"))
    {
        insertEnd(diff, inorder(etree->leftchild), 1);
        insertEnd(diff, differentiate(etree->rightchild), 1);
        insertEnd(diff, "+", 3);
        insertEnd(diff, inorder(etree->rightchild), 1);
        insertEnd(diff, differentiate(etree->leftchild), 1);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "/"))
    {
        insertEnd(diff, inorder(etree->leftchild), 1);
        insertEnd(diff, differentiate(etree->rightchild), 1);
        insertEnd(diff, "-", 3);
        insertEnd(diff, inorder(etree->rightchild), 1);
        insertEnd(diff, differentiate(etree->leftchild), 1);
        insertEnd(diff, "/", 3);
        insertEnd(diff, "(", 4);
        insertEnd(diff, inorder(etree->rightchild), 1);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "^", 3);
        insertEnd(diff, "2", 0);
    }
    else if (etree->tfn == 3 && strcmp(etree->info, "^"))
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
        insertEnd(diff, differentiate(etree->leftchild), 1);
    }
    findiff = diff;
}
