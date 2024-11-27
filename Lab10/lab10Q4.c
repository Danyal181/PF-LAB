#include <stdio.h>
#include <string.h>

#define maxcars 100

typedef struct {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
} Car;

Car cars[maxcars];
int carCount = 0;

void addCar() {
    if (carCount >= maxcars) {
        printf("Car storage is full!\n");
        return;
    }
    printf("Enter make: ");
    scanf("%s", cars[carCount].make);
    printf("Enter model: ");
    scanf("%s", cars[carCount].model);
    printf("Enter year: ");
    scanf("%d", &cars[carCount].year);
    printf("Enter price: ");
    scanf("%f", &cars[carCount].price);
    printf("Enter mileage: ");
    scanf("%f", &cars[carCount].mileage);
    carCount++;
}

void displayCars() {
    for (int i = 0; i < carCount; i++) {
        printf("Car %d: %s %s (%d) - $%.2f, %.2f km\n", i + 1, cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }
}

void searchCars() {
    char term[50];
    printf("Enter make or model to search: ");
    scanf("%s", term);

    for (int i = 0; i < carCount; i++) {
        if (strstr(cars[i].make, term) || strstr(cars[i].model, term)) {
            printf("Found: %s %s (%d) - $%.2f, %.2f km\n", cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Car\n2. Display Cars\n3. Search Cars\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCar(); 
			break;
            case 2: displayCars(); 
			break;
            case 3: searchCars(); 
			break;
        }
    } while (choice != 4);
    return 0;
}
