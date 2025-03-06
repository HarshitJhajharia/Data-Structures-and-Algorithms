#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList() {
    struct Node* head = NULL, * temp = NULL;
    int n, data;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    if (n <= 0) return NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* reverseRecursively(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* newHead = reverseRecursively(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

struct Node* reversalList(struct Node* head) {
    struct Node *prev = NULL, *ptr = head, *next = NULL;
    while (ptr != NULL) {
        next = ptr->next;  
        ptr->next = prev;  
        prev = ptr;        
        ptr = next;
    }
    return prev; 
}

int main() {
    struct Node* head = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Reverse List (Recursively)\n");
        printf("4. Reverse List (Iteratively)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = reverseRecursively(head);
                printf("List reversed recursively.\n");
                break;
            case 4:
                head = reversalList(head);
                printf("List reversed iteratively.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
