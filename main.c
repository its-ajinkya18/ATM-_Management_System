#include "main.h"
int pos;
char *admin_pass = "2025", *user_name = "Admin";
int main()
{
    Accounts account;
    account.account_count = 0;
    load_details(&account);
    int option;
    do
    {
        printf("1. Create Account\n2. User login\n3. Admin login\n4. Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&option); 
        switch (option)
        {
        case 1:
            create_account(&account);
            break;
        case 2:
            user_login(&account);
            break;
        case 3:
            admin_login(&account);
            break;
        case 4:
            printf("Exiting ATM!\n");
            printf("\n---------------Thank you---------------\n");
            break;
        default:
            printf("Enter valid option.\n");
            break;
        }  
    } while (option != 4);
    return 0;   
}