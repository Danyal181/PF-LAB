#include <stdio.h>

int main() {
    int oddstart;
    printf("Enter an odd number to initialize the pattern: ");
    scanf("%d", &oddstart);

    int rows = (oddstart + 1) / 2;

    for (int row = rows; row >= 1; row--) {
        int value = oddstart;
        
        for (int col = 1; col <= row; col++) {
            printf("%d ", value);
            value -= 2;
        }
        
        printf("\n");
        oddstart -= 2;
    }

    return 0;
}
