#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    int True = 1;
    while (True)
    {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new -> data = num;
        new -> next = NULL;
        if (head == NULL)
        {
            head = new;
            head -> next = head;
        }
        else
        {
            struct Node *temp = head;
            while (temp -> next != head)
            {
                temp = temp -> next;
            }
            new -> next = head;
            temp -> next = new;
        }

        int choice;
        scanf("%d", &choice);
        if(choice != 1)
            True = 0;
    }

    printf("The List: ");
    struct Node *temp = head;
    do{
        printf("%d ", temp -> data);
        temp = temp -> next;
    } 
    while (temp -> next != head);
    return 0;
}