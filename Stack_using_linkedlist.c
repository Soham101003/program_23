#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Initialize the stack with a pointer to the top of the stack
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1; // Return a sentinel value to indicate an empty stack
    }
    int poppedValue = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return poppedValue;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to display the elements of the stack
void display() {
    struct Node* current = top;
    if (current == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
