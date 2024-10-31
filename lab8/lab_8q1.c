#include <stdio.h>

int main() {
    int start, end;

    printf("Enter starting value: ");
    scanf("%d", &start);
    printf("Enter ending value: ");
    scanf("%d", &end);

    for (int num = start; num <= end; num++) {
        if (num < 2) {
            continue;
        }

        int primeFlag = 1;

        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0) {
                primeFlag = 0;
                break;
            }
        }

        if (primeFlag) {
            printf("Prime number: %d\n", num);
        }
    }

    return 0;
}
