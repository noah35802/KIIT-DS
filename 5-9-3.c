#include <stdio.h>
#include <stdlib.h>

const int SIZE = 200;
int *STACK_binary;
int TOP = -1;

void push(int value);
int pop();
void traverse();
void convert_to_binary(int decimal);

int main()
{
    int decimal;
    STACK_binary = malloc(SIZE * sizeof(int));

    printf("Enter the decimal number: ");
    scanf("%d", &decimal);

    convert_to_binary(decimal);
    printf("Binary value: ");
    traverse();

    return 0;
}

void push(int value)
{
    if (TOP >= SIZE - 1)
    {
        printf("Overflow.\n");
        return;
    }

    STACK_binary[++TOP] = value;}

int pop()
{
    if (TOP == -1)
    {
        printf("Underflow.\n");
        return -1;
    }

    return STACK_binary[TOP--];
}

void traverse()
{
    if (TOP == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    for (int i = TOP; i >= 0; i--)
    {
        printf("%d", STACK_binary[i]);
    }
    printf("\n");
}

void convert_to_binary(int decimal)
{
    while (decimal > 0)
    {
        push(decimal % 2);
        decimal = decimal / 2;
    }
}

