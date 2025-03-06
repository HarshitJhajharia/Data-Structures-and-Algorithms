#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *createlist(struct Node *head, int n) {
    struct Node *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element: ");
        scanf("%d", &data);

        newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } 
        else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}


// Function to find the n/2 th element using slow and fast pointers
void findMiddle(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("The n/2th element is: %d\n", slow->data);
}


void traversallist(struct Node *head) {
    printf("Linked List: ");
    struct Node *temp = head;

    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Node *head = NULL;
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    head = createlist(head, n);
    traversallist(head);

    findMiddle(head);

    return 0;
}