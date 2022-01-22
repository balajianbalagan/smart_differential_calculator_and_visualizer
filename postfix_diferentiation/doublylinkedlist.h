#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            printf("%s",temp->info);
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