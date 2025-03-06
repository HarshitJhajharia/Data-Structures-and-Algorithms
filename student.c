#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    struct Node *next;
    char name[30];
    char dept[10];
    int year[10];
    int roll[10];
};

struct Node *createnode()
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory not allocated");
    }
    printf("Enter name of student: ");
    scanf("%s",&newnode->name);
    printf("Enter department of student: ");
    scanf("%s",&newnode->dept);
    printf("Enter year of admission: ");
    scanf("%d",&newnode->year);
    printf("Enter roll number of student: ");
    scanf("%d",&newnode->roll);

    newnode->next = NULL;
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

void ListStudentsinCSE(struct Node *head)
{
    struct Node *temp = head;
    int flag=1;
    while(temp!=NULL)
    {
        if(strcmp(temp->dept, "CSE") == 0)
        {
            printf("%s\n",temp->name);
            flag=0;
        }
    }
}