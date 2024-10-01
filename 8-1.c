#include <stdio.h>

int main() {
    printf("Enter the order of the first polynomial: ");
    int n;
    scanf("%d", &n);
    int p1[++n];
    printf("Enter the first polynomial:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p1[i]);
    }

    printf("Enter the order of the second polynomial: ");
    int m;
    scanf("%d", &m);
    int p2[++m];
    printf("Enter the second polynomial:\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &p2[i]);
    }
    printf("\nThe First Polynomial is: ");
    for(int i = 0; i < n; i++)
    {
        printf("%dx^%d ", p1[i], i);
    }
    printf("\nThe Second Polynomial is: ");
    for(int i = 0; i < n; i++)
    {
        printf("%dx^%d ", p2[i], i);
    }

    int max = n >= m ? n : m;
    int p3[max];
    for(int i = 0; i < max; i++)
    {
        if(i < m && i < n || n == m)
        {
            p3[i] = p1[i] + p2[i];
        } 
        else
        {
            if(i >= n)
            {
                p3[i] = p2[i];
            }
            if(i >= m)
            {
                p3[i] = p1[i];
            }
        }
    }
    printf("\nThe Sum of the Polynomial is: ");
    for(int i = 0; i < max; i++)
    {
        printf("%dx^%d ", p3[i], i);
    }
    return 0;
}