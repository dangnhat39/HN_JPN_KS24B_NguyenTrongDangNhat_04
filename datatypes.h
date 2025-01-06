#ifndef DATATYPES_H  
#define DATATYPES_H  

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

#endif