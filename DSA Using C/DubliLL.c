#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
typedef struct Node *node;

node CreateNode(int data)
{
    node n = (node)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void DisplayForward(node head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void DisplayBackWard(node last)
{
    while (last != NULL)
    {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

node InsertAtFirst(node head, int ele)
{
    node NewNode = CreateNode(ele);
    NewNode->next = head;
    head->prev = NewNode;
    return NewNode;
}

node InsertAtIndex(node head, int index, int ele)
{
    if (index == 0)
    {
        return InsertAtFirst(head, ele);
    }
    node newNode = CreateNode(ele);
    int temp = 1;
    node p = head;
    while (temp < index)
    {
        p = p->next;
        temp++;
    }
    newNode->prev = p;
    newNode->next = p->next;
    p->next->prev = newNode;
    p->next = newNode;
    return head;
}

int main()
{
    node head, second, third, fourth;
    head = CreateNode(11);
    second = CreateNode(22);
    third = CreateNode(33);
    fourth = CreateNode(44);
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;

    DisplayForward(head);
    DisplayBackWard(fourth);

    head = InsertAtFirst(head, 10);
    DisplayForward(head);
    DisplayBackWard(fourth);

    head = InsertAtIndex(head, 1, 12);
    DisplayForward(head);
    DisplayBackWard(fourth);

    return 0;
}