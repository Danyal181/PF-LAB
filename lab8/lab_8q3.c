#include <stdio.h>

int main() {
    int matrix[3][3];
    int found = 0;

    printf("Enter 9 elements for a 3x3 matrix:\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("Element [%d][%d]: ", row + 1, col + 1);
            scanf("%d", &matrix[row][col]);
        }
    }

    for (int row = 0; row < 3; row++) {
        int minInRow = matrix[row][0];
        int minCol = 0;

        for (int col = 1; col < 3; col++) {
            if (matrix[row][col] < minInRow) {
                minInRow = matrix[row][col];
                minCol = col;
            }
        }

        int isSaddle = 1;
        for (int checkRow = 0; checkRow < 3; checkRow++) {
            if (matrix[checkRow][minCol] > minInRow) {
                isSaddle = 0;
                break;
            }
        }

        if (isSaddle) {
            printf("Saddle point at [%d][%d]: %d\n", row + 1, minCol + 1, minInRow);
            found = 1;
        }
    }

    if (!found) {
        printf("No saddle point in the matrix.\n");
    }

    return 0;
}