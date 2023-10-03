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
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void Display(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Insert At Begin [O(1)]

struct Node *InsertAtFirst(struct Node *head, int element)
{
    struct Node *ptr = CreateNode(element);
    ptr->next = head;
    return ptr;
}

// Insert At End  [O(n)]
struct Node *InsertAtEnd(struct Node *head, int element)
{
    struct Node *ptr = head;
    struct Node *newNode = CreateNode(element);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return head;
}

// Insert At between  [O(n)]

void InsertAt(struct Node *head, int index, int element)
{
    struct Node *ptr = head;
    struct Node *newNode = CreateNode(element);
    int temp = 0;

    while (temp < index - 1)
    {
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

//Insert After a Node
void InsertAfterNode(struct Node *prev, int element)
{
    struct Node *node = CreateNode(element);
    node->next = prev->next;
    prev->next = node;
}

struct Node *DeleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

void DeleteLast(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    struct Node *q = ptr->next;
    ptr->next = NULL;
    free(q);
}

void DeleteAt(struct Node *head, int index)
{
    struct Node * ptr = head;
    int temp = 0;
    while (temp<index-1)
    {
        temp++;
        ptr = ptr->next;
    }
    struct Node * p = ptr->next;
    ptr->next = p->next;
    free(p);

}

struct Node * DeleteHavingValue(struct Node *head, int element)
{
    struct Node * p= head;
    struct Node * q = head->next;

    if (head->data == element)
    {
        return DeleteFirst(head);
    }

   while (q->data != element && q!=NULL)
   {
     q = q->next;
     p = p->next;
   }
   
   if (q->data == element)
   {
    p->next = q->next;
    free(q);
   }

   return head;
   
    
}

int Search(struct Node *head, int element)
{
    struct Node * ptr = head;
    int i=0;
    while (ptr!=NULL)
    {
        if (ptr->data==element)
        {
            return i;
        }
        i++;
        ptr=ptr->next;
    }
    
    return -1;
}


int main()
{
    // defination
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Memory Allocation
    head = CreateNode(10);
    second = CreateNode(20);
    third = CreateNode(30);
    fourth = CreateNode(40);

    // Linking the node
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    Display(head);
    head = InsertAtFirst(head, 9);
    Display(head);

    head = InsertAtEnd(head, 50);
    Display(head);

    InsertAt(head, 1, 33);
    Display(head);

    InsertAfterNode(third, 22);
    Display(head);

    head = DeleteHavingValue(head,22);
    Display(head);

    DeleteAt(head,1);
    Display(head);

    DeleteLast(head);
    Display(head);

    head = DeleteFirst(head);
    Display(head);

    printf("element found at %d",Search(head,30));


    return 0;
}