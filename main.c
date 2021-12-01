#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
void linkedlisttraversal(struct Node * head)
{
    struct Node * p=head;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
}
struct Node * insertAtFrist(struct Node * head,int data)
{
    struct Node * ptr=(struct Node *)malloc(sizeof (struct Node));
    ptr->data=data;
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
struct Node * insertAtEnd(struct Node * head,int data)
{
    struct Node *new_node,*p;
    p=head;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=new_node;
    new_node->next=head;
    return head;
}
struct Node * insertAtAfter(struct Node * head,int data,int value)
{
    struct Node *new_node,*ptr,*p;
    int i=1;
    ptr=head;
    while(value!=ptr->data)
    {
        if(ptr->next==head)
        {
            i=0;
            break;
        }
        ptr=ptr->next;
    }
    if(i!=0)
    {
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=data;
        p=ptr->next;
        ptr->next=new_node;
        new_node->next=p;
    }
    return head;
}
struct Node * insertAtBefore(struct Node * head,int data,int value)
{
    struct Node * new_node,*ptr,*p,*p1;
    int i=1;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    ptr=head;
    if(ptr->data==value)
    {
        p=ptr->next;
        while(p->next!=head)
        {
            p=p->next;
        }
        p->next=new_node;
        new_node->next=head;
        head=new_node;
        return head;
    }
    else
    {
        while(value!=ptr->data)
        {
            if(ptr->next==head)
            {
                i=0;
                break;
            }
            p=ptr;
            ptr=ptr->next;
        }
        if(i!=0)
        {
            p->next=new_node;
            new_node->next=ptr;
            return head;
        }
    }
}
int main()
{
    struct Node *head;
    struct Node *newhead;
    struct Node *second;
    struct Node *thrid;
    //allocate memory for nodes in the linked list in heap
    head=(struct Node *)malloc(sizeof (struct Node));
    second=(struct Node *)malloc(sizeof (struct Node));
    thrid=(struct Node *)malloc(sizeof (struct Node));
    //link frist and second nodes;
    head->data=7;
    head->next=second;
    //link second and thrid nodes;
    second->data=11;
    second->next=thrid;
    //terminate list at the thried node;
    thrid->data=66;
    thrid->next=head;
    linkedlisttraversal(head);
    //head=insertAtFrist(head,20);
    head=insertAtEnd(head,30);
    printf("After Insertion\n");
    //head=insertAtAfter(head,32,11);
    head=insertAtBefore(head,33,3);
    linkedlisttraversal(head);
    return 0;
}
