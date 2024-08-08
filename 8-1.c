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
    printf("Enter the second polynomial:\n ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &poly2[i]);
    }
    printf("\nThe First Polynomial is: ");
    Polynomial(poly1, n);
    printf("\nThe Second Polynomial is: ");
    Polynomial(poly2, m);

    int max = n >= m ? n : m;
    int poly3[max];
    for(int i = 0; i < max; i++) {
        if(i < m && i < n || n == m) {
            poly3[i] = poly1[i] + poly2[i];
        } else {
            if(i >= n) {
                poly3[i] = poly2[i];
            }
            if(i >= m) {
                poly3[i] = poly1[i];
            }
        }
    }
    printf("\nThe Sum of the Polynomial is: ");
    Polynomial(poly3, max);
    return 0;
}