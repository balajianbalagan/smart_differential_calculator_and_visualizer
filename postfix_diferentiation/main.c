#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "postfix.h"
#include "differentiate.h"

int numstr(char *n, node arr)
{
    int i, k, nlen = strlen(n);
    char *tmp = n, *res = malloc(225);
    for (i = 0; i < nlen; i++)
    {
        if (!isdigit(tmp[i]))
        {
            if (tmp[i] == '.')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }

    for (k = 0; k < i; k++)
    {
        *(res + k) = n[k];
    }
    *(res + k) = '\0';
    insertEnd(arr, res, 0); //insert end to the doubly linked list
    return i - 1;
}
void storinput(char *str, node arr)
{
    char *temp = str;
    int leng = strlen(str), skip; //skip variable to store the value of the index from the numstr
    for (int i = 0; i <= leng; i++)
    {
        if (isdigit(temp[i]))
        {
            skip = numstr(temp + i, arr);
            i += skip;
        }
        else if (temp[i] == 'x')
        {
            insertEnd(arr, "x", 2);
        }
        else if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/' || temp[i] == '^')
        {
            char ins[] = "\0";
            strncat(ins, &temp[i], 1);
            insertEnd(arr, ins, 3);
        }
        else if (temp[i] == '{' || temp[i] == '[' || temp[i] == '(')
        {
            char ins[] = "\0";
            strncat(ins, &temp[i], 1);
            insertEnd(arr, ins, 4);
        }
        else if (temp[i] == '}' || temp[i] == ']' || temp[i] == ')')
        {
            char ins[] = "\0";
            strncat(ins, &temp[i], 1);
            insertEnd(arr, ins, 5);
        }
    }
}
int main()
{
    //differentiation basics
    //step 1) getting the input as a string
    node inputarray = createlist();
    char inpstr[300];
    scanf("%[^\n]%*c", inpstr);
    //step 2) inserting into linked list and prioritizing inputs
    storinput(inpstr, inputarray); //=======> kanivan
    //step 3) converting to postfix
    node output = postfix(inputarray);
    printf("Postfix expression of input : \n");
    display(output);
    printf("\n");
    //step 4) creating expression tree
    struct tree *t = expressiontree(output); //=======> balaju
    // inorder(t);
    // printf("%s", io);
    strcpy(io, "\0");
    //step 5) differentiation of expression tree
    node findiff = createlist();
    differentiate(t, findiff);
    printf("Differentiated expression before simplification : \n");
    displaywithoutspace(findiff);
    printf("\n");

    return 0;
}
