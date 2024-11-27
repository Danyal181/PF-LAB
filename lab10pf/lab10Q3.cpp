#include <stdio.h>

#define MAX_LIMIT 35

void monitorTemperature(float temperature) {
    static int exceedCount = 0;

    if (temperature > MAX_LIMIT) {
        exceedCount++;
        printf("Warning: %.2f exceeds the maximum limit!\n", temperature);
    } else {
        printf("%.2f is within the acceptable range.\n", temperature);
    }
    printf("Total Exceeds: %d\n", exceedCount);
}

int main() {
    float readings[] = {36.2, 34.0, 38.5, 33.8};
    for (int i = 0; i < 4; i++) {
        monitorTemperature(readings[i]);
    }
    return 0;
}
