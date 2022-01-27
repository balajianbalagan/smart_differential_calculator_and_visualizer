#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "postfix.h"

// #include "tree.h"
// #include "differentiate.h"

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
        // else{
        //     char ins[]="\0";
        //     strncat(ins,&temp[i],1);
        //     insertEnd(arr,ins,404);
        // }
    }
}
int main()
{
    node inputarray = createlist();
    char inpstr[300];
    scanf("%[^\n]%*c", inpstr);
    storinput(inpstr, inputarray);

    node output = postfix(inputarray);
    printf("Postfix expression : \n");
    display(output);
    printf("\n");

    struct tree * t = expressiontree(output);

    node diff = createlist();
    differentiate(t, diff);
    printf("Differentiated ecpression : \n");
    display(diff);
    return 0;
}
