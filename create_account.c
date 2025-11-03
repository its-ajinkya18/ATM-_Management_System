#include "main.h"
void create_account(Accounts *account)
{
    char name[25], account_no[20], pin[10];
    printf("Enter your Name : ");
    scanf(" %[^\n]s",name);
    validate_name(name);
    printf("Enter 10 digit Account number : ");
    scanf(" %[^\n]s",account_no);
    validate_account_no(account_no);
    search_account_no(account,account_no);
    printf("Enter 4 digit New PIN : ");
    scanf(" %[^\n]s",pin);
    validate_pin(pin);
    strcpy(account->details[account->account_count].name, name);
    strcpy(account->details[account->account_count].account_no, account_no);
    account->details[account->account_count].balance = 0;
    strcpy(account->details[account->account_count].pin, pin);
    (account->account_count)++;
    printf("----------Account Created Successfully----------\n");
    save_details(account);
}