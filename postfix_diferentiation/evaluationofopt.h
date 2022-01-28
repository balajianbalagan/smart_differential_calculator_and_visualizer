#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node evaluationofopt(node postopt)
{
    int i, A, B, val;
    char ch[100];

    stack eval;
    node optoutput = createlist();
    node temp = postopt->rptr;
    while (temp != NULL)
    {

        temp = temp->rptr;
    }
    return optoutput;
}