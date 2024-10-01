#include <stdio.h>

int main() {
    int arr[10];
    int *ptr = arr;

    printf("Enter 10 elements of the array:\n");
    for (int i = 0; i < 10; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("The elements of the array are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr + i));
    }

    printf("\n");

    return 0;
}
