#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *Next;
} Node;

Node *TOP = NULL;

void push(int value);
int pop();
void peek();
int is_empty();
void traverse();

int main()
{
    printf("Enter 1 to Push a value into the STACK.\n");
    printf("Enter 2 to Pop value from the STACK.\n");
    printf("Enter 3 to Peek.\n");
    printf("Enter 4 to Check if the STACK is empty.\n");
    printf("Enter 5 to Traverse the STACK.\n");
    printf("Enter 6 to Exit.\n");

    int choice, value;
    while(1)
    {
        printf("Input: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                printf("%d\n", value);
                break;

            case 3:
                peek();
                break;
            
            case 4:
                value = is_empty();
                if (value)
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;

            case 5:
                traverse();
                break;

            case 6:
                return 0;
        }

    }
}

int is_empty()
{
    if (TOP == NULL)
        return 1;
    return 0;
}

void push(int value)
{
    Node *NEW;
    NEW = malloc(sizeof(Node));
    NEW->data = value;
    NEW->Next = NULL;

    if (is_empty())
    {
        TOP = NEW;
    } else 
    {
        NEW->Next = TOP;
        TOP = NEW;
    }

    printf("Value pushed successfully.\n");
}

int pop()
{
    if (is_empty())
    {
        printf("Underflow.\n");
        return -1;
    }

    int temp = TOP->data;
    TOP = TOP->Next;
    printf("Value popped successfully.\n");
    return temp;
}

void peek()
{
    if (is_empty())
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("%d\n", TOP->data);
}

void traverse()
{
    if (is_empty())
    {
        printf("Stack is empty.\n");
        return;
    }

    for (Node *ptr = TOP; ptr != NULL; ptr = ptr->Next)
        printf("%d ", ptr->data);
    printf("\n");
}