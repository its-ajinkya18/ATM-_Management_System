#include "main.h"
void user_login(Accounts *account) {
    char account_no[20], pin[10];
    printf("Enter your 10 digit Account number : ");
    scanf(" %[^\n]s",account_no);
    validate_account_no(account_no);
    printf("Enter your 4 digit PIN : ");
    scanf(" %[^\n]s",pin);
    validate_pin(pin);
    if(check_pin(account, account_no, pin, &pos) == FAILURE) {
        printf("Account Details not Matched!\nLogin failed\n\n");
        return;
    }
    printf("Account Details Matched\nLogin Successfully\n\n");
    int option;
    do {
        printf("1. View Account Details\n2. Check Balance\n3. Deposit\n4. Withdrawal\n5. Change PIN\n6. Logout\n");
        printf("Enter your choice : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            view_details(account, pos);
            break;
        case 2:
            check_balance(account,pos);
            break;
        case 3:
            deposit(account, pos);
            break;
        case 4:
            Withdrawal(account, pos);
            break;
        case 5:
            change_pin(account, pos);
            break;
        case 6:
            printf("Logout from your Account\n");
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }
    } while (option != 6);
}
void view_details(Accounts *account, int pos) {
    printf("\nName\t\t : %s\n",account->details[pos].name);
    printf("Account number\t : %s\n\n",account->details[pos].account_no);
    // printf("Balance\t\t : %.2f\n",account->details[pos].balance);
    // printf("PIN\t\t : %s\n\n",account->details[pos].pin);
}
void check_balance(Accounts *account, int pos) {
    printf("\nYour Account Balance = %.2f\n\n",account->details[pos].balance);
}
void deposit(Accounts *account, int pos) {
    int amount;
    printf("\nEnter Amount to Deposit : ");
    scanf("%d",&amount);
    if(amount < 0) {
        printf("Invalide Amount!\n\n");
        return;
    }
    else if(amount > 10000) {
        printf("You can Deposite upto 10000\n\n");
        return;
    }
    account->details[pos].balance = account->details[pos].balance + amount;
    save_details(account);
    printf("Amount Deposited Successfully\n\n");
}
void Withdrawal(Accounts *account, int pos) {
    int amount;
    printf("\nEnter Amount to Withdrawal : ");
    scanf("%d",&amount);
    if(amount < 0) {
        printf("Invalide Amount!\n\n");
        return;
    }
    if(amount > 10000) {
        printf("You can Withdrawal upto 10000\n\n");
        return;
    }
    else if(amount > account->details[pos].balance) {
        printf("Insufficient Balance\nWithdrawal failed\n\n");
        return;
    }
    account->details[pos].balance = account->details[pos].balance - amount;
    save_details(account);
    printf("Amount Withdrawal Successfully\n\n");
}
int change_pin(Accounts *account, int pos) {
    char new_pin[10];
    printf("\nEnter new PIN : ");
    scanf(" %[^\n]s",new_pin);
    validate_pin(new_pin);
    if(strcmp(new_pin, account->details[pos].pin) == 0) {
        printf("New PIN matches with Current PIN\nPlease take another PIN\n");
        return FAILURE;
    }
    strcpy(account->details[pos].pin, new_pin);
    save_details(account);
    printf("PIN changed Successfully\n\n");
    return SUCCESS;
}