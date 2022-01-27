#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "doublylinkedlist.h"
#include "tree.h"

node differentiate(tree etree)
{
    if (etree->fn == 0)
    {
        return "0";
    }
    else if (etree->fn == 1)
    {
        // node diff = createlist();
    }
    else if (etree->fn == 2)
    {
        if (strcmp("x", etree->info))
        {
            return "1";
        }
    }
    else if (etree->fn == 3 && strcmp(etree->info, "+"))
    {
        insertEnd(diff, differentiate(etree->left_child));
        insertEnd(diff, "+", 3); //0-numbers 1-functions(sin,cos) 2-variable (x) 3-operators 4-open brackets 5-close brackets404-not defined yet
        insertEnd(diff, differentiate(etree->right_child));
    }
    else if (etree->fn == 3 && strcmp(etree->info, "-"))
    {
        insertEnd(diff, differentiate(etree->left_child), 1);
        insertEnd(diff, "-", 3);
        insertEnd(diff, differentiate(etree->right_child), 1);
    }
    else if (etree->fn == 3 && strcmp(etree->info, "*"))
    {
        insertEnd(diff, inorder(etree->left_child), 1);
        insertEnd(diff, differentiate(etree->right_child), 1);
        insertEnd(diff, "+", 3);
        insertEnd(diff, inorder(etree->right_child), 1);
        insertEnd(diff, differentiate(etree->left_child), 1);
    }
    else if (etree->fn == 3 && strcmp(etree->info, "/"))
    {
        insertEnd(diff, inorder(etree->left_child), 1);
        insertEnd(diff, differentiate(etree->right_child), 1);
        insertEnd(diff, "-", 3);
        insertEnd(diff, inorder(etree->right_child), 1);
        insertEnd(diff, differentiate(etree->left_child), 1);
        insertEnd(diff, "/", 3);
        insertEnd(diff, "(", 4);
        insertEnd(diff, inorder(etree->right_child), 1);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "^", 3);
        insertEnd(diff, "2", 0);
    }
    else if (etree->fn == 3 && strcmp(etree->info, "^"))
    {
        insertEnd(diff, etree->right_child->info, 1);
        insertEnd(diff, "*", 3);
        insertEnd(diff, "(", 4);
        insertEnd(diff, etree->left_child->info, 1);
        insertEnd(diff, "(", 4);
        insertEnd(diff, etree->right_child->info - 1, 1);
        insertEnd(diff, ")", 5);
        insertEnd(diff, ")", 5);
        insertEnd(diff, "*", 3);
        insertEnd(diff, differentiate(etree->left_child), 1);
    }
}

node differentialstring()
{
    node diff = createlist();
}
