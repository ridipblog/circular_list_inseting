#include<stdio.h>
#include<stdlib.h>
int check=0;
struct Node
{
    int data;
    struct Node * next;
};
struct Node * insertAtFrist(struct Node * head,int data)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    ptr->data=data;
    while(p->next!=head)
    {
        p=p->next;
    }
    ptr->next=head;
    p->next=ptr;
    head=ptr;
    return head;
};
struct Node * insertAtIndexLast(struct Node * head,int data,int index)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    int i=0;
    index=index-1;
    if(index==-1)
    {
        printf("\n0 Is Not Index ");
    }
    else
    {
        while(i!=index)
        {
            i++;
            p=p->next;
        }
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
        return head;
    }
};
struct Node * insertAtIndexFrist(struct Node * head,int data,int index)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    struct Node * temp;
    int i=0;
    index=index-1;
    if(index==-1)
    {
        printf("\n0 Is Not Index");
    }
    else
    {
        while(i!=index)
        {
            i++;
            temp=p;
            p=p->next;
        }
        ptr->data=data;
        ptr->next=p;
        if(index==0)
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=ptr;
            head=ptr;
        }
        else
        {
            temp->next=ptr;
        }
        return head;
    }
};
struct Node * insertAtEnd(struct Node * head,int data)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    ptr->data=data;
    while(p->next!=head)
    {
        p=p->next;
    }
    ptr->next=head;
    p->next=ptr;
    return head;
};
//Deletion Program Start
struct Node * deleteAtFrist(struct Node * head)
{
    struct Node * p=head;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        if(p->next==head)
        {
            printf("\nDeleted Data %d ",head->data);
            free(head);
            head=NULL;
            check=0;
        }
        else if(head==NULL)
        {
            printf("\nNo Data");
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            printf("\nDeleted Data %d ",head->data);
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    return head;
};
struct Node * deleteAtValue(struct Node * head,int value)
{
    struct Node * ptr=head;
    struct Node *temp;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        int True=0;
        do
        {
            if(ptr->data==value)
            {
                True=1;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        ptr=head;
        if(True==1)
        {
            if(ptr->data==value)
            {
                head=deleteAtFrist(head);
            }
            else
            {
                while(ptr->data!=value)
                {
                    temp=ptr;
                    ptr=ptr->next;
                }
                printf("\nDeleted Data %d ",ptr->data);
                temp->next=ptr->next;
                free(ptr);
            }
        }
        else
        {
            printf("\nValue Not Found !");
        }
    }
    return head;
};
struct Node * deleteAtEnd(struct Node * head)
{
    struct Node * ptr=head;
    struct Node * temp;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        if(ptr->next==head)
        {
            head=deleteAtFrist(head);
        }
        else
        {
            while(ptr->next!=head)
            {
                temp=ptr;
                ptr=ptr->next;
            }
            printf("\nDeleted Data %d ",ptr->data);
            temp->next=ptr->next;
            free(ptr);
        }
    }
    return head;
};
struct Node * deleteList(struct Node * head)
{
    struct Node * ptr=head;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        while(ptr->next!=head)
        {
            head=deleteAtEnd(head);
            ptr=ptr->next;
        }
        head=deleteAtEnd(head);
        printf("\nList Is Deleted");
    }
    return head;
};
//Display Program Start
void display(struct Node * head)
{
    struct Node * p=head;
    if(head==NULL)
    {
        printf("\nNo Data");
    }
    else
    {
        do
        {
            printf("\nData %d ",p->data);
            p=p->next;
        }while(p!=head);
    }
}
void main()
{
    int choice;
    struct Node * head=NULL;
    check=0;
    while(1)
    {
        printf("\n1 For Insert At Frist ");
        printf("\n2 For Display ");
        printf("\n3 For Insert At Index Last");
        printf("\n4 For Insert At Index Frist ");
        printf("\n5 For Insert At End ");
        printf("\nDeletion Programs");
        printf("\n6 For Delete At Frist");
        printf("\n7 For Delete At Index ");
        printf("\n8 For Delete At Last ");
        printf("\n9 For Delete List ");
        scanf("%d",&choice);
        if(choice==10)
        {
            break;
        }
        else if(choice==1)
        {
            printf("\nEnter Data ");
            int data;
            scanf("%d",&data);
            if(check==0)
            {
                head=(struct Node *)malloc(sizeof(struct Node));
                head->data=data;
                head->next=head;
                check=1;
            }
            else
            {
                head=insertAtFrist(head,data);
            }
        }
        else if(choice==2)
        {
            display(head);
        }
        else if(choice==3)
        {
            printf("\nEnter Data And Index ");
            int data,index;
            scanf("%d%d",&data,&index);
            head=insertAtIndexLast(head,data,index);
        }
        else if(choice==4)
        {
            printf("\nEnter Data And Index ");
            int data,index;
            scanf("%d%d",&data,&index);
            head=insertAtIndexFrist(head,data,index);
        }
        else if(choice==5)
        {
            printf("\nEnter Data ");
            int data;
            scanf("%d",&data);
            head=insertAtEnd(head,data);
        }
        else if(choice==6)
        {
            head=deleteAtFrist(head);
        }
        else if(choice==7)
        {
            printf("\nEnter Value For Delete ");
            int value;
            scanf("%d",&value);
            head=deleteAtValue(head,value);
        }
        else if(choice==8)
        {
            head=deleteAtEnd(head);
        }
        else if(choice==9)
        {
            head=deleteList(head);
        }
    }
}
