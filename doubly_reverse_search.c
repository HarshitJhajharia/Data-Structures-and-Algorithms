#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *next;
    struct Node *prev;
    int data;
};

struct Node *createnode(int data)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("memory not allocated");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

struct Node *createlist(struct Node *head, int n)
{
    head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *tail;
    if(head==NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    int data;
    printf("Enter data for node 1: ");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    head->prev=NULL;
    tail = head;

    for(int i=2;i<=n;i++)
    {
        struct Node *p = (struct Node*)malloc(sizeof(struct Node));
        if (p!=NULL)
        {
            printf("Enter data for node %d: ",i);
            scanf("%d",&data);
            p->data=data;
            p->next=NULL;
            p->prev=tail;
            tail->next=p;
            tail=p;
        }
        else
        {
            printf("Memory cannot be allocated");
            break;
        }
    }
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Linked list is: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void search(struct Node *head)
{
    int item, flag=0;
    struct Node *ptr = head;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    int i=0;
    printf("\nEnter data you want to search: ");
    scanf("%d",&item);
    while(ptr!=NULL)
    {
        if(ptr->data == item)
        {
        printf("Element found at location %d",i+1);
        flag=1;
        }
        i++;
        ptr=ptr->next;
    }
    if(flag==0)
    {
        printf("Element not found");
    }
}

int check(int n)
{
    if(n%2 == 0)
    {
        return 1;
    }
    return 0;
}

void EvenOdd(struct Node *head)
{
    int even=0, odd=0, a;
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
         a=check(ptr->data);
         if(a == 1)
         {   
             even=even+ptr->data;
         }
         else
         {
             odd=odd+ptr->data;
         }
         ptr=ptr->next;
    }   
    printf("\nSum of even numbers: %d",even);
    printf("\nSum of odd numbers: %d",odd);
}

struct Node *reverse(struct Node *head)
{
    struct Node *temp=NULL, *ptr;
    ptr = head;
    
    while(ptr!=NULL)
    {
        temp=ptr->prev;
        ptr->prev=ptr->next;
        ptr->next=temp;
        ptr=ptr->prev;
    }
    if(temp!=NULL)
    {
        head=temp->prev;
    }
    return head;
}

int main()
{   
    struct Node *head, *tail;
    int n;

    while(1)
    {
        int ch;
        printf("\n1.Add an element\n2.Search for a element\n3.Sum of even and odd\n4.Reverse the list\n5.Display\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter number of elements: ");
            scanf("%d",&n);
            head = createlist(head, n);
            break;
            case 2:
            search(head);
            break;
            case 3:
            EvenOdd(head);
            break;
            case 4:
            head = reverse(head);
            printf("Reversed ");
            display(head);
            break;
            case 5:
            display(head);
            break;
            case 6:
            exit(0);
            default :
            printf("Enter a valid choice");
        }
    }

    return 0;
}