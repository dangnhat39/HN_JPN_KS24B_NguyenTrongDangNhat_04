#ifndef USERFUNCTIONS_H  
#define USERFUNCTIONS_H  
#include "datatypes.h"

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

