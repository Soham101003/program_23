#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Circular reference to itself
        *head = newNode;
    } else {
        struct Node* tail = (*head)->next;
        while (tail->next != *head) {
            tail = tail->next;
        }
        newNode->next = *head;
        tail->next = newNode;
        *head = newNode;
    }
    printf("Element %d inserted at the front.\n", data);
}

// Function to insert a node at an intermediate position
void insertIntermediate(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position for insertion.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Circular reference to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        int i = 1;
        while (i < position - 1 && temp->next != *head) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Element %d inserted at position %d.\n", data, position);
    }
}

// Function to delete a node from a given position
void deleteElement(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position for deletion.\n");
        return;
    }
    if (position == 1) {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        if (temp == *head) {
            *head = NULL;
        } else {
            temp->next = (*head)->next;
            free(*head);
            *head = temp->next;
        }
        printf("Element at position 1 deleted.\n");
    } else {
        struct Node* temp = *head;
        int i = 1;
        while (i < position - 1 && temp->next != *head) {
            temp = temp->next;
            i++;
        }
        if (temp->next == *head) {
            printf("Position %d is out of bounds.\n", position);
        } else {
            struct Node* toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            printf("Element at position %d deleted.\n", position);
        }
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to the beginning)\n");
}

int main() {
    struct Node* head = NULL; // Initialize the head of the circular linked list to NULL
    int choice, data, position;

    do {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Intermediate Position\n");
        printf("3. Delete Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position for insertion: ");
                scanf("%d", &position);
                insertIntermediate(&head, data, position);
                break;
            case 3:
                printf("Enter the position for deletion: ");
                scanf("%d", &position);
                deleteElement(&head, position);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory before exiting
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
