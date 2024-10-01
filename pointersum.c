#include <stdio.h>

void sum(int *ptr1, int *ptr2, int *ptr3) {
    *ptr3 = *ptr1 + *ptr2;
    printf("The sum is: %d\n", *ptr3);
}

int main() {
    int a, b, c;
    int *ptr1, *ptr2, *ptr3;
    
    ptr1 = &a;
    ptr2 = &b;
    ptr3 = &c;

    printf("Enter a number: ");
    scanf("%d", ptr1);

    printf("Enter second number: ");
    scanf("%d", ptr2);

    sum(ptr1, ptr2, ptr3);

    return 0;    
}
