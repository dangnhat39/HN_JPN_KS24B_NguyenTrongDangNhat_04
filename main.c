#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userFunctions.h"

int main(int argc, char *argv[]) {
    int choice;
    int valid;

    do {
        showMainMenu();
        valid = 0;

        do {
            char inputBuffer[10];
            printf("Enter your choice: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);

            inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 

            if (strlen(inputBuffer) == 0) {
                printf("Error: Choice cannot be empty. Please try again.\n");
                continue;
            }

            if (sscanf(inputBuffer, "%d", &choice) != 1) {
                printf("Error: Invalid input. Please enter a number.\n");
                continue;
            }

            valid = 1;
        } while (!valid);

        switch (choice) {
            case 1:
                showAdminMenu();
                break;
            case 2:
                showUserLoginScreen();
                break;
            case 0:
                printf("Exiting the program...\n");
                saveUsersToBinaryFile("users.bin");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}