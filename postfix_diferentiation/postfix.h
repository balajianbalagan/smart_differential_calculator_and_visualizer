#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "doublylinkedlist.h"
node postfix(node inparr)
{
    if(isEmptydllist(inparr))
    {
        printf("***The expression is empty ***\n");
    }
    else{
        node temp, parsearr=createlist();
        stack postfix_stack=create();
        push(postfix_stack,"(",4);
        temp=inparr;
        insertEnd(temp,")",5);
        while(temp!=NULL)
        {
           if(temp->fn==0 || temp->fn==2  )//check for numbers
           {
               insertEnd(parsearr,temp->info,temp->fn);
           }
           else if(temp->fn==4){//check for open parenthesis
               push(postfix_stack,temp->info,temp->fn);
           }
           else if(temp->fn==3)//check for operators
           {
              
               if(strcmp("*",temp->info)==0 || strcmp("/",temp->info)==0)
               {

                   while((strcmp(top(postfix_stack),"*")==0) || (strcmp(top(postfix_stack),"/")==0))
                   {
                        insertEnd(parsearr,top(postfix_stack),topfn(postfix_stack));
                        printf("%s",top(postfix_stack));
                        pop(postfix_stack);
                   }
                    push(postfix_stack,temp->info,temp->fn);
               }
               else if(strcmp("^",temp->info)==0)
               {

                   while(strcmp("^",top(postfix_stack))==0)
                   {
                       insertEnd(parsearr,top(postfix_stack),topfn(postfix_stack));
                        pop(postfix_stack);
                   }
                   push(postfix_stack,temp->info,temp->fn);
               }
               else if(strcmp("+",temp->info)==0 || strcmp("-",temp->info)==0)
               {
                   while((strcmp(top(postfix_stack),"+")==0) || (strcmp(top(postfix_stack),"-")==0) || (strcmp(top(postfix_stack),"*")==0) || (strcmp(top(postfix_stack),"/")==0) )
                   {
                        insertEnd(parsearr,top(postfix_stack),topfn(postfix_stack));
                        pop(postfix_stack);
                   }
                   push(postfix_stack,temp->info,temp->fn);
               }
               
           }
           else if(strcmp("]",temp->info)==0)
            {
                while(strcmp("[",top(postfix_stack))!=0)
                   {
                       insertEnd(parsearr,top(postfix_stack),topfn(postfix_stack));
                        pop(postfix_stack);
                   }
                   pop(postfix_stack);
               }
               else if(strcmp("}",temp->info)==0)
               {
                   while(strcmp("{",top(postfix_stack))!=0)
                   {
                       insertEnd(parsearr,top(postfix_stack),topfn(postfix_stack));
                        pop(postfix_stack);
                   }
                   pop(postfix_stack);
               }
               else if(strcmp(")",temp->info)==0)
               {
                   while(strcmp("(",top(postfix_stack))!=0)
                   {
                       insertEnd(parsearr,top(postfix_stack),topfn(postfix_stack));
                        pop(postfix_stack);
                   }
                   pop(postfix_stack);
               }
            temp=temp->rptr;
        }
        return parsearr;
    }
}
