/*
//optimization
//step 1 : creating feedback input from findiff
convertostring(findiff);
printf("\nFeedback Input : %s\n", optstring);
//step 2 : storing it as a dll
node feedbackinputarray = createlist();
storinput(optstring, feedbackinputarray);
//step 3 : creating postfix expression again for optimizing output
node optoutput = postfix(feedbackinputarray);
printf("\nPostfix expression of optimization input : \n");
display(optoutput);
printf("\n");
//step 4 : evaluation of the postfix expression
stack evaloptout = evaluationofopt(optoutput);
printf("Differentiated expression after simplification : \n");
displaystack(evaloptout);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack evaluationofopt(node optout)
{
    int i, val, A1, B1;

    stack eval = create();
    node optoutput = createlist();
    node temp = optout->rptr->rptr;
    while (temp != NULL)
    {
        printf("info = %s\n", temp->info);
        char A[100], B[100], ch[100];
        char tempstr[100];
        strcat(ch, temp->info);
        if (temp->fn == 0)
        {
            push(eval, temp->info, temp->fn);
        }
        else if (temp->fn == 3)
        {
            strcat(A, top(eval));
            A1 = topfn(eval);
            printf("A=%s     fn=%d\n", A, A1);
            pop(eval);
            strcat(B, top(eval));
            B1 = topfn(eval);
            printf("B=%s     fn=%d\n", B, B1);
            pop(eval);
            if (strcmp(temp->info, "+") == 0)
            {
                printf("add\n");
                if ((strcmp(B, "0") == 0))
                {

                    strcat(tempstr, A);

                    push(eval, tempstr, 2);
                }
                else if ((strcmp(A, "0") == 0))
                {

                    strcat(tempstr, B);
                    printf("value : %s", tempstr);
                    push(eval, tempstr, 2);
                }
                else if (A1 == 2 && B1 == 2)
                {
                    strcat(tempstr, A);
                    strcat(tempstr, "+");
                    strcat(tempstr, B);
                    printf("value : %s", tempstr);
                    push(eval, tempstr, 2);
                }
                else
                {
                    val = atoi(A) + atoi(B);
                    sprintf(tempstr, "%d", val);
                    push(eval, tempstr, 0);
                }
            }
            if (strcmp(ch, "-") == 0)
            {
                if ((strcmp(B, "0") == 0))
                {
                    strcat(tempstr, A);
                    push(eval, tempstr, 2);
                }
                else if ((strcmp(A, "0") == 0))
                {
                    strcat(tempstr, B);
                    push(eval, tempstr, 2);
                }
                else if (A1 == 2 && B1 == 2)
                {
                    strcat(tempstr, A);
                    strcat(tempstr, "-");
                    strcat(tempstr, B);
                    push(eval, tempstr, 2);
                }
                else
                {
                    val = atoi(A) + atoi(B);
                    sprintf(tempstr, "%d", val - 1);
                    push(eval, tempstr, 0);
                }
            }
        }

        temp = temp->rptr;
    }
    return eval;
}
*/