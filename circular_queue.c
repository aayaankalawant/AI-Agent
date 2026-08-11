#include<stdio.h>

#define size 5
struct cir_queue
{
	int arr[size];
	int front;
	int rear;
};
void init(struct cir_queue *A)
{
	int A->front = -1;
	int A->rear = -1;
}
int queue_full(struct cir_queue *A)
{
	if(A->rear == (size - 1) && A->front == 0 || A->front == (A->rear + 1))
	{
		return 1;
	}
	else
	{
		return 0;;
	}
}
int queue_empty(struct cir_queue *A)
{
	if(A->front == -1 && A->rear == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(struct cir_queue *A,int data)
{
	if(queue_full(A))
	{
		printf("Queue is full...");
		return;	
	}
	else
	{
		if(A->front == -1)
		{
			A->front = 0;
		}
		else
		{
			A->rear = (A->rear + 1)%size;
			A->arr[A->rear] = data;
			printf("front = %d\rear = %d",A->front,A->rear);
		}
	}
}
void  dequeue(struct cir_queue *A)
{
	if(queue_empty(A))
	{
		printf("Queue is empty...\n");\
		return;
	}
	else
	{
		if(A->front == A->rear)
		{
			A->front = -1;
			A->rear = -1;
		}
		else
		{
			int temp = A->arr[A->rear];
			printf("Deleted element : %d",temp);
			A->front = (A->front + 1)%size;
			printf("front = %d\nrear = %d",A->front,A->rear);
		}
	}
}
void peek(struct cir_queue *A)
{
	if(queue_empty(A))
	{
		printf("Queue is empty...\n");
		return;
	}
	else
	{
		printf("Peek element:%d",A->arr[A->front]);
		return;
	}
}
void display_queue(struct cir_queue *A)
{
	if(queue_empty(A))
	{
		printf("queue is empty...\n");
		return;
	}
	else
	{
		while (1)
		{
			int i = 0;
			print("%d->",A->arr[A->front]);
			if(i == A->rear)
			{
				break;
			}
			i = (i + 1) % size;
		}
	}
}
int main()
