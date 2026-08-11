#include<stdio.h>
#define size 5

struct stack
{
    int arr[size];
    int top;
};

//--------------------------------
int stack_full(struct stack *A)
{
    if (A->top == (size - 1))
    {
        return 1;   
    }
    else
    {
        return 0;
    }
}
//-----------------------------------------
void init(struct stack *A)
{
    A->top = -1;   // ? correction
}

int stack_empty(struct stack *A)
{
    if (A->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//------------------------------------------------------------
void display(struct stack *A)
{
    if (stack_empty(A))
    {
        printf("Stack is empty...\n");
        return;
    }
    else
    {
        int i;
        printf("Stack elements:\n");
        for (i = A->top; i >= 0; i--)
        {
            printf("%d->", A->arr[i]);
        }
        printf("\nDisplay stack from top to bottom\n"); // ? correction
    }
}
//--------------------------------------------------------------
int binary_search(struct stack *A, int key, int left, int right)
{
    if (stack_empty(A))
    {
        printf("Stack is empty...\n");
        return -1;
    }
    else
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (A->arr[mid] == key)
            {
                printf("Element found at index %d\n", mid);
                return mid;
            }
            else if (A->arr[mid] > key)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        printf("Element not found...\n");
        return -1;
    }
}
//--------------------------------------------------------------------
int linear_search(struct stack *A, int key)
{
    if (stack_empty(A))   // ? correction
    {
        printf("Stack is Empty...\n");
        return -1;
    }
    else
    {
        int i;
        for (i = 0; i <= A->top; i++)
        {
            if (A->arr[i] == key)
            {
                printf("Element Found at index %d\n", i);
                return i;   
            }   
        }
        printf("Such Element not found...\n");
        return -1;
    }
}
//--------------------------------------------------------------------
void bubble_sort(struct stack *A)
{
    if (stack_empty(A))
    {
        printf("Stack is empty...\n");
        return;
    }
    else
    {
        int i, j;
        for (i = 0; i <= A->top; i++)
        {
            for (j = 0; j < (A->top - i); j++)
            {
                if (A->arr[j] > A->arr[j+1])
                {
                    int temp = A->arr[j];
                    A->arr[j] = A->arr[j+1];
                    A->arr[j+1] = temp;
                }
            }
        }
        printf("Stack sorted using Bubble sort...\n");
    }
}
//--------------------------------------------------------------------
void selection_sort(struct stack *A)
{
    if (stack_empty(A))   // ? correction
    {
        printf("Stack is Empty...\n");
        return;
    }
    else
    {
        int i, j, min, temp;
        for (i = 0; i < A->top; i++)
        {
            min = i;
            for (j = i+1; j <= A->top; j++)
            {
                if (A->arr[j] < A->arr[min])   // ? correction
                {
                    min = j;
                }
            }
            temp = A->arr[i];
            A->arr[i] = A->arr[min];
            A->arr[min] = temp;
        }
        printf("Stack sorted successfully using selection sort...\n");
    }
}
//-------------------------------------------------------------------------------
void insertion_sort(struct stack *A)
{
    int key, i, j;
    if (stack_empty(A))
    {
        printf("Stack is Empty...\n");
        return;
    }
    else
    {
        for (i = 1; i <= A->top; i++)   // ? correction
        {
            key = A->arr[i];
            j = i - 1;
            while (j >= 0 && A->arr[j] > key)
            {
                A->arr[j+1] = A->arr[j];
                j--;
            }
            A->arr[j+1] = key;
        }
        printf("Stack sorted using insertion sort...\n");
    }
}
//----------------------------------------------------------------------------
void push(struct stack *A, int data)
{
    if (stack_full(A))
    {
        printf("Stack is full, cannot push elements...\n");
        return;
    }
    else
    {
        A->top++;
        A->arr[A->top] = data;
        printf("Data added successfully...\n");
    }
}
//----------------------------------------------------------------
void pop(struct stack *A)
{
    if (stack_empty(A))
    {
        printf("Stack is empty, can't do pop...\n");
        return;
    }
    else
    {
        printf("Deleted element: %d\n", A->arr[A->top]);
        A->top--;
    }
}
//------------------------------------------------------------------
void peek(struct stack *A)
{
    if (stack_empty(A))   // ? correction
    {
        printf("Stack is empty...\n");
        return;
    }
    else
    {
        printf("Peek Element: %d\n", A->arr[A->top]);
    }
}
//-------------------------------------------------------------------
int main()
{
    int data, ch;
    struct stack s1;
    init(&s1);
    
    do
    {
        printf("========Menu========\n"); // ? correction
        printf("0.Exit\n1.push\n2.pop\n3.peek\n4.Bubble_sort\n5.Insertion_sort\n6.Selection_sort\n7.Binary_search\n8.Linear_search\n9.Display stack\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        
        switch (ch)
        {
            case 0:
            {
                printf("Thanks for using...\n");
                return 0;
            }
            case 1:
            {
                printf("Enter data to push in stack: ");
                scanf("%d", &data);
                push(&s1, data);
                break;
            }
            case 2:
            {
                pop(&s1);
                break;
            }
            case 3:
            {
                peek(&s1);
                break;
            }
            case 4:
            {
                bubble_sort(&s1);
                break;
            }
            case 5:
            {
                insertion_sort(&s1);
                break;
            }
            case 6:
            {
                selection_sort(&s1);
                break;
            }
            case 7:
            {
                int key;
                printf("Enter key to search: ");
                scanf("%d", &key);
                binary_search(&s1, key, 0, s1.top);
                break;
            }
            case 8:
            {
                int key;
                printf("Enter key to search: ");
                scanf("%d", &key);
                linear_search(&s1, key);
                break;
            }
            case 9:
            {
                display(&s1);
                break;
            }
            default:
            {
                printf("Invalid choice...\n");
                break;
            }
        }
    } while (ch != 0);
    
    return 0;
}
