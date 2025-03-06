#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *Create(struct Node *head, int n) {
    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter value for position %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            struct Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    return head;
}

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

struct Node *insertAtBeginning(struct Node *head) {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct Node *insertAtEnd(struct Node *head) {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

struct Node *deleteFromBeginning(struct Node *head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == head) {
        free(head);
        return NULL;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        struct Node *toDelete = head;
        head = head->next;
        free(toDelete);
    }
    return head;
}

struct Node *deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == head) {
        free(head);
        return NULL;
    } else {
        struct Node *secondLast = head;
        while (secondLast->next->next != head) {
            secondLast = secondLast->next;
        }
        struct Node *last = secondLast->next;
        secondLast->next = head;
        free(last);
    }
    return head;
}

int main() {
    struct Node *head = NULL;
    int choice, n, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                head = Create(head, n);
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                head = insertAtBeginning(head);
                break;
            case 4:
                head = insertAtEnd(head);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                head = deleteFromEnd(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
