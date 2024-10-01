#include <stdio.h>
#include <stdlib.h>

int prime(int n)
{
    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int sum(int *ptr, int a)
{
    int sum = 0;
    for(int i = 0; i < a; i++)
    {
        int n = *(ptr + i);
        if(prime(n))
        {
            sum = sum + n;
        }
    }
    return sum;
}
int main()
{
    int a;
    printf("Enter the number of elements: ");
    scanf("%d", &a);

    int *ptr = (int *)malloc(a *sizeof(int));
    for(int i = 0; i < a; i++)
    {
        printf("Enter number: ");
        scanf("%d", (ptr + i));
    }

    printf("The sum of the prime numbers are: %d", sum(ptr, a));
    
    free(ptr);
    return 0;
}