#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *CreateNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    (*ptr).data = data;
    return ptr;
}
//Test

void Display(struct Node *head)
{
    struct Node * ptr=head;
    do
    {
        printf("%d ", (*ptr).data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct Node * InsertAtFirst(struct Node *head,int data)
{
    struct Node *newNode = CreateNode(data);
    struct Node *ptr = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next=newNode;
    newNode->next=head;
    return newNode;
}

void InsertAfterNode(struct Node * prev,int ele)
{
    struct Node * newNode = CreateNode(ele);
    newNode->next=prev->next;
    prev->next=newNode;
}


struct Node * DeleteFirst(struct Node * head)
{
    struct Node *newhead = head->next;
    struct Node *p = newhead;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = newhead;
    free(head);
    return newhead;

    
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = CreateNode(10);
    second = CreateNode(20);
    third = CreateNode(30);
    fourth = CreateNode(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    Display(head);

    head = InsertAtFirst(head,11);
    head = InsertAtFirst(head,12);
    Display(head);

    InsertAfterNode(third,33);
    Display(head);
    head = DeleteFirst(head);
    puts("After deleteFirst");
    Display(head);

    return 0;
}