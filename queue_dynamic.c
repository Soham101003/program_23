#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int *array;
    int front, rear, size;
};

// Function to create a queue 
struct Queue* createQueue(int size)
{
    struct Queue * queue= (struct Queue*)malloc(sizeof(struct Queue));
    if(!queue)
    {
        perror("Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }   
    queue->array=(int *)malloc(sizeof(int)*size);
    if(!queue)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    } // creating a queue and implementing it as an array
    queue->size=size;
    queue->front=queue->rear=-1; // initializing an empty queue 
    return queue; 
}

// function to check if queue is full or not 
int isFull(struct Queue*queue)
{
    return (queue->rear==queue->size-1);
}

// Function to check if the queue is empty or not 
int isEmpty(struct Queue*queue)
{
    return (queue->front==-1);
}

// Function to add elements to the queue 
void Enqueue(struct Queue *queue,int item)
{
        // item refers to the element to be pushed in the queue
        // checking if the queue if full or not 
        if(isFull(queue))
        {
            printf("Queue is full. Cannot insert element \n");          
              return ;

        }
        if(isEmpty(queue))
        {    
            
            queue->front=0; // front=0 means some element is present in the queue
        }
        queue->rear++;    
        queue->array[queue->rear]=item; // pushing the item from the rear side of the array
         printf("%d has been inserted in the queue\n", item);
    
}

// Function to delete elements from the queue
int Dequeue(struct Queue *queue)
{
    // checking if the queue is empty 
    if(isEmpty(queue))
    {
            printf("Queue is empty. Nothing to delete \n");
            return 0 ;
    }
    int item=queue->array[queue->front]; // takes the best available element front the front of the queue
    queue->front++; // moving the pointer to the next location 

    // edge case : if only one element is left 
    if(queue->front>queue->rear)
    {
        queue->front=queue->rear=-1; // resetting the value to -1 which means empty queue
    
    }
    printf("Dequeued element is %d : \n", item);
    return item;
}
// Function to display the existing queue
void display(struct Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty....Nothing to display \n");
        return;
    }
    printf("Queue elements are : ");
    for(int i=queue->front; i<=queue->rear;i++)
    {
        printf("%d " ,  queue->array[i]);
    }
    printf("\n");
}

// main method 
int main()
{
    int choice, item;
    struct Queue *queue=NULL;
    int size;
    printf("Enter size of the queue : \n");
    scanf("%d", &size);
    queue=createQueue(size);
    while(1)
    {
        printf("\n MENU \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display \n");
        printf("4. Exit Function\n");
        printf("Enter your choice 1-4 : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: printf("1. Enqueue Function \n");
                printf("Enter the item to be inserted : \n");
                scanf("%d", &item);
                Enqueue(queue,item);
                break;
        case 2 : printf("2. Dequeue Function \n");
                Dequeue(queue);
                break;
        case 3: printf("3. Display Function \n");
                display(queue);
                break;
        case 4: printf("Exiting......\n");
                 free(queue->array);
                free(queue);
                exit(0);
                break;
        default: printf("Invalid Input\n");
        
        }
    }
    return 0;
}