#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void print(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void insert_at_head(struct Node **head, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if (*head == NULL)
        *head = new;
    else{
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}

void insert_at_end(struct Node **head, int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if (*head == NULL)
        *head = new;
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
        new->prev = temp;
    }
}

void insert(struct Node **head, int data, int index)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    if (index < 0)
    {
        insert_at_head(head, data);
    }
    else
    {
        if (*head == NULL)
        {
            printf("\nElement added at position: 1");
            *head = new;
            return;
        }
        else
        {
            if (index == 0)
                insert_at_head(head, data);
            else
            {
                struct Node *temp = *head;
                for (int i = 1; i < index; i++)
                {
                    if (temp->next == NULL)
                    {
                        printf("Inserted at postion: %d", (i + 2));
                        insert_at_end(head, data);
                        return;
                    }
                    temp = temp->next;
                }
                if (temp->next == NULL)
                {
                    new->prev = temp;
                    temp->next = new;
                }
                else
                {
                    struct Node *temp2 = temp->next;
                    temp->next = new;
                    new->prev = temp;
                    new->next = temp2;
                    temp2->prev = new;
                }
            }
        }
    }
}

void del(struct Node **head, int index)
{
    if (index < 0)
    {
        printf("\nInvalid");
        return;
    }
    if (*head == NULL)
    {
        printf("\nEmpty");
        return;
    }
    if (index == 0)
    {
        *head = (*head)->next;
    }
    else
    {
        struct Node *current = *head;
        for (int i = 1; i < index; i++)
        {
            if (current->next == NULL)
            {
                printf("\nInvalid Index");
                return;
            }
            current = current->next;
        }
        current->next = current->next->next;
    }
}
void menu()
{
    printf("1: Insert\n");
    printf("2: Delete\n");
    printf("3: Print\n");
    printf("4: Exit\n");
}
void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    menu();
    int isTrue = 1;
    int choice, data, index;
    while (isTrue)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number and position: ");
            scanf("%d %d", &data, &index);
            insert(&head, data, index - 1);
            break;
        case 2:
            printf("Enter the position: ");
            scanf("%d", &index);
            del(&head, index - 1);
            break;
        case 3:
            print(head);
            break;
        case 4:
            printf("\nExit");
            isTrue = 0;
            break;
        default:
            printf("\nInvalid:");
            break;
        }
    }
}