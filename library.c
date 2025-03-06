#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node 
{
    struct Node *next;
    char title[30];
    char author[30];
    char publisher[30];
    int isbn;
};

struct Node *createnode()
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    printf("Enter title of book: ");
    scanf("%s",&newnode->title);
    printf("Enter name of author: ");
    scanf("%s",&newnode->author);
    printf("Enter name of publisher: ");
    scanf("%s",&newnode->publisher);
    printf("Enter ISBN of book: ");
    scanf("%d",&newnode->isbn);

    newnode->next=NULL;
    return newnode;
}

struct Node *add(struct Node *head)
{
    struct Node *newnode = createnode();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    struct Node *temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

void search(struct Node *head)
{
    struct Node *ptr=head;
    int item, i=0, flag=0;
    if(ptr==NULL)
    {
        printf("No Books found");
        return;
    }
    printf("Enter ISBN of book to be searched: ");
    scanf("%d",&item);
    while(ptr!=NULL)
        {
            if(ptr->isbn == item)
            {
                printf("Book found, Book title: %s",ptr->title);
                flag=0;
            }
            i++;
            ptr=ptr->next;
            if(flag==1)
            {
                printf("Book not found");
            }
        }
}

void display(struct Node *head)
{
    printf("Books are:");
    struct Node *temp = head;
    while(temp!=NULL)
    {
        printf("%s ",temp->title);
        temp=temp->next;
    }
}

struct Node *delete(struct Node *head, int place)
{
    struct Node *todel = head, *temp = head;
    for(int i=1 ; i<=place ; i++)
    {
        temp=todel;
        todel=todel->next;
    }
    temp->next=todel->next;
    free(todel);

    return head;
}

int main()
{
    struct Node *head;
    int ch, place;

    while(1)
    {
        printf("\n1.Add a book\n2.Search for a book by ISBN\n3.Delete a book\n4.Display Books\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            head = add(head);
            printf("Book added");
            break;
            case 2:
            search(head);
            break;
            case 3:
            display(head);
            printf("\nEnter position of book to be deleted: ");
            scanf("%d",&place);
            delete(head, place);
            break;
            case 4:
            display(head);
            break;
            case 5:
            exit(0);
            printf("\nExiting...");
            break;
            default:
            printf("Enter valid choice");
        }

    }
    return 0;
}