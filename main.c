#include "main.h"
int pos;
int main()
{
    Accounts account;
    account.account_count = 0;
    load_details(&account);
    int option;
    do
    {
        printf("1. Create Account\n2. Login into your Account\n3. Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&option); 
        switch (option)
        {
        case 1:
            create_account(&account);
            break;
        case 2:
            login(&account);
            break;
        case 3:
            printf("Exiting ATM!\n");
            printf("\n---------------Thank you---------------\n");
            break;
        default:
            printf("Enter valid option.\n");
            break;
        }  
    } while (option != 3);
    return 0;   
}