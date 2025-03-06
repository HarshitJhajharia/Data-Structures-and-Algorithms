#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(struct Node* head, int n) {
    struct Node* temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element: ");
        scanf("%d", &data);

        newNode = createNode(data);

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

void printList(struct Node* head) {
    printf("Linked List: ");
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* partition(struct Node* head, int x) {
    struct Node *lessHead = NULL, *lessTail = NULL;
    struct Node *greaterHead = NULL, *greaterTail = NULL;
    struct Node *current = head;

    while (current) {
        struct Node* next = current->next;
        current->next = NULL;

        if (current->data < x) {
            if (!lessHead) {
                lessHead = lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else {
            if (!greaterHead) {
                greaterHead = greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = next;
    }

    if (!lessHead) return greaterHead;

    lessTail->next = greaterHead;
    return lessHead;
}

int main() {
    struct Node* head = NULL;
    int choice, x, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Print List\n");
        printf("3. Partition List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                head = createList(head, n);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                if (head == NULL) {
                    printf("List is empty, create a list first.\n");
                    break;
                }
                printf("Enter partition value: ");
                scanf("%d", &x);
                head = partition(head, x);
                printf("Partitioned List:\n");
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
