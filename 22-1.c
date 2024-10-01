#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert_at_head(struct Node **head, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("ERROR");
        return;
    }
    node -> data = data;
    node -> next = NULL;
    if (*head == NULL)
        *head = node;
    else
    {
        node->next = *head;
        *head = node;
    }
}

void insert_at_end(struct Node **head, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("ERROR");
        return;
    }
    node -> data = data;
    node -> next = NULL;

    if (*head == NULL)
        *head = node;
    else
    {
        struct Node *end = *head;
        while (end -> next != NULL)
            end = end -> next;
        end -> next = node;
    }
}

void insert_at_pos(struct Node **head, int data, int index)
{
    if (index < 1)
    {
        printf("\nInvalid");
        return;
    }

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("ERROR");
        return;
    }
    node -> data = data;
    node -> next = NULL;

    if (index == 1)
    {
        node -> next = *head;
        *head = node;
    }
    else
    {
        struct Node *current = *head;
        for (int i = 1; i < index - 1; i++)
        {
            if (current == NULL)
                break;
            current = current -> next;
        }
        if (current == NULL)
        {
            printf("\nInvalid");
            return;
        }
        else
        {
            node -> next = current -> next;
            current -> next = node;
        }
    }
}

void delete_at_head(struct Node **head)
{
    if (*head == NULL)
        printf("\nERROR");
    else
    {
        *head = (*head) -> next;
    }
}

void delete_at_end(struct Node **head)
{
    if (*head == NULL)
    {
        printf("\nERROR");
        return;
    }
    else if ((*head) -> next == NULL)
        (*head) = NULL;
    else
    {
        struct Node *node = *head;
        while (node -> next -> next != NULL)
            node = node -> next;
        node -> next = NULL;
    }
}

void delete_at_pos(struct Node **head, int index)
{
    if (index < 0)
    {
        printf("\nInvalid");
        return;
    }
    if (*head == NULL)
    {
        printf("\nERROR");
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
                printf("\nInvalid");
                return;
            }
            current = current->next;
        }
        current -> next = current -> next -> next;
    }
}

void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("\nThe List was reversed successfully");
}

void print(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node -> data);
        node = node -> next;
    }
    printf("\n");
}


void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    int True = 1;
    while (True)
    {
        printf("1: Insert at Head\n");
        printf("2: Insert at End\n");
        printf("3: Insert at Position\n");
        printf("4: Delete at Head\n");
        printf("5: Delete at End\n");
        printf("6: Delete at Position\n");
        printf("7: Reverse\n");
        printf("8: Print\n");
        printf("9: Exit\n");
        printf("Enter your choice:\n");
        int choice;
        int data;
        int index;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &data);
            insert_at_head(&head, data);
            break;
        case 2:
            printf("Enter the number: ");
            scanf("%d", &data);
            insert_at_end(&head, data);
            break;
        case 3:
            printf("Enter the number: ");
            scanf("%d", &data);
            printf("Enetr the position: ");
            scanf("%d", &index);
            insert_at_pos(&head, data, index);
            break;
        case 4:
            delete_at_head(&head);
            break;
        case 5:
            delete_at_end(&head);
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &index);
            delete_at_pos(&head, index - 1);
            break;
        case 7:
            reverse(&head);
            break;
        case 8:
            print(head);
            break;
        case 9:
            printf("\nExit");
            True = 0;
            break;
        default:
            printf("Invalid");
            break;
        }
    }
}