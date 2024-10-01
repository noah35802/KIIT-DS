#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

void enqueue(struct Queue* q, int value);
void dequeue(struct Queue* q);
void traverse(struct Queue* q);
int isFull(struct Queue* q);
int isEmpty(struct Queue* q);

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Dequeued %d\n", q->items[q->front]);
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

void traverse(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    int choice, value;

    while (1) {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Traverse");
        printf("\n4. IsEmpty");
        printf("\n5. IsFull");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                traverse(&q);
                break;
            case 4:
                if (isEmpty(&q))
                    printf("Queue is Empty\n");
                else
                    printf("Queue is not Empty\n");
                break;
            case 5:
                if (isFull(&q))
                    printf("Queue is Full\n");
                else
                    printf("Queue is not Full\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid!\n");
        }
    }

    return 0;
}