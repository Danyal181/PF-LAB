#include <stdio.h>

void bubbleSort(int arr[], int n) {
    if (n <= 1) return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSort(arr, n - 1);
}

int main() {
    int arr[] = {5, 3, 8, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
