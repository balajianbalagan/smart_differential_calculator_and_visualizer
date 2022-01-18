#include <stdio.h>
#include <stdlib.h>
#define EmptyTOS -1
#define MINSTACKSIZE 3
struct stack_record
{
    int *SArray;
    int topofstack;
    int capacity;
};
typedef struct stack_record *stack;
stack createstack(int maxElements)
{
    stack s;
    if (maxElements < MINSTACKSIZE)
    {
        printf("Error:Stack size is too small\n");
    }
    else
    {
        s = (struct stack_record *)malloc(sizeof(struct stack_record));
        s->SArray = (int *)malloc(sizeof(int) * maxElements);
        if (s->SArray == NULL)
        {
            printf("Fatal Error\n");
        }
        s->topofstack = EmptyTOS;
        s->capacity = maxElements;
        printf("stack created\n");
        return s;
    }
}
int isFull(stack s)
{
    return ((s->topofstack) == ((s->capacity) - 1));
}
int isEmpty(stack s)
{
    return ((s->topofstack) == -1);
}
void DisposeStack(stack s)
{
    if (s->SArray != NULL)
    {
        free(s->SArray);
        free(s);
    }
    else
    {
        printf("Already Empty\n");
    }
}
stack push(stack s, int element)
{
    if (isFull(s))
    {
        printf("Stack is full new element can't be inserted\n");
    }
    else
    {
        s->SArray[++(s->topofstack)] = element;
    }
    return s;
}
void pop(stack s)
{
    if (isEmpty(s))
    {
        printf("stack is already empty can't do pop\n");
    }
    else
    {
        (s->topofstack)--;
        printf("POP occurred\n");
    }
}
int top(stack s)
{
    if (isEmpty(s))
    {
        printf("stack is empty can't display the top element\n");
    }
    else
    {
        return (s->SArray[s->topofstack]);
    }
}
int topandpop(stack s)
{
    if (!(isEmpty(s)))
    {
        int topelem = top(s);
        pop(s);
        printf("Pop occurred\n");
        return topelem;
    }
    return -1;
}
void makeempty(stack s)
{
    if (isEmpty(s))
    {
        printf("Already empty!");
    }
    else
    {
        s->topofstack = -1;
    }
}
void displaystack(stack s)
{
    if (!isEmpty(s))
    {
        printf("The elements are \n");
        for (int i = s->topofstack; i >= 0; i--)
        {
            printf(" %d ", s->SArray[i]);
        }
        printf("\n");
    }
    else
    {
        printf("The stack is empty\n");
    }
}