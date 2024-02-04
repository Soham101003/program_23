#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(Node** head, int data, int position) {
    if (position == 0 || *head == NULL) {
        insertFront(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteFront(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        deleteFront(head);
        return;
    }
    Node* current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Display List\n");
        printf("2. Insert at Front\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Front\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 4:
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                deleteFront(&head);
                break;
            case 6:
                deleteEnd(&head);
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
