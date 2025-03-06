#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
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
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void traversallist(struct Node *head) {
    printf("Linked List: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *InsertStart(struct Node *head) {
    int data;
    printf("Enter the data to insert at start: ");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
    }
    return newNode;
}

struct Node *InsertEnd(struct Node *head) {
    int data;
    printf("Enter the data to insert at end: ");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node *InsertAnywhere(struct Node *head, int position) {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    struct Node *newNode = createNode(data);
    if (position == 1 || head == NULL) {
        newNode->next = head;
        return newNode;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *DeleteStart(struct Node *head) {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *DeleteEnd(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node *DeleteAnywhere(struct Node *head, int place) {
    if (head == NULL || place == 1) return DeleteStart(head);
    struct Node *temp = head;
    for (int i = 1; i < place - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        struct Node *toDel = temp->next;
        temp->next = toDel->next;
        free(toDel);
    }
    return head;
}

int main() {
    struct Node *head = NULL;
    int choice, n, position;
    do {
        printf("\nMenu:\n");
        printf("1. Create List\n2. Insert at Start\n3. Insert at End\n4. Insert at Position\n5. Delete from Start\n6. Delete from End\n7. Delete from Position\n8. Display List\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                head = createlist(head, n);
                break;
            case 2:
                head = InsertStart(head);
                break;
            case 3:
                head = InsertEnd(head);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                head = InsertAnywhere(head, position);
                break;
            case 5:
                head = DeleteStart(head);
                break;
            case 6:
                head = DeleteEnd(head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = DeleteAnywhere(head, position);
                break;
            case 8:
                traversallist(head);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 9);
    return 0;
}
