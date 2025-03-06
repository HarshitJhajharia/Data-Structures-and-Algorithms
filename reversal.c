#include<stdio.h>
#include<stdlib.h>

struct Node 
{
  int data;
  struct Node *next;
};

struct Node *createnode(int data)
{
  struct Node *newnode = (struct Node*)malloc(sizeof(struct Node*));
  if (newnode==NULL)
  {
    printf("Memory allocation failed");
    return NULL;
  }
  else 
  {
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
  }
}

struct Node *createlist(struct Node *head, int n)
{
  struct Node *temp=NULL, *newnode=NULL;

  for(int i=0;i<n;i++)
  {
    int data;
    printf("Enter data:");
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

void traversallist(struct Node *head)
{
  printf("Linked list is: ");
  struct Node *temp=head;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

struct Node *reverse(struct Node *head)
{
    struct Node *prev=NULL, *next=NULL, *ptr=head;
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

int main()
{
  struct Node *head = NULL;
  int n;
  printf("Enter number of elements:");
  scanf("%d",&n);

  head=createlist(head, n);
  traversallist(head);

  printf("Reversed list:\n");
  head=reverse(head);
  traversallist(head);
}