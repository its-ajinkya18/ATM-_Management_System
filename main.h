#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include<ctype.h>

#define MAX_ACCOUNTS        100

typedef struct {
    char name[25];
    char account_no[20];
    float balance;
    char pin[10];
}Account_details;

typedef struct 
{
    Account_details details[MAX_ACCOUNTS];
    int account_count;
}Accounts;

typedef enum
{
    SUCCESS,
    FAILURE
}Status;

extern int pos;

void create_account(Accounts *account);
void login(Accounts *account);
void validate_name(char name[]);
void validate_account_no(char account_no[]);
void validate_pin(char pin[]);
void search_account_no(Accounts *account, char account_no[]);
Status check_pin(Accounts *account, char account_no[], char pin[], int *pos);
void load_details(Accounts *account);
void save_details(Accounts *account);
void view_details(Accounts *account, int pos);
void check_balance(Accounts *account, int pos);
void deposit(Accounts *account, int pos);
void Withdrawal(Accounts *account, int pos);
void change_pin(Accounts *account, int pos);
#endif