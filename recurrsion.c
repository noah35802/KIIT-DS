#include <stdio.h>

int sum_series(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n + sum_series(n - 1);
    }
}

int main() {
    int n;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n > 0) {
        int result = sum_series(n);
        printf("The sum of the series 1 + 2 + 3 + ... + %d is: %d\n", n, result);
    } else {
        printf("Please enter a positive integer.\n");
    }

    return 0;
}
