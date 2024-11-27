#include <stdio.h>
#include <string.h>


struct Movie {
    char title[50];
    char genre[20];
    char director[50];
    int releaseYear;
    float rating;
};


void addMovie(struct Movie *movie) {
    printf("Enter movie title: ");
    scanf(" %[^\n]", movie->title);
    printf("Enter genre: ");
    scanf(" %[^\n]", movie->genre);
    printf("Enter director: ");
    scanf(" %[^\n]", movie->director);
    printf("Enter release year: ");
    scanf("%d", &movie->releaseYear);
    printf("Enter rating: ");
    scanf("%f", &movie->rating);
}


void searchByGenre(struct Movie movies[], int count, char genre[]) {
    printf("Movies of genre '%s':\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("- %s\n", movies[i].title);
        }
    }
}


void displayMovies(struct Movie movies[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nMovie %d Details:\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f\n", movies[i].rating);
    }
}

int main() {
    struct Movie movies[10];
    int movieCount = 0;
    int choice;
    char searchGenre[20];

    do {
        printf("\n1. Add a new movie\n");
        printf("2. Search by genre\n");
        printf("3. Display all movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (movieCount < 10) {
                    addMovie(&movies[movieCount]);
                    movieCount++;
                } else {
                    printf("Movie list is full.\n");
                }
                break;
            case 2:
                printf("Enter genre to search: ");
                scanf(" %[^\n]", searchGenre);
                searchByGenre(movies, movieCount, searchGenre);
                break;
            case 3:
                displayMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
