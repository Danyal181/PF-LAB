#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 50

typedef struct {
    char name[100];
    char destination[100];
    int duration;
    float cost;
    int seats;
} Package;

Package packages[MAX_PACKAGES];
int packageCount = 0;

void addPackage() {
    if (packageCount >= MAX_PACKAGES) {
        printf("Package storage is full!\n");
        return;
    }
    printf("Enter package name: ");
    scanf("%s", packages[packageCount].name);
    printf("Enter destination: ");
    scanf("%s", packages[packageCount].destination);
    printf("Enter duration (days): ");
    scanf("%d", &packages[packageCount].duration);
    printf("Enter cost: ");
    scanf("%f", &packages[packageCount].cost);
    printf("Enter available seats: ");
    scanf("%d", &packages[packageCount].seats);
    packageCount++;
}

void displayPackages() {
    for (int i = 0; i < packageCount; i++) {
        printf("Package %d: %s to %s, %d days, $%.2f, %d seats available\n", i + 1, packages[i].name, packages[i].destination, packages[i].duration, packages[i].cost, packages[i].seats);
    }
}

void bookPackage() {
    int index;
    printf("Enter package number to book: ");
    scanf("%d", &index);

    if (index > 0 && index <= packageCount && packages[index - 1].seats > 0) {
        packages[index - 1].seats--;
        printf("Package booked successfully!\n");
    } else {
        printf("Invalid selection or no seats available.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Package\n2. Display Packages\n3. Book Package\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPackage(); break;
            case 2: displayPackages(); break;
            case 3: bookPackage(); break;
        }
    } while (choice != 4);
    return 0;
}
