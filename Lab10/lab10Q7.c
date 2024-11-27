#include <stdio.h>

double convertToKilometers(double meters) {
    static int timesCalled = 0;
    timesCalled++;
    printf("This function has been called %d time(s).\n", timesCalled);
    return meters * 0.001;
}

int main() {
    double meters;
    printf("Enter distance in meters: ");
    scanf("%lf", &meters);

    double kilometers = convertToKilometers(meters);
    printf("%.2lf meters equals %.2lf kilometers.\n", meters, kilometers);

    return 0;
}

