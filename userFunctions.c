#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <stdbool.h>
#include "userFunctions.h"  

#define MAX_USERS 100  

User users[MAX_USERS];  
int userCount = 0;  

int isDuplicate(User newUser) { 
	int i; 
    for (i = 0; i < userCount; i++) {  
        if (strcmp(users[i].userNumber, newUser.userNumber) == 0 ||  
            strcmp(users[i].phone, newUser.phone) == 0 ||  
            strcmp(users[i].email, newUser.email) == 0 ||  
            strcmp(users[i].username, newUser.username) == 0) {  
            return 1;  
        }  
    }  
    return 0;  
}  

void showMainMenu() {  
    printf("***Bank Management System Using C***\n");  
    printf("===================================\n");  
    printf("          CHOOSE YOUR ROLE         \n");  
    printf("===================================\n");  
    printf("[1] Admin.\n");  
    printf("[2] User.\n");  
    printf("[0] Exit the Program.\n");  
    printf("===================================\n");  
    
}  

void showUserLoginScreen() {  
    printf("***Bank Management System Using C***\n");  
    printf("===================================\n");  
    printf("               LOGIN               \n");  
    printf("===================================\n");  
    printf("Email: test@gmail.com\n");  
    printf("Password: *****\n");  
    printf("===================================\n");  
    printf("[0] Back to Main Menu\n");  
    
    int choice;  
    int valid = 0;
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
    if (choice == 0) return;  

}  

int isValidDate(int day, int month, int year) {  
    if (year < 1900 || year > 2100) return 0;  
    if (month < 1 || month > 12) return 0;  
    if (day < 1 || day > 31) return 0;  
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return 0;  
    if (month == 2) {  
        int isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);  
        if (day > 28 + isLeap) return 0;  
    }  
    return 1;  
}  

void addUser() {  
    if (userCount >= MAX_USERS) {  
        printf("Error: User limit reached. Cannot add more users.\n");  
        return;  
    }  

    User newUser;  
    printf("\n*** Add a New User ***\n");  
    int valid;

     
  do {
    valid = 1; 
    char inputBuffer[100]; 

    printf("Enter the user ID: ");
    fgets(inputBuffer, sizeof(inputBuffer), stdin);

    
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

    if (strlen(inputBuffer) == 0) {
        printf("Error: User ID cannot be empty. Please try again.\n");
        valid = 0;
    } else if (strlen(inputBuffer) > 10) {
        printf("Error: User ID must be <= 10 characters. Please try again.\n");
        valid = 0;
    } else {
        int i;
        for (i = 0; i < userCount ; i++) {
            if (strcmp(users[i].userNumber, inputBuffer) == 0) {
                printf("Error: User ID '%s' already exists.\n", inputBuffer);
                valid = 0;
                break;
            }
        }
    }

	if (valid) {
	    strcpy(newUser.userNumber, inputBuffer); 
	}

   } while (!valid);


    do {
        valid = 1; 
        char inputBuffer[100];
        printf("Enter the name: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        
        if (strlen(inputBuffer) == 0) {
	        printf("Error: Name cannot be empty. Please try again.\n");
	        valid = 0;
        }
        else if (strlen(inputBuffer) > 50) {
            printf("Error: Name must be <= 50 characters.\n");
            valid = 0;
        } else {
            strcpy(newUser.name, inputBuffer); 
        }
    } while (!valid);


     do {
        valid = 1; 
        char inputBuffer[100];
        printf("Enter the Email: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        
        if (strlen(inputBuffer) == 0) {
	        printf("Error: Email user cannot be empty. Please try again.\n");
	        valid = 0;
        }
        else if (strlen(inputBuffer) > 50) {
            printf("Error: Email user must be <= 50 characters.\n");
            valid = 0;
        } else {
        	int i;
            for (i = 0; i < userCount; i++) {
                if (strcmp(users[i].email, inputBuffer) == 0) {
                    printf("Error: User email '%s' already exists.\n", inputBuffer);
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                strcpy(newUser.email, inputBuffer); 
             }
        }
	
    } while (!valid);



	do {
	    valid = 1;
	    char inputBuffer[20];
	    printf("Enter the Phone (10 digits): ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    
	    
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
	    
	   
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Phone number cannot be empty. Please try again.\n");
	        valid = 0;
	    } 
	  
	    else if (strlen(inputBuffer) != 10) {
	        printf("Error: Phone number must be exactly 10 digits.\n");
	        valid = 0;
	    } 
	    
	    else {
	        int i;
	        for (i = 0; i < strlen(inputBuffer); i++) {
	            if (!isdigit(inputBuffer[i])) {
	                printf("Error: Phone number must contain only digits.\n");
	                valid = 0;
	                break;
	            }
	        }
	    }
	
	    
	    if (valid) {
	        int i;
	        for (i = 0; i < userCount; i++) {
	            if (strcmp(users[i].phone, inputBuffer) == 0) {
	                printf("Error: Phone number '%s' already exists.\n", inputBuffer);
	                valid = 0;
	                break;
	            }
	        }
	    }
	
	   
	    if (valid) {
	        strcpy(newUser.phone, inputBuffer);
	    }
	
	} while (!valid);
	
	do {
	    valid = 1; 
	    char inputBuffer[10];
	    printf("Enter the gender (0 for Male, 1 for Female): ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    
	   
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
	
	    
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Gender cannot be empty. Please try again.\n");
	        valid = 0;
	    } else {
	        int gender = atoi(inputBuffer); 
	        if (gender != 0 && gender != 1) {
	            printf("Error: Gender must be 0 (Male) or 1 (Female).\n");
	            valid = 0;
	        } else {
	            newUser.gender = gender;
	        }
	    }
	
	} while (!valid);




    do {
	    valid = 1;
	    char inputBuffer[50];
	    printf("Enter the date of birth (dd mm yyyy): ");
	    fgets(inputBuffer, sizeof(inputBuffer), stdin);
	    inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 
	
	    if (strlen(inputBuffer) == 0) {
	        printf("Error: Date of birth cannot be empty. Please enter a valid date.\n");
	        valid = 0;
	    } else {
	        int day, month, year;
	        if (sscanf(inputBuffer, "%d %d %d", &day, &month, &year) != 3 || 
	            !isValidDate(day, month, year)) {
	            printf("Error: Invalid date of birth. Please enter a valid date in the format dd mm yyyy.\n");
	            valid = 0;
	        } else {
	            newUser.day = day;
	            newUser.month = month;
	            newUser.year = year;
	        }
	    }
	} while (!valid);

    do {
        valid = 1; 
        char inputBuffer[20];
        printf("Enter the username: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';
        
        if (strlen(inputBuffer) == 0) {
	        printf("Error: username cannot be empty. Please try again.\n");
	        valid = 0;
        }
        else if (strlen(inputBuffer) > 50) {
            printf("Error: username must be <= 20 characters.\n");
            valid = 0;
        } else {
        	int i;
            for (i = 0; i < userCount; i++) {
                if (strcmp(users[i].username, inputBuffer) == 0) {
                    printf("Error: username '%s' already exists.\n", inputBuffer);
                    valid = 0;
                    break;
                }
            }
            if (valid) {
		         strcpy(newUser.username, inputBuffer); 
	        }
        }
	
    } while (!valid);
    
    

   do {
        valid = 1;
        char inputBuffer[20];
        printf("Enter the balance: ");
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

        if (strlen(inputBuffer) == 0) {
            printf("Error: Balance cannot be empty. Please enter a positive number.\n");
            valid = 0;
        } else {
            char *endPtr;
            double balance = strtod(inputBuffer, &endPtr);
            if (*endPtr != '\0' || balance <= 0) {
                printf("Error: Balance must be a positive number.\n");
                valid = 0;
            } else {
                newUser.balance = balance;
            }
        }
    } while (!valid);
    
    strcpy(newUser.status, "Open");  

    users[userCount] = newUser;  
    userCount++;  
    printf("\nUser added successfully!\n");  
    saveUsersToBinaryFile("users.bin");
}   

void showAllUsers() {  
    if (userCount == 0) {  
        printf("\nNo accounts to display.\n");  
        return;  
    }  

    printf("\n========================================================================================\n");  
    printf("| %-10s | %-15s | %-25s | %-12s | %-10s |\n",  
           "ID", "Name", "Email", "Phone", "Status");  
    printf("========================================================================================\n");  
	

	int i;
    for (i = 0; i < userCount; i++) {  
        printf("| %-10s | %-15s | %-25s | %-12s | %-10s |\n",  
               users[i].userNumber,  
               users[i].name,  
               users[i].email,  
               users[i].phone,  
               users[i].status);  
    }  

    printf("========================================================================================\n");  
    printf("[0] Back to Main Menu\n");  
    int choice;  
    int valid = 0;
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
//    system("cls"); 
    if (choice == 0) return;  
}  

void searchUserByName() {  
    char searchName[50];  
    
    int valid = 0;
    do {
        char inputBuffer[10];
        printf("Enter the name of the user you want to search for: ");  
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 

        if (strlen(inputBuffer) == 0) {
            printf("Error: The Name cannot be empty. Please try again.\n");
            continue;
        }

        if (sscanf(inputBuffer, "%10s", searchName) != 1) {
            printf("Error: Invalid input. Please enter the ID.\n");
            continue;
        }

        valid = 1; 
    } while (!valid); 

    int found = 0;  
    printf("\nSearch results:\n");  
    printf("+------------+----------------------+----------------------+---------------+-------------+\n");  
    printf("| ID         | Name                 | Email                | Phone         | Status      |\n");  
    printf("+============+======================+======================+===============+=============+\n");  

	int i;
    for (i = 0; i < userCount; i++) {  
        if (strstr(users[i].name, searchName)) {  
            printf("| %-10s | %-20s | %-20s | %-13s | %-11s |\n",  
                   users[i].userNumber,  
                   users[i].name,  
                   users[i].email,  
                   users[i].phone,  
                   users[i].status);  
            found = 1;  
        }  
    }  

    printf("+------------+----------------------+----------------------+---------------+-------------+\n");  

    if (!found) {  
        printf("No users found!\n");  
    }  

    printf("[0] Back to Main Menu\n");  
    int choice;  
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
//    system("cls"); 
    if (choice == 0) return;  
}  

void searchUserByID() {  
    char searchID[11];  
	int valid = 0;
    do {
        char inputBuffer[10];
        printf("Enter the ID of the user you want to search for: ");  
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 

        if (strlen(inputBuffer) == 0) {
            printf("Error: Choice cannot be empty. Please try again.\n");
            continue;
        }

        if (sscanf(inputBuffer, "%10s", searchID) != 1) {
            printf("Error: Invalid input. Please enter the ID.\n");
            continue;
        }

        valid = 1; 
    } while (!valid); 
    
    int found = 0;  
    int i;
    for (i = 0; i < userCount; i++) {  
        if (strcmp(users[i].userNumber, searchID) == 0) {  
            printf("\nUser found:\n");  
            printf("ID: %s\n", users[i].userNumber);  
            printf("Name: %s\n", users[i].name);  
            printf("Email: %s\n", users[i].email);  
            printf("Phone: %s\n", users[i].phone);  
            printf("Gender: %s\n", users[i].gender == 0 ? "Male" : "Female");  
            printf("Date of Birth: %02d/%02d/%04d\n", users[i].day, users[i].month, users[i].year);  
            printf("Username: %s\n", users[i].username);  
            printf("Balance: %.2lf\n", users[i].balance);  
            printf("Status: %s\n", users[i].status);  
            found = 1;  
            break;  
        }  
    }  

    if (!found) {  
        printf("No user found with ID %s\n", searchID);  
    }  

    printf("[0] Back to Main Menu\n");  
    int choice;  
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
    if (choice == 0) return;  
}  

void lockUser() {  
    char userID[11];  
    
	int valid = 0;
    do {
        char inputBuffer[20];
        printf("Enter the ID of the user you want to lock: ");   
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 

        if (strlen(inputBuffer) == 0) {
            printf("Error: Choice cannot be empty. Please try again.\n");
            continue;
        }

        if (sscanf(inputBuffer, "%10s", userID) != 1) {
            printf("Error: Invalid input. Please enter the ID.\n");
            continue;
        }

        valid = 1; 
    } while (!valid); 
     
	
	int i;
    for (i = 0; i < userCount; i++) {  
        if (strcmp(users[i].userNumber, userID) == 0) {  
            if (strcmp(users[i].status, "Locked") == 0) {  
                printf("User is already locked.\n");  
            } else {  
                strcpy(users[i].status, "Locked");  
                printf("User %s is now locked.\n", users[i].name);  
            }  
            return;  
        }  
    }  
    printf("No user found with ID %s\n", userID);  
}  

void unlockUser() {  
    char userID[11];  
   
    
    int valid = 0;
    do {
        char inputBuffer[20];
        printf("Enter the ID of the user you want to unlock: ");     
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; 

        if (strlen(inputBuffer) == 0) {
            printf("Error: Choice cannot be empty. Please try again.\n");
            continue;
        }

        if (sscanf(inputBuffer, "%10s", userID) != 1) {
            printf("Error: Invalid input. Please enter the ID.\n");
            continue;
        }

        valid = 1; 
    } while (!valid); 

	int i;
    for (i = 0; i < userCount; i++) {  
        if (strcmp(users[i].userNumber, userID) == 0) {  
            if (strcmp(users[i].status, "Open") == 0) {  
                printf("User is already unlocked.\n");  
            } else {  
                strcpy(users[i].status, "Open");  
                printf("User %s is now unlocked.\n", users[i].name);  
            }  
            return;  
        }  
    }  
    printf("No user found with ID %s\n", userID);  
}  
void saveUsersToBinaryFile(const char *filename) {
    FILE *fp = fopen(filename, "wb"); 
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }
    fwrite(&userCount, sizeof(int), 1, fp);

	int i;
    for (i = 0; i < userCount; i++) {
        fwrite(&users[i], sizeof(User), 1, fp);
    }

    fclose(fp);
    printf("Save file '%s' success.\n", filename);
}

bool loadUsersFromBinaryFile(const char *filename, User users[], int *numUsers) {
    FILE *fp = fopen(filename, "rb"); 
    if (fp == NULL) {
        printf("No file with name '%s' found.\n", filename);
        return false;
    }

    if (fread(numUsers, sizeof(int), 1, fp) != 1) {
        printf("Error.\n");
        fclose(fp);
        return false;
    }

    if (*numUsers > MAX_USERS){
        printf("Index of user out of range.\n");
        *numUsers = 0;
        fclose(fp);
        return false;
    }

	int i;
    for (i = 0; i < *numUsers; i++) {
        if (fread(&users[i], sizeof(User), 1, fp) != 1) {
            printf("Error.\n");
            *numUsers = 0;
            fclose(fp);
            return false;
        }
    }

    fclose(fp);
    printf("Load users from file '%s' success.\n", filename);
    return true;
}

int compareUsers(const void *a, const void *b) {
    User *userA = (User *)a;
    User *userB = (User *)b;
    return strcmp(userA->name, userB->name);
}

void sortUsersByName() {
    if (userCount == 0) {
        printf("\nNo User.\n");
        return;
    }

    qsort(users, userCount, sizeof(User), compareUsers);

    printf("\nSort by Name Done.\n");
    showAllUsers(); 
}

int compareUsersByID(const void *a, const void *b) {
    User *userA = (User *)a;
    User *userB = (User *)b;
    return strcmp(userA->userNumber, userB->userNumber);
}

void sortUsersByID() {
    if (userCount == 0) {
        printf("\nNo User.\n");
        return;
    }

    qsort(users, userCount, sizeof(User), compareUsersByID);

    printf("\nSort by Id Done.\n");
    showAllUsers();
}

void showSortMenu() {
    int choice;
    do {
        printf("\n*** Sort Menu ***\n");
        printf("=======================\n");
        printf("[1] Sort by name\n");
        printf("[2] Sort by ID\n");
        printf("[0] Back to Main Menu\n");
        printf("=======================\n");

       
        int valid = 0;
        do {
            char inputBuffer[20];
            printf("Enter your choice to sort: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);

            inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

            if (strlen(inputBuffer) == 0) {
                printf("Error: Choice cannot be empty. Please try again.\n");
                continue;
            }

            if (sscanf(inputBuffer, "%d", &choice) != 1) {
                printf("Error: Invalid input. Please enter a valid number.\n");
                continue;
            }

            valid = 1; 
        } while (!valid);

       
        switch (choice) {
            case 1:
                sortUsersByName();
                break;
            case 2:
                sortUsersByID();
                break;
            case 0:
                return; 
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);
}

void showAdminMenu() {

    int choice;
    if (!loadUsersFromBinaryFile("users.bin", users, &userCount)) {
        printf("New User List.\n");
    }
	
    do {
        printf("***Bank Management System Using C***\n");
        printf("=======================================\n");
        printf("[1] Add User\n");
        printf("[2] Show All Users\n");
        printf("[3] Search User By Name\n");
        printf("[4] Search User By ID\n");
        printf("[5] Lock User\n");
        printf("[6] Unlock User\n");
        printf("[7] Sort User\n");
        printf("[0] Back to Main Menu\n");
        printf("=======================================\n");

        
        int valid = 0;
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
                addUser();
                break;
            case 2:
                showAllUsers();
                break;
            case 3:
                searchUserByName();
                break;
            case 4:
                searchUserByID();
                break;
            case 5:
                lockUser();
                break;
            case 6:
                unlockUser();
                break;
            case 7:
                showSortMenu();
                break;
            case 0:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);
}
