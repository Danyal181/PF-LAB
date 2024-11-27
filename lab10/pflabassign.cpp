#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definitions
struct player {
    char name[20];
    char team[20];
};

struct bowl {
    char type[10];  // seamer, pacer, spinner, N/A
    char arm[5];    // left or right
    struct player ply;
};

struct bat {
    char type[10];  // top order, middle order, lower order
    char handed[8]; // lefty or righty
    struct bowl ply2;
};

// Function to add player records
void addPlayer() {
    FILE *filePtr = fopen("players.dat", "ab");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct bat playerInfo;

    for (int i = 0; i < 5; ++i) {
        printf("\nInput details for Player %d:\n", i + 1);

        printf("Enter Name: ");
        scanf("%s", playerInfo.ply2.ply.name);
        printf("Enter Team: ");
        scanf("%s", playerInfo.ply2.ply.team);

        // Only request bowler info for the first 3 players
        if (i < 3) {
            printf("Bowler type (seamer/pacer/spinner/N/A): ");
            scanf("%s", playerInfo.ply2.type);
            printf("Bowling Arm (left/right): ");
            scanf("%s", playerInfo.ply2.arm);
        } else {
            strcpy(playerInfo.ply2.type, "N/A");
            strcpy(playerInfo.ply2.arm, "N/A");
        }

        printf("Batsman Type (top/middle/lower): ");
        scanf("%s", playerInfo.type);
        printf("Handed (lefty/righty): ");
        scanf("%s", playerInfo.handed);

        fwrite(&playerInfo, sizeof(struct bat), 1, filePtr);
    }

    fclose(filePtr);
}

// Function to display player records
void displayPlayers() {
    FILE *filePtr = fopen("players.dat", "rb");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct bat playerInfo;

    printf("\nDisplaying all player data:\n");
    while (fread(&playerInfo, sizeof(struct bat), 1, filePtr)) {
        printf("\nName: %s | Team: %s | Bowler Type: %s | Arm: %s | Batting Type: %s | Handed: %s\n",
               playerInfo.ply2.ply.name, playerInfo.ply2.ply.team, playerInfo.ply2.type, playerInfo.ply2.arm, playerInfo.type, playerInfo.handed);
    }

    fclose(filePtr);
}

// Function to modify player data
void modifyPlayer() {
    FILE *filePtr = fopen("players.dat", "rb+");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct bat playerInfo;
    char playerName[20];
    int isFound = 0;

    printf("\nEnter player's name to modify: ");
    scanf("%s", playerName);

    while (fread(&playerInfo, sizeof(struct bat), 1, filePtr) && !isFound) {
        if (strcmp(playerInfo.ply2.ply.name, playerName) == 0) {
            printf("New Team: ");
            scanf("%s", playerInfo.ply2.ply.team);
            fseek(filePtr, -sizeof(struct bat), SEEK_CUR);
            fwrite(&playerInfo, sizeof(struct bat), 1, filePtr);
            isFound = 1;
        }
    }

    if (!isFound) {
        printf("Player not found.\n");
    }

    fclose(filePtr);
}

// Function to remove a player
void removePlayer() {
    FILE *filePtr = fopen("players.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    if (filePtr == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct bat playerInfo;
    char playerName[20];
    int isFound = 0;

    printf("\nEnter the name of the player to delete: ");
    scanf("%s", playerName);

    // Copy data to the temp file, skipping the record to delete
    while (fread(&playerInfo, sizeof(struct bat), 1, filePtr)) {
        if (strcmp(playerInfo.ply2.ply.name, playerName) != 0) {
            fwrite(&playerInfo, sizeof(struct bat), 1, tempFile);
        } else {
            isFound = 1;
        }
    }

    fclose(filePtr);
    fclose(tempFile);

    // If the player was found and removed, update the original file
    if (isFound) {
        remove("players.dat");
        rename("temp.dat", "players.dat");
        printf("Player %s deleted successfully.\n", playerName);
    } else {
        printf("Player not found.\n");
        remove("temp.dat");
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Players\n2. Display Players\n3. Modify Player\n4. Delete Player\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                displayPlayers();
                break;
            case 3:
                modifyPlayer();
                break;
            case 4:
                removePlayer();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}