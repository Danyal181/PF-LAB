#include<stdio.h>

int main() {
    int value = 0, temp = 0;

    do {
        printf("Enter the number ");
        scanf("%d", &value);
        temp = value;
        printf("%d\n", temp);
    } while (temp != 0);
printf("Program terminated");
    return 0;
}
