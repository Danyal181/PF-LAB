
#include <stdio.h>

#define METERS_TO_KILOMETERS 0.001

double convertToKilometers(double meters) {
    static int callCount = 0;
    callCount++;
    printf("Function called %d times\n", callCount);
    return meters * METERS_TO_KILOMETERS;
}

int main() {
    double meters;
    printf("Enter distance in meters: ");
    scanf("%lf", &meters);

    double kilometers = convertToKilometers(meters);
    printf("%.2lf meters is %.2lf kilometers\n", meters, kilometers);
    return 0;
}

