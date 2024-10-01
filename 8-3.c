#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} sparse_matrix;

sparse_matrix* add_sparse_matrices(sparse_matrix* mat1, int num1, sparse_matrix* mat2, int num2, int* num_result)
{
    sparse_matrix* result = (sparse_matrix*)malloc((num1 + num2) * sizeof(sparse_matrix));
    int i = 0, j = 0, k = 0;

    while (i < num1 && j < num2) {
        if (mat1[i].row < mat2[j].row) {
            result[k++] = mat1[i++];
        } else if (mat1[i].row > mat2[j].row) {
            result[k++] = mat2[j++];
        } else {
            if (mat1[i].col < mat2[j].col) {
                result[k++] = mat1[i++];
            } else if (mat1[i].col > mat2[j].col) {
                result[k++] = mat2[j++];
            } else {
                result[k].row = mat1[i].row;
                result[k].col = mat1[i].col;
                result[k].val = mat1[i].val + mat2[j].val;
                i++;
                j++;
                k++;
            }
        }
    }

    while (i < num1) {
        result[k++] = mat1[i++];
    }

    while (j < num2) {
        result[k++] = mat2[j++];
    }

    *num_result = k;
    return result;
}

void print_sparse_matrix(sparse_matrix* mat, int num_terms) {
    int i;
    for (i = 0; i < num_terms; i++) {
        printf("(%d, %d, %d) ", mat[i].row, mat[i].col, mat[i].val);
    }
    printf("\n");
}

int main() {
    int num1, num2;

    printf("Enter the number of terms in Matrix 1: ");
    scanf("%d", &num1);

    sparse_matrix* mat1 = (sparse_matrix*)malloc(num1 * sizeof(sparse_matrix));

    printf("Enter the terms of Matrix 1:\n");
    for (int i = 0; i < num1; i++) {
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].val);
    }

    printf("Enter the number of terms in Matrix 2: ");
    scanf("%d", &num2);

    sparse_matrix* mat2 = (sparse_matrix*)malloc(num2 * sizeof(sparse_matrix));

    printf("Enter the terms of Matrix 2:\n");
    for (int i = 0; i < num2; i++) {
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].val);
    }

    int num_result;
    sparse_matrix* result = add_sparse_matrices(mat1, num1, mat2, num2, &num_result);

    printf("Matrix 1: ");
    print_sparse_matrix(mat1, num1);

    printf("Matrix 2: ");
    print_sparse_matrix(mat2, num2);

    printf("Result: ");
    print_sparse_matrix(result, num_result);

    free(mat1);
    free(mat2);
    free(result);

    return 0;
}