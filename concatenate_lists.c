#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

struct Node *createnode(int data)
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Node *createlist(struct Node *head, int n)
{
    struct Node *newnode=NULL, *temp=NULL;
    
    for(int i=0;i<n;i++)
    {
        int data;
        printf("Enter element %d: ",i+1);
        scanf("%d",&data);
        newnode = createnode(data);
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
    }
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
   
        printf("Linked list is: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
}

struct Node *ConcatenateLists(struct Node *l1, struct Node *l2)
{
    struct Node *temp = l1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = l2;

    return l1;
}

struct Node *reverse(struct Node *head)
{
    struct Node *next=NULL, *prev=NULL, *ptr=head;
    while(ptr!=NULL)
    {
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
    }
    head=prev;
    return head;
}

void Sort(struct Node *head)
{
    int swapped;
    struct Node *ptr;

    if(head==NULL)
    {
        return;
    }
    do
    {
        swapped=0;
        ptr = head; 

        while(ptr->next!=NULL)
        {
            if(ptr->data > ptr->next->data)
            {
                int x = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = x;
                swapped=1;
            }
            ptr=ptr->next;
        }
    }   
    while(swapped);
}

int main()
{
    struct Node *head=NULL;
    int n1, n2;

    printf("Enter number of elements for list 1: ");
    scanf("%d",&n1);
    struct Node *list1 = createlist(head, n1);
    display(list1);

    printf("\nEnter number of elements for list 2: ");
    scanf("%d",&n2);
    struct Node *list2 = createlist(head, n2);
    display(list2);

    struct Node *final = ConcatenateLists(list1, list2);
    printf("\nThe Concatenated ");
    display(final);
    printf("\n");

    final = reverse(final);
    printf("\n");
    printf("Reversed ");
    display(final);
    printf("\n");

    Sort(final);
    printf("\n");
    printf("Sorted ");
    display(final);

    return 0;
}
