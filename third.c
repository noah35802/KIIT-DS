#include <stdio.h>

struct number {
    float real;
    float imag;
};

struct number sum(struct number n1, struct number n2) {
    struct number n3;
    n3.real = n1.real + n2.real;
    n3.imag = n1.imag + n2.imag;
    return n3;

}

struct number pro(struct number * n1, struct number * n2) {
    struct number n3;
    n3.real = (n1->real * n2->real) - (n1->imag * n2->imag);
    n3.imag = (n1->real * n2->imag) + (n1->imag * n2->real);
    return n3;
}

int main() {
    struct number n1, n2, n3;
    printf("Enter the first number :-\n");
    printf("Real part: ");
    scanf("%f", &n1.real);
    printf("Imaginary part: ");
    scanf("%f", &n1.imag);
    printf("Enter the second number :-\n");
    printf("Real part: ");
    scanf("%f", &n2.real);
    printf("Imaginary part: ");
    scanf("%f", &n2.imag);

    printf("\nThe first Number :- %.2f + i%.2f\nThe second Number :- %.2f + i%.2f", n1.real, n1.imag, n2.real, n2.imag);
    printf("\nPress :-\n1: Addition\n2: Multiplication\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        n3 = sum(n1,n2);
        printf("\nThe sum of the two numbers :- %.2f + i%.2f", n3.real, n3.imag);
        break;
    case 2:
        n3 = pro(&n1,&n2);
        printf("\nThe product of the two numbers :- %.2f + i%.2f", n3.real, n3.imag);
        break;

    default:
        printf("Wrong Input :(:(");
        break;
    }
    return 0;
}
