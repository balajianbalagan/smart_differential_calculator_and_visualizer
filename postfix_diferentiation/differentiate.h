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
        insertEnd(diff, "+");
        insertEnd(diff, differentiate(etree->right_child));
    }
    else if (etree->fn == 3 && strcmp(etree->info, "-"))
    {
        insertEnd(diff, differentiate(etree->left_child));
        insertEnd(diff, "-");
        insertEnd(diff, differentiate(etree->right_child));
    }
    else if (etree->fn == 3 && strcmp(etree->info, "*"))
    {
        insertEnd(diff, inorder(etree->left_child));
        insertEnd(diff, differentiate(etree->right_child));
        insertEnd(diff, "+");
        insertEnd(diff, inorder(etree->right_child));
        insertEnd(diff, differentiate(etree->left_child));
    }
    else if (etree->fn == 3 && strcmp(etree->info, "/"))
    {
        insertEnd(diff, inorder(etree->left_child));
        insertEnd(diff, differentiate(etree->right_child));
        insertEnd(diff, "-");
        insertEnd(diff, inorder(etree->right_child));
        insertEnd(diff, differentiate(etree->left_child));
        insertEnd(diff, "/");
        insertEnd(diff, "(");
        insertEnd(diff, inorder(etree->right_child));
        insertEnd(diff, ")");
        insertEnd(diff, "^");
        insertEnd(diff, "2");
    }
    else if (etree->fn == 3 && strcmp(etree->info, "^"))
    {
        insertEnd(diff, etree->right_child->info);
        insertEnd(diff, "*");
        insertEnd(diff, "(");
        insertEnd(diff, etree->left_child->info);
        insertEnd(diff, "(");
        insertEnd(diff, etree->right_child->info - 1);
        insertEnd(diff, ")");
        insertEnd(diff, ")");
        insertEnd(diff, "*");
        insertEnd(diff, differentiate(etree->left_child));
    }
}

node differentialstring()
{
    node diff = createlist();
}
