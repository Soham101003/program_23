#include<stdio.h>
#include <stdlib.h>

// define a structure for a queue
struct Queue
{
    int *items;
    int front;
    int rear;
    int maxSize;

};

// function to initialise a structure
void initQueue(struct Queue *q, int maxSize)
{
    q->items=(int*)malloc(sizeof(int)*maxSize);
    q->front=q->rear=-1;
    q->maxSize=maxSize;
}

//checks for an empty queue
int isEmpty(struct Queue *q)
{
    return (q->front==-1 && q->rear==-1);
}
// checks if the queue is full or not 

int isFull(struct Queue * q)
{
    return (q->rear==q->maxSize-1);
}

// Function to add elements to the queue 
void enqueue(struct Queue * q,int value)
{
    if(isFull(q))
    {
        printf("Queue is full. Cannot insert.\n");
        
    }
    else
    {
        if(q->front==-1)
        {
            q->front=0; // front =0 means element is present 
        }
        q->rear++;
        q->items[q->rear]=value; // shifting the rear val to right and allocating an item
    }
}
// Function to delete an element 
int dequeue(struct Queue*q)
{   int item;
    if(isEmpty(q))
    {
        printf("Queue is Empty.Nothing to delete\n");
        return -1;
    }
    else
    {
        item=q->items[q->front]; // storing the front element in a variable 
        q->front++; // incrementing the front value leaves the previous value unattended
        if(q->front>q->rear) // edge case: if one element is present 
        {
            q->front=q->rear=-1;

        } 

    }
    return item;
 } // Queue construction has ended 
 
 // structure replicating a stack 
  struct StackUsingQueue
  {
    struct Queue q1;
    struct Queue q2;

  };

// Initialize an empty stack 
void initStack(struct StackUsingQueue * stack, int maxsize)
{
    initQueue(&stack->q1,maxsize);
    initQueue(&stack->q2, maxsize);
}
// push an element into the  stack 
void push (struct StackUsingQueue * stack, int value)
{
    enqueue(&stack->q1,value);
}

// Pop an element from the stack 
int pop(struct StackUsingQueue * stack)
{ 
    int item;
    if(isEmpty(&stack->q1))
    {
        printf("Stack is empty. Nothing to pop.\n");
        return -1;
    }
    // transfering from q1 to q2 
    while(!isEmpty(&stack->q1))
    {
        item=dequeue(&stack->q1);
        if(!isEmpty(&stack->q1))
        {
            enqueue(&stack->q2,item);
        }
    }
    // swapping the elements 
    struct Queue temp =stack->q1;
    stack->q1=stack->q2;
    stack->q2=temp;
    return item;

}

// Display the top placed items on the stack 
int top(struct StackUsingQueue * stack)
{
    int item;
    if(isEmpty(&stack->q1))
    {
        printf("Stack is empty, no top item is present\n");
        return -1 ;
    }
    // transfer elements from q1 to q2 
    while(!isEmpty(&stack->q1))
    {
        item=dequeue(&stack->q1);
        if(!isEmpty(&stack->q1))
        {
            enqueue(&stack->q2,item);
        }
    }
    // swapping the elements 
    struct Queue temp =stack->q1;
    stack->q1=stack->q2;
    stack->q2=temp;
    return item;
}
// check for empty stack 
int isStackEmpty(struct StackUsingQueue * stack)
{
    return isEmpty(&stack->q1);
}
// cleanup memory allocated 
void cleanUpQueue(struct Queue *q )
{
    free(q->items);
    q->front=-1;
    q->rear=-1;
    q->maxSize=0;
}
// main function 
int main()
{
    int maxSize;
    printf("Enter the maximun Size: \n");
    scanf("%d", &maxSize);
    struct StackUsingQueue stack;
    initStack(&stack,maxSize);
    int choice, value;
    while(1)
    {
        printf("\n Stack Using Queue menu\n");
        printf("1. Push Operation \n");
        printf("2. Pop operation\n");
        printf("3.Get the top element  \n");
        printf("4.Is Empty \n");
        printf("5.Quit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : // push a value 
                    if(stack.q1.maxSize==stack.q1.rear+1)
                    {
                        printf("Stack is Full cannot push elements\n");

                    }
                    else
                    {
                        printf("Enter the element to be pushed : \n");
                        scanf("%d", &value);
                        push(&stack,value);
                        printf("Pushed %d into the stack \n", value);

                    }
                    break;
            case 2 : // pops a value 
                    value=pop(&stack);
                    if(value!=-1)
                    {
                        printf("Poppped %d from the stack. \n", value);

                    }
                    break;
            case 3 : // Shows the top value 
                    value=top(&stack);
                     if(value!=-1)
                    {
                        printf("Top value is %d from the stack. \n", value);

                    }    
                    break;
            case 4: if(isStackEmpty(&stack))
                    {
                            printf("Stack is empty.\n");
                    }   
                    else
                    {
                        printf("Stack is not empty.\n");
                    }
                    break;
            case 5: cleanUpQueue(&stack.q1);
                    cleanUpQueue(&stack.q2);
                    printf("Exiting Menu ...........\n");
                    exit(0);
            default: printf("Invalid Input ");

         }

    }
    return 0;
}