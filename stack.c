#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int capacity;
    int size;
} stacker;

// function to initialise all values
struct Stack* createstack(int capacity) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    stack->capacity = capacity;
    stack->size = 0;
    stack->data = (int*)malloc(capacity * sizeof(int)); // dynamically allocating memory for stack
    if (!stack->data) {
        printf("Memory allocation failed.\n");
        free(stack);
        exit(1);
    }
    
    return stack;
}

// to check if the stack is empty
int isempty(struct Stack* stack) {
    return stack->size == 0;
}

// to check if the stack is full or not 
int isfull(struct Stack* stack) {
    return stack->size == stack->capacity;
}

// to push an element into the stack
void push(struct Stack* stack, int item) {
    if (isfull(stack)) {
        printf("Stack is already full...could not enter %d\n", item);
        return;
    }
    stack->data[stack->size++] = item;
}

// to pop an element from the stack
int pop(struct Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty....nothing in there\n");
        return -1;
    }
    return stack->data[--stack->size];
}

int top(struct Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty. No top element.\n");
        return -1;
    }
    return stack->data[stack->size - 1];
}

// frees the allocated space
void destroystack(struct Stack* stack) {
    free(stack->data);
    free(stack);
}

// main method
int main() {
    int stacksize;
    printf("Enter the size of the elements: ");
    scanf("%d", &stacksize);

    // creating a stack by taking user inputs
    struct Stack* stack = createstack(stacksize);

    int numElements;
    printf("Enter the number of elements to push: ");
    scanf("%d", &numElements);

    printf("Entering %d elements in the stack\n", numElements);
    for (int i = 0; i < numElements; i++) {
        int elements;
        scanf("%d", &elements);
        push(stack, elements); // calling the push function
    }

    printf("Top element: %d\n", top(stack));
    printf("Popped elements: ");
    while (!isempty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    destroystack(stack);
    return 0;
}
