#include <stdio.h>

int main() {
    int matA[3][3], matB[3][3], product[3][3] = {0};

    printf("Enter values for Matrix A (3x3):\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("Element [%d][%d]: ", row + 1, col + 1);
            scanf("%d", &matA[row][col]);
        }
    }

    printf("Enter values for Matrix B (3x3):\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("Element [%d][%d]: ", row + 1, col + 1);
            scanf("%d", &matB[row][col]);
        }
    }

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            for (int element = 0; element < 3; element++) {
                product[row][col] += matA[row][element] * matB[element][col];
            }
        }
    }

    printf("Product of Matrix A and Matrix B:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", product[row][col]);
        }
        printf("\n");
    }

    return 0;
}
