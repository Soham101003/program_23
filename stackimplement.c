#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
// creating a structure

struct Stack
{
    int *item;
    int top;
    int capacity;
};

// Initialise the structure variable
void ini(struct Stack *s ,int capacity)
{
    s->capacity=capacity;
    s->top=-1;
    s->item=(int *)malloc(sizeof(int*)*capacity);
}

// checking for full stack
bool isFull(struct Stack * s)
{
    return s->top==s->capacity-1;
}

//checking if stack is empty
bool isEmpty(struct Stack *s)
{
    return s->top==-1;
}

// function to push an element 
void push(struct Stack *s,int item)
{
    if(isFull(s))
    {
        printf("Stack is full...cannot be pushed");
        return;
    }
    s->item[++s->top]=item;
    printf("Pushed %d into the stack \n", item);
}

// function to pop
void pop(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped item is %d\n", s->item[s->top--]);
}
// function to display
void display(struct Stack*s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty");
        return ;
    }
    printf("Stack contents : \n");
    {   for(int i=  s->top; i>=0; i--)
        printf("%d \n", s->item[i]);
    }
}
void cleanUp(struct Stack *s)
{
    free(s->item);
}

// main method 
int main()
{
    int capacity;
    printf("Enter the capacity of the stack");
    scanf("%d", &capacity);

    struct Stack stack ;
    ini(&stack,capacity);

    int choice,item;
    while(1)
    {
        printf("MENU\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT \n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :printf("PUSH\n");
                    printf("Enter item to push : \n");
                    scanf("%d",&item);
                    push(&stack,item);
                     break;

            case 2: printf("POP\n");
                    pop(&stack);
                    break;
            case 3: printf("DISPLAY\n");
                    display(&stack);
                    break;
            case 4: printf("EXIT\n");
                    cleanUp(&stack);
                    printf("Exiting the program....\n");
                    break;
            default:
                    printf("Invalid Input\n");


            
        }


    }
    return 0;
}
