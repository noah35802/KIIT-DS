#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 200;
char *STACK;
int TOP = -1;

void push(int value);
void reverse_string(char *string);

int main()
{
    char string[SIZE];
    STACK = malloc(SIZE * sizeof(char));
    
    printf("Enter the string: ");
    fgets(string, SIZE, stdin);
    string[strlen(string) - 1] = '\0';
    
    reverse_string(string);

    if (strcmp(string, STACK) == 0)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}

void push(int value)
{
    if (TOP >= SIZE - 1)
    {
        printf("Overflow.\n");
        return;
    }

    STACK[++TOP] = value;}

void reverse_string(char *string)
{
    for (int i = strlen(string) - 1; i >= 0; i--)
        push(string[i]);
}
