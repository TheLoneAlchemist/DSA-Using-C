#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    int *arr;

} stack;

int isFull(stack *sp);
int isEmpty(stack *sp);
void push(stack *sp, int data);
int pop(stack *sp);
int peek(stack *sp, int ele);
void Display(stack *sp);
int stackTop(stack *sp);
int stackButtom(stack *sp);
int main(int argc, char const *argv[])
{
    stack *sp = (stack *)malloc(sizeof(stack));
    // printf("%d",sizeof(stack)); //sizeof this stack is 4+4+8=16
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sizeof(int) * sp->size);
    printf("Stack is %s\n",isEmpty(sp)?"Empty":"Not Empty");
    printf("Stack is %s\n",isFull(sp)?"Full":"Not Full");

    push(sp,10);
    push(sp,20);
    push(sp,30);
    push(sp,40);


    printf("Stack is %s\n",isEmpty(sp)?"Empty":"Not Empty");
    printf("Stack is %s\n",isFull(sp)?"Full":"Not Full");

    push(sp,50);
    printf("Stack is %s\n",isEmpty(sp)?"Empty":"Not Empty");
    printf("Stack is %s\n",isFull(sp)?"Full":"Not Full");
    push(sp,44);
    Display(sp);
    printf("%d\n", peek(sp,2));

    printf("top element: %d\n",stackTop(sp));
    printf("top element: %d\n",stackButtom(sp));
    return 0;
}

void push(stack *sp, int data)
{
    if (isFull(sp))
    {
        printf("Stack Overflow!, can not push %d\n",data);
    }
    else{
        sp->top++;
        sp->arr[sp->top] = data;
    }
    
}

int pop(stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack underflow! can't pop...");
        return -1;
    }
    else
    {
        int value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
    
    
}

int isEmpty(stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(stack *sp)
{
    if (sp->top >= sp->size - 1)
    {
        return 1;
    }
    return 0;
}

int peek(stack *sp, int position)
{
    int arrIndex = sp->top-position+1;
    if (arrIndex<0 || arrIndex>sp->top)
    {
        printf("Not a valid position\n");
        return -1;
    }
    else
    {
        return sp->arr[arrIndex];
    }
}

void Display(stack *sp)
{
    for (int i = sp->size-1; i >=0; i--)
    {
        printf("%d\n",sp->arr[i]);
    }
    printf("\n");
}

int stackTop(stack *sp)
{
    return sp->arr[sp->top];
}
int stackButtom(stack *sp)
{
    return sp->arr[0];
}