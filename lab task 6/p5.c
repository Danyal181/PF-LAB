#include<stdio.h>

int main() {
    int num = 0, i = 0;

    printf("Enter number ");
    scanf("%d", &num);

    for (i = 2; i <= 9; i++) {
        num = num / i;
        printf("\n%d", num);
    }

    return 0;
}
