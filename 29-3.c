#include <stdio.h>
#include <stdlib.h>

struct Header
{
    struct Node *head;
    int row;
    int col;
    int size;
};
struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
};

int main()
{
    int n, m;
    printf("Enter the row & column: ");
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    int a = 1;

    printf("Enter the elements of the sparse Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Enter a number: ");
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
                a++;
        }
    }

    struct Header *A = (struct Header *)malloc(sizeof(struct Header));
    A->row = n;
    A->col = m;
    A->size = a - 1;

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    A->head = head;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->row = i;
                newNode->col = j;
                newNode->value = matrix[i][j];
                newNode->next = NULL;
                if (head == NULL)
                {
                    head = newNode;
                }
                else
                {
                    struct Node *temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newNode;
                }
            }
        }
    }
    A->head = head;
    printf("\nThe sparse matrix :\n");
    printf("%d %d %d", A->row, A->col, A->size);
    struct Node *temp = A->head;
    while (temp != NULL) {
        printf("\n%d %d %d", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
    return 0;
}