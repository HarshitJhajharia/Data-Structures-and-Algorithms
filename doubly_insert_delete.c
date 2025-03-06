#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createnode(int data) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

struct Node *createlist(int n) {
    struct Node *head = NULL, *tail = NULL;
    int data;
    
    for (int i = 1; i <= n; i++) {
        printf("Enter data for element %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = createnode(data);
        
        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

void displaylist(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *InsertStart(struct Node *head, int value) {
    struct Node *newnode = createnode(value);
    if (head != NULL) {
        newnode->next = head;
        head->prev = newnode;
    }
    return newnode;
}

struct Node *InsertEnd(struct Node *head, int num) {
    struct Node *newnode = createnode(num);
    if (head == NULL) return newnode;
    
    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct Node *InsertAnywhere(struct Node *head, int x, int position) {
    if (position == 1) return InsertStart(head, x);
    
    struct Node *newnode = createnode(x);
    struct Node *temp = head;
    
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;
    
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    
    return head;
}

struct Node *deletestart(struct Node *head) {
    if (head == NULL) return NULL;
    struct Node *todel = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(todel);
    return head;
}

struct Node *deleteend(struct Node *head) {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else head = NULL;
    free(temp);
    return head;
}

struct Node *deleteanywhere(struct Node *head, int place) {
    if (place == 1) return deletestart(head);
    
    struct Node *temp = head;
    for (int i = 1; i < place && temp != NULL; i++)
        temp = temp->next;
    
    if (temp == NULL) return head;
    
    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

int main() {
    struct Node *head = NULL;
    int choice, n, value, position;
    
    do {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Start\n");
        printf("4. Insert at End\n");
        printf("5. Insert at any Position\n");
        printf("6. Delete from Start\n");
        printf("7. Delete from End\n");
        printf("8. Delete from any Position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                head = createlist(n);
                break;
            case 2:
                displaylist(head);
                break;
            case 3:
                printf("Enter element to be added at start: ");
                scanf("%d", &value);
                head = InsertStart(head, value);
                break;
            case 4:
                printf("Enter element to be added at end: ");
                scanf("%d", &value);
                head = InsertEnd(head, value);
                break;
            case 5:
                printf("Enter position for element to be entered: ");
                scanf("%d", &position);
                printf("Enter element to be added: ");
                scanf("%d", &value);
                head = InsertAnywhere(head, value, position);
                break;
            case 6:
                head = deletestart(head);
                break;
            case 7:
                head = deleteend(head);
                break;
            case 8:
                printf("Enter position of element to be deleted: ");
                scanf("%d", &position);
                head = deleteanywhere(head, position);
                break;
            case 9:
            printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);
    
    return 0;
}
