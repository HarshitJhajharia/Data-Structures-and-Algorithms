#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *create(struct Node *head, int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node*));
    if(ptr==NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        ptr->data=item;
        ptr->next=head;
        head=ptr;
    }
return head;
}

void search(struct Node *head)
{
    struct Node *ptr=head;
    int item, i=0, flag=0;
    if(ptr==NULL)
    {
        printf("List is empty\n");
        return;
    }
        printf("Enter element to be searched: ");
        scanf("%d",&item);
        while(ptr!=NULL)
        {
            if(ptr->data==item)
            {
                printf("Element found at location %d\n",i+1);
                flag=0;
            }
            i++;
            ptr = ptr->next;
        }
        if(flag==1)
        {
            printf("Item not found");
        }
}

int main()
{
    struct Node *head=NULL;
    int choice, item;
    do
    {
        printf("\n1.Create \n2.Search \n3.Exit \nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d",&item);
                head=create(head, item);
                break;
            case 2:
                search(head);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\nPlease enter a valid choice\n");
        }      
    }
    while(choice!=3);
    return 0;
}