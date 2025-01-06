#ifndef USERFUNCTIONS_H  
#define USERFUNCTIONS_H  

typedef struct {  
    char userNumber[11];  
    char name[50];  
    char email[50];  
    char phone[15];  
    int gender;  
    int day, month, year;  
    char username[20];  
    double balance;  
    char status[10];
    char input[100];  
} User;  

void addUser();  
void showAllUsers();  
void searchUserByName();  
void searchUserByID();  
void lockUser();  
void unlockUser();  
void showAdminMenu();  
void showMainMenu();  
void showUserLoginScreen();  
void saveUsersToBinaryFile(const char *filename);
#endif
