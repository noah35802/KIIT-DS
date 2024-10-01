#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void enqueue(Stack *stack, int item) {
    if (is_full(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

int dequeue(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

void traverse(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Elements in the stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->items[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);

    enqueue(&stack, 1);
    enqueue(&stack, 2);
    enqueue(&stack, 3);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", dequeue(&stack));
    printf("Popped element: %d\n", dequeue(&stack));

    traverse(&stack);

    return 0;
}