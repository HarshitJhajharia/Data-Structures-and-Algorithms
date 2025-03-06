#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *head, *tail;


struct node *CreateNode(int data)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	if(n==NULL)
	{
		printf("memory not allocated");
		return NULL;
	}
	else 
	{
		n->data=data;
		n->next=NULL;
		n->prev=NULL;
	return n;
	}
}

struct node *createList(long num)
{
	for(int j=1; j<=10; j++)
	{
		int i=num%10;
		struct node *newNode=CreateNode(i);
		num=num/10;
		if(head==NULL)
		{
			head=newNode;
		}
		else
		{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}
	}
return head;
}


void DisplayList() {
    struct node *temp=head;
    if (head == NULL) 
    {
        printf("List empty.");
    } 
    else 
    {
        printf("The list is: ");
        while (temp != NULL) 
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


void palindrome(long num)
{
    long reversed = 0, remainder, original=num;

    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder; 
        num=num/10;
    }

    if (original == reversed)
        printf("%ld is a palindrome.", original);
    else
        printf("%ld is not a palindrome.", original);
}


int main()
{
	long num;
	printf("enter a 10 digit number: ");
	scanf("%ld",&num);
	
	head=createList(num);
	DisplayList();
	
	printf("\n");
	
		palindrome(num);
return 0;
}
	