#include <stdio.h>

int Polynomial(int arr[], int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%dx^%d ", arr[i], i);
    }
}

int main() {
    printf("Enter the order of the first polynomial: ");
    int n;
    scanf("%d", &n);
    int poly1[++n];
    printf("Enter the first polynomial:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter the order of the second polynomial: ");
    int m;
    scanf("%d", &m);
    int poly2[++m];
    printf("Enter the second polynomial:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &poly2[i]);
    }
    printf("\nThe First Polynomial: ");
    Polynomial(poly1, n);
    printf("\nThe Second Polynomial: ");
    Polynomial(poly2, m);

    int max = m + n - 1;
    int poly3[max];
    for(int i = 0; i < max; i++) {
        poly3[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            poly3[i + j] += poly1[i] * poly2[j];
        }
    }
    printf("\nThe Product of the Polynomial is: ");
    Polynomial(poly3, max);
    return 0;
}