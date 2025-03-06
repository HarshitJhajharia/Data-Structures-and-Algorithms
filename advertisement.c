#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    struct Node *next;
    struct Node *prev;
    char ad[30];
};

struct Node *createnode()
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    printf("Enter your advertisement: ");
    scanf("%s",newnode->ad);

    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

struct Node *add(struct Node *head)
{
    struct Node *newnode;
    newnode = createnode();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    struct Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

struct Node *delete(struct Node *head) 
{
    struct Node *ptr=head, *temp=head;
    if (head == NULL) {
        printf("List is empty\n");
    }
    else
    {
        temp=ptr;
        ptr=ptr->next;
    
        while(ptr->next != NULL)
        {
            temp->next=NULL;
            ptr->prev=NULL;
            free(ptr);
        }
    }    
    return head;
}

void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct Node *temp=head;
        struct Node *last=head;
        int ch;
        while(1)
        {
        printf("\n0.Current advertisement\n1.Next advertisement\n2.Previous advertisement\n3.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
            printf("%s",temp->ad);
            break;
            case 1:
            if(temp->next==NULL)
            {
                temp=head;
                printf("%s",temp->ad);
            }
            else
            {
                temp=temp->next;
                printf("%s",temp->ad);
            }
            break;
            case 2:
            if(temp->prev==NULL)
            {
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                } 
            }
            else
            {
                temp=temp->prev;
            }
            printf("%s",temp->ad);
            break;
            case 3:
            return;
        }
        }
    }
}

int main()
{
    struct Node *head=NULL, *tail=NULL;
    int ch, position;
    while(1)
    {
        printf("\n1.Add\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            head = add(head);
            printf("\nAdvertisement added");
            break;
            case 2:
            delete(head);
            printf("\nAdvertisement deleted");
            break;
            case 3:
            display(head);
            break;
            case 4: 
            exit(0);
            default :
            printf("\nEnter a valid choice");
        }
    }
    return 0;
}
