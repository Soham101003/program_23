#include<stdio.h>
#include<stdlib.h>

// structure to define the node characteristics
struct Node 
{   
    int data;
    struct Node * next;/* data */
};

// Function to create a node
struct Node* createNode(int data)
{
    struct Node* newNode= (struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
            printf("Memory allocation failed\n");
            exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;

}

// Function to insert a Node in the front 
void InsertFront(struct Node **head, int data)
{
        // allocate a newNode 
        struct Node * newNode = createNode(data);
        newNode->next=*head;
        *head=newNode;
}
// Function to delete from the end 
void InsertEnd(struct Node **head, int data)
{
    // Allocate a newNode
    struct Node *newNode= createNode(data);
    // If no node exits
    if(*head==NULL)
    {
            *head=newNode;
    }
    else
    {
        struct Node *current=*head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newNode;
    }

}
//  Function to insert at intermediate position 
void insertIntermediate(struct Node **head, int data, int position)
{
    // validating the position 
    if(position<0)
    {
        printf("Invalid position,\n");
        return;

    }
    if(position==0)
    {
        InsertFront(head,data);
        return;
    }
    struct Node * newNode=createNode(data);
    struct Node * current = *head;
    for(int i=0;i<position-1;i++)
    {
            if(current==NULL)
            {
                    printf("Position out of order.\n");
                    return;
            }
            current=current->next;
    }
    if(current==NULL)
    {
        printf("Position out of order\n");
        
    }
    else
    {
        newNode->next=current->next;
        current->next=newNode;
    }
    }

// Function to delete from the front
void deleteFront(struct Node **head)
{
    if(*head==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    struct Node * temp=*head; // copying the head value
    *head=(*head)->next;
    free(temp); // freeing the space allocated for the copy
}

// Function to Delete from end 
void deleteEnd(struct Node **head)
{
    if(*head==NULL)
    {
        printf("Linked List is empty nothing to delete\n");
        return;
    }
    // Only if one node is present after the first node 
    if((*head)->next == NULL)
    {
        free(*head);
        *head=NULL;
        return;  // 1->2->NULL
        // (head)1->NULL // NULL 
    }
    struct Node * current=*head;
    struct Node * prev= NULL;
    while(current->next!=NULL)
    {
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    free(current);
}

// Function to delete element from an intermediate position 
void deleteIntermediate(struct Node **head, int position)
{
    if(*head==NULL)
    {
        printf("Linked List is empty.\n");
        return ;

    }
    if(position== 0)
    {
        deleteFront(head);

    }
    if(position<0)
    {
        printf("Invalid Position.\n");
        return ;
    }
    struct Node *current=*head;
    struct Node *prev=NULL;
    int count=0;
    while (current->next!=NULL)
    {
        prev=current;
        current=current->next;
        count ++; // traversing the pointers and updating it
    }
    if(current==NULL)
    {
        printf("OUT OF ORDER.\n");
        return;
    }
    prev->next=current->next;
    free(current);

}

// Function to display the linked List 
void DisplayList(struct Node *head)
{
    struct Node * current = head;
    while(current != NULL) // element is present 
    {
        printf("%d->", current->data);
        current=current->next;

    }
printf("NULL\n");
} // output 1->2->3->NULL
// Function to free the allocated memory 
void FreeList(struct Node *head)
{
    struct Node *current=head;
    while(current!=NULL)
    {
        struct Node * temp=current; // copy variable 
        current=current->next;
        free(temp);
    }
}
int main()
{
    struct Node *head= NULL;
    int choice, data, position;
    while (1)
    {
        printf(" .........MENU OF SINGLY LINKED LIST .........\n");
        printf("1. Display \n");
        printf("2. Insert Front\n");
        printf("3. Insert End \n");
        printf("4. Insert Intermediate\n");
        printf("5. Delete Front\n");
        printf("6. Delete End .\n");
        printf("7. Delete Intermediate");
        printf("8. .....Exit.....\n");
        printf("Enter your choice 1-8\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: DisplayList(head);
                    break;
            case 2:
                    printf("Enter the data to insert\n");
                    scanf("%d", &data);
                    InsertFront(&head,data);
                    break;
            case 3: printf("Enter element to insert\n");
                    scanf("%d", &data);
                    InsertEnd(&head,data);
                    break;
            case 4: printf("Enter element to insert\n");
                    scanf("%d", &data);
                    printf("Enter position to insert\n");
                    scanf("%d", &position);
                    insertIntermediate(&head,data,position);
                    break;
            case 5: deleteFront(&head);
                    break;
            case 6: deleteEnd(&head);
                    break;
            case 7 : printf("Enter the position you want to delete from\n");
                    scanf("%d",&position);
                    deleteIntermediate(&head,position);
                    break;
            case 8 : printf("......Exiting the function......\n");
                    exit(0);
                    break;
            default:printf("Invalid Input\n");
                    
        }
    }

    return 0;

}

