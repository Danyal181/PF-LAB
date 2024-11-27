#include <stdio.h>
#include <string.h>

struct Flight {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
};


void displayFlight(struct Flight f) {
    printf("Flight Number: %d\n", f.flightNumber);
    printf("Departure City: %s\n", f.departureCity);
    printf("Destination City: %s\n", f.destinationCity);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.availableSeats);
}


void bookSeat(struct Flight *f) {
    if (f->availableSeats > 0) {
        f->availableSeats--;
        printf("Seat booked successfully! Remaining seats: %d\n", f->availableSeats);
    } else {
        printf("No seats available.\n");
    }
}

int main() {
    struct Flight flight = {101, "Karachi", "Lahore", "2024-12-05", 5};

    printf("Initial Flight Details:\n");
    displayFlight(flight);

    printf("\nBooking a seat...\n");
    bookSeat(&flight);

    printf("\nUpdated Flight Details:\n");
    displayFlight(flight);

    return 0;
}
