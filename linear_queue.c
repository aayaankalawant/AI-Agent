#include<stdio.h>
#define size 5

struct queue
{
    int arr[size];
    int front;
    int rear;
};
//------------------------------------------------------
void init(struct queue *A)
{
    A->front = -1;
    A->rear = -1;
}
//---------------------------------------------------
int queue_full(struct queue *A)
{
    if(A->rear == (size-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//------------------------------------------------------
int queue_empty(struct queue *A)
{
    if(A->rear == -1 || A->front == -1 || A->front > A->rear)   // ? Added condition A->front > A->rear
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//---------------------------------------------------------------
void enqueue(struct queue *A,int data)
{
    if(queue_full(A))
    {
        printf("Queue is full...\n");
        return;
    }
    else
    {
        if(A->front == -1)   // ? Removed redundant check for rear, only front matters
        {
            A->front = 0;    // ? Changed from A->front++ to proper initialization
        }
        A->rear++;
        A->arr[A->rear] = data;
        printf("Data added successfully...\n");
        printf("front = %d\nRear = %d\n",A->front,A->rear);
    }
}
//---------------------------------------------------------------------
void dequeue(struct queue *A)
{
    if(queue_empty(A))
    {
        printf("Queue is empty...\n");
        return;
    }
    else
    {
        int temp = A->arr[A->front];
        printf("deleted element: %d\n",temp);   // ? Added newline for clarity
        A->front++;
        if(A->front > A->rear)   // ? Moved inside same block, removed extra else
        {
            A->front = -1;
            A->rear = -1;
            printf("Queue is now Empty...\n");
        }
    }
}
//--------------------------------------------------------------------
void peek(struct queue *A)
{
    if(queue_empty(A))
    {
        printf("Queue is empty...\n");
        return;
    }
    else
    {
        printf("Peek element : %d\n",A->arr[A->front]);
        return;
    }
}
//----------------------------------------------------------------------
void display_queue(struct queue *A)
{
    if(queue_empty(A))
    {
        printf("Queue is empty...\n");
        return;
    }
    else
    {
        printf("The Queue elements are:\n");
        int i = A->front;   // ? Declared i properly
        while(i <= A->rear) // ? Corrected condition (was i > rear)
        {
            printf("%d->",A->arr[i]);
            i++;
        }
        printf("NULL\n");   // ? Added NULL for proper queue end
    }
}
//----------------------------------------------------------------------
int main()
{
    int ch,data;
    struct queue q1;
    init(&q1);
    
    do
    {
        printf("0.exit\n1.Enqueue\n2.Dequeue\n3.peek\n4.display\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 0:
                {
                    printf("Thank you for using...\n");
                    return 0;
                }
            case 1:
                {
                    printf("Enter data:");
                    scanf("%d",&data);
                    enqueue(&q1,data);
                    break;
                }
            case 2:
                {
                    dequeue(&q1);
                    break;
                }
            case 3:
                {
                    peek(&q1);
                    break;
                }
            case 4:
                {
                    display_queue(&q1);
                    break;
                }
            default:
                {
                    printf("Invalid choice...\n");
                    break;
                }
        }
    }while(ch != 0);   // ? Added missing semicolon
    return 0;
}

