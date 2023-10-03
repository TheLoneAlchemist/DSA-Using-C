#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node *node;

void Display(node top)
{
    printf("--------\n");
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
    printf("--------\n");
}

node CreateNode(int data)
{
    node n = (node)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

int isEmpty(node n)
{
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    node n2 = (node)malloc(sizeof(node));
    if (n2 == NULL)
    {
        return 1;
    }
    return 0;
    free(n2);
}

node push(node n, int data)
{
    if (isFull(n))
    {
        puts("Stack OverFlow!");
        return NULL;
    }
    else
    {
        node new = CreateNode(data);
        new->next = n;
        return new;
    }
}

node pop(node top)
{
    if (isEmpty(top))
    {
        puts("Stack Underflow!");
        return NULL;
    }
    else
    {
        node n = top->next;

        free(top);
        return n;
    }
}

int main()
{
    node top = NULL;
    top = push(top, 11);
    top = push(top, 12);
    top = push(top, 13);
    Display(top);

    top = pop(top);
    top = pop(top);
    top = pop(top);
    Display(top);
    top = pop(top);

    return 0;
}