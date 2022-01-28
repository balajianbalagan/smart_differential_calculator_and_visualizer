#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct noderec
{
    char info[200];
    int fn;//0-numbers 1-functions(sin,cos) 2-variable (x) 3-operators 4-open brackets 5-close brackets404-not defined yet
    struct noderec* lptr;
    struct noderec* rptr;
};
typedef struct noderec* node;
typedef node header;
node createlist()
{
    header l;
    l=(node)malloc(sizeof(struct noderec));
    l->lptr=NULL;
    l->rptr=NULL;
    return l;
}
int isEmptydllist(header l){
    if(l->lptr==NULL && l->rptr==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void insertBeg(header l,char* x,int fnval)
{
    node dnew;
    dnew=(node)malloc(sizeof(struct noderec));
    dnew->fn=fnval;
    strcpy(dnew->info,x);
    if(isEmptydllist(l))
    {
        dnew->rptr=NULL;
        dnew->lptr=l;
        l->rptr=dnew;
    }
    else{
        dnew->rptr=l->rptr;
        dnew->lptr=l;
        (l->rptr)->lptr=dnew;
        l->rptr=dnew;
    }
}
void insertEnd(header l,char *x,int fnval)
{
    node dnew,temp;
    dnew=(node)malloc(sizeof(struct noderec));
    strcpy(dnew->info,x);
    dnew->fn=fnval;
     if(isEmptydllist(l))
    {
        dnew->rptr=NULL;
        dnew->lptr=l;
        l->rptr=dnew;
    }
    else{
        // dnew->rptr=l;
        // dnew->lptr=l->lptr;
        // (l->lptr)->rptr=dnew;
        // l->lptr=dnew;
        dnew->rptr=NULL;
        temp=l->rptr;
        while(temp->rptr!=NULL)
        {
            temp=temp->rptr;
        }
        dnew->lptr=temp;
        temp->rptr=dnew;
    }
}
// void insertmid(header l,char * x,int pos,int fnval)
// {
//     node temp,dnew;
//     dnew=(node)malloc(sizeof(struct noderec));
//     strcpy(dnew->info,x);
//     dnew->fn=fnval;
//     if(isEmptydllist(l))
//     {
//         dnew->rptr=NULL;
//         dnew->lptr=l;
//         l->rptr=dnew;
//     }
//     else{
//         int i=1;
//         temp=l;
//         while(temp->rptr!=NULL && i<pos)
//         {
//             temp=temp->rptr;i++;
//         }
//         if(temp->rptr==NULL)
//         {
//             dnew->rptr=NULL;
//             dnew->lptr=temp;
//             temp->rptr=dnew;
//         }
//         else{
//             dnew->rptr=temp->rptr;
//             dnew->lptr=temp;
//             (temp->rptr)->lptr=dnew;
//             temp->rptr=dnew;
//         }
//     }
// }
void display(header l)
{
    node temp;
    if(isEmptydllist(l))
    {
        printf("List is empty No elements\n");
    }
    else{
        temp=l->rptr;
        printf("The elements are : ");
        while(temp!=NULL)
        {
            // printf(" %s %d \n",temp->info,temp->fn);
            printf(" %s ",temp->info);
            temp=temp->rptr;
        }
        printf("\n");
    }
}


//extras
// void delete(header l,char* x)
// {
//     node temp;
//     if(isEmptydllist(l))
//     {
//         printf("List is Empty\n");
//     }
//     else{
//         temp=l->rptr;
//         while(temp!=NULL && temp->info!=x)
//         {
//             temp=temp->rptr;
//         }
//         if(temp==NULL)
//         {
//             printf("Element not found\n");
//         }
//         else if(temp->rptr==NULL){
//             (temp->lptr)->rptr=NULL;
//             free(temp);
//         }
//         else{
//             temp->lptr->rptr=temp->rptr;
//             temp->rptr->lptr=temp->lptr;
//             free(temp);
//             printf("The element deleted\n");
//         }
//     }
// }
// void search(header l,int x)
// {
//     if(isEmptydllist(l))
//     {
//         printf("List is empty no search\n");
//     }
//     else{
//         int i=1;
//         node temp=l->rptr;
//         while (temp!=NULL && temp->info!=x)
//         {
//             temp=temp->rptr;i++;
//         }
//         if(temp==NULL)
//         {
//             printf("Not found\n");
//         }
//         else{
//             printf("The position is : %d  \n",i);
//         }
//     }
// }
// int main()
// {
//     node m=createlist();
//     insertEnd(m,"sd",404);
//     display(m);
// }
struct tree
{
    char info[200];
    int tfn;
    struct tree *leftchild;
    struct tree *rightchild;
    struct tree *next;
};
struct tree *head = NULL;
struct tree *newNode(char *info, int tfn)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    strcpy(node->info, info);
    node->tfn = tfn;
    node->leftchild = NULL;
    node->rightchild = NULL;
    node->next = NULL;

    return (node);
}
// char * inorder(struct tree *node,char *io)
// {
//     char *nu="\0";
//     if (node == NULL)
//         return nu;
//     else
//     {
//         char *l=inorder(node->leftchild,io);

//         printf( " inside==%s\n",node->info);
       
//         strcat(io, node->info);
//          printf( " io==%s\n",io);
//         /* now recur on rightchild child */
//          char *ll=inorder(node->rightchild,io);
//     }
//     printf("1\n");
//     char *tptr=io;
//     return tptr;
// }
char io[100];
void  inorder(struct tree *tnode)
{
    char *nu="\0";
    if (tnode == NULL)
        return ;
    else
    {
        inorder(tnode->leftchild);
        strcat(io, tnode->info);

        /* now recur on rightchild child */
        inorder(tnode->rightchild);
    }
    
}
void treepush(struct tree *x)
{
    if (head == NULL)
        head = x;
    else
    {
        (x)->next = head;
        head = x;
    }
}
struct tree *treepop()
{
    struct tree *p = head;
    head = head->next;
    return p;
}
struct tree* expressiontree(node inparr)
{
    struct tree *x, *y, *z;
    node temp=inparr->rptr;
    while (temp!=NULL)
    {
        if(temp->fn==3)
        {
            z = newNode(temp->info,temp->fn);
            x = treepop();
            y = treepop();
            z->leftchild = y;
            z->rightchild = x;
            treepush(z);
        }
        else{
            z = newNode(temp->info,temp->fn);
            treepush(z);
        }
        temp=temp->rptr;
    }
    return z;
    
}
// int main()
// {
//     char s[] = {'A', 'B', 'C', '*', '+', 'D', '/'};
//     int l = sizeof(s) / sizeof(s[0]);
//     struct tree *x, *y, *z;
//     for (int i = 0; i < l; i++)
//     {
//         if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
//         {
//             z = newNode(s[i]);
//             x = pop();
//             y = pop();
//             z->leftchild = y;
//             z->rightchild = x;
//             push(z);
//         }
//         else
//         {


//             z = newNode(s[i]);
//             push(z);
//         }
//     }
//     printf(" The Inorder Traversal of Expression Tree: ");
//     printInorder(z);
//     return 0;
// }
struct snoderec
{
    char info[300];
    int sfn;
    struct snoderec *next;
};
typedef struct snoderec *snode;
snode temp, prev,snew;
typedef snode stack;

stack create()
{
    stack s;
    s = (struct snoderec *)malloc(sizeof(struct snoderec *));
    s->next = NULL;
}

int isEmpty(stack s)
{
    return (s->next == NULL);
}
void push(stack s, char *x,int sfnval)
{
    snew = (struct snoderec *)malloc(sizeof(struct snoderec *));
    strcpy(snew->info, x);
    snew->sfn=sfnval;
    // strcpy(s->next,snew);
    // snew->info = x;
    snew->next = s->next;
    s->next = snew;
}
void pop(stack s)
{
    if (!isEmpty(s))
    {
        temp = s->next;
        s->next = temp->next;
        free(temp);
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
char *top(stack s)
{
    char *res;
    if (!isEmpty(s))
    {
        res = (s->next)->info;
        return res;
    }
    else
    {
        printf("\nList is already Empty\n");
        return "\0";
    }
}
int topfn(stack s)
{
    if(!isEmpty(s))
    {
        return (s->next)->sfn;
    }
    else{
        printf("Stack is empty\n");
        return -1;
    }
}
// char *topandpop(stack s)
// {
//     if (!isEmpty(s))
//     {
//         char *t = (s->next)->info;
//         pop(s);
//         return t;
//     }
//     else
//     {
//         printf("\nList is already Empty\n");
//     }
// }
void makeempty(stack s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
}
void disposestack(stack s)
{
    if (s != NULL)
    {
        makeempty(s);
        free(s);
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
void displaystack(stack s)
{
    temp = s->next;
    if (!isEmpty(s))
    {
        while (temp != NULL)
        {
            printf("%s ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nList is already Empty\n");
    }
}
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
        display(parsearr);
        return parsearr;
    }
}
// void differentiate(struct tree *etree, node findiff)
// {
//     node diff = createlist();
//     if (etree->tfn == 0)
//     {
//         insertEnd(diff, "0", 0);
//     }
//     else if (etree->tfn == 1)
//     {
//         // node diff = createlist();
//     }
//     else if (etree->tfn == 2)
//     {
//         if (strcmp("x", etree->info))
//         {
//             insertEnd(diff, "1", 0);
//         }
//     }
//     else if (etree->tfn == 3 && strcmp(etree->info, "+"))
//     {
//         differentiate(etree->leftchild, diff);
//         insertEnd(diff, "+", 3); //0-numbers 1-functions(sin,cos) 2-variable (x) 3-operators 4-open brackets 5-close brackets404-not defined yet
//         differentiate(etree->rightchild, diff);
//     }
//     else if (etree->tfn == 3 && strcmp(etree->info, "-"))
//     {
//         differentiate(etree->leftchild, diff);
//         insertEnd(diff, "-", 3);
//         differentiate(etree->rightchild, diff);
//     }
//     else if (etree->tfn == 3 && strcmp(etree->info, "*"))
//     {
//         insertEnd(diff, inorder(etree->leftchild), 1);
//         strcpy(io,"\0");
//         differentiate(etree->rightchild, diff);
//         insertEnd(diff, "+", 3);
//         insertEnd(diff, inorder(etree->rightchild), 1);
//         strcpy(io,"\0");
//         differentiate(etree->leftchild, diff);
//     }
//     else if (etree->tfn == 3 && strcmp(etree->info, "/"))
//     {
//         insertEnd(diff, inorder(etree->leftchild), 1);strcpy(io,"\0");
//         differentiate(etree->rightchild, diff);
//         insertEnd(diff, "-", 3);
//         insertEnd(diff, inorder(etree->rightchild), 1);strcpy(io,"\0");
//         differentiate(etree->leftchild, diff);
//         insertEnd(diff, "/", 3);
//         insertEnd(diff, "(", 4);
//         insertEnd(diff, inorder(etree->rightchild), 1);strcpy(io,"\0");
//         insertEnd(diff, ")", 5);
//         insertEnd(diff, "^", 3);
//         insertEnd(diff, "2", 0);
//     }
//     else if (etree->tfn == 3 && strcmp(etree->info, "^"))
//     {
//         insertEnd(diff, etree->rightchild->info, 1);
//         insertEnd(diff, "*", 3);
//         insertEnd(diff, "(", 4);
//         insertEnd(diff, etree->leftchild->info, 1);
//         insertEnd(diff, "(", 4);
//         insertEnd(diff, etree->rightchild->info - 1, 1);
//         insertEnd(diff, ")", 5);
//         insertEnd(diff, ")", 5);
//         insertEnd(diff, "*", 3);
//         differentiate(etree->leftchild, diff);
//     }
//     display(diff);
//     findiff = diff;
// }
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

    struct tree *t = expressiontree(output);
    inorder(t);
    printf("%s",io);
    // node findiff = createlist();
    // differentiate(t, findiff);
    // printf("Differentiated ecpression : \n");
    // display(findiff);
    return 0;
}

