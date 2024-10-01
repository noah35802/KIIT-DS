#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Queue {
    struct Node* first;
    struct Node* next;
};

struct Queue* createQueue();
void enqueue(struct Queue* q, int value);
void dequeue(struct Queue* q);
void traverse(struct Queue* q);
int isEmpty(struct Queue* q);

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->first = NULL;
    q->next = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->link = NULL;

    if (q->next == NULL) {
        q->first = q->next = newNode;
        printf("Enqueued %d\n", value);
        return;
    }

    q->next->link = newNode;
    q->next = newNode;
    printf("Enqueued %d\n", value);
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    struct Node* temp = q->first;
    printf("Dequeued %d\n", q->first->data);
    q->first = q->first->link;

    if (q->first == NULL)
        q->next = NULL;

    free(temp);
}

int isEmpty(struct Queue* q) {
    return q->first == NULL;
}

void traverse(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = q->first;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    int choice, value;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. IsEmpty\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                traverse(q);
                break;
            case 4:
                if (isEmpty(q))
                    printf("Queue is Empty\n");
                else
                    printf("Queue is not Empty\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid!\n");
        }
    }

    return 0;
}