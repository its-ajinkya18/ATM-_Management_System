#include"main.h"
void admin_login(Accounts *account) {
    char username[20], pass[10];
    printf("Enter the username : ");
    scanf(" %[^\n]",username);
    validate_name(username);
    printf("Enter the password : ");
    scanf(" %[^\n]",pass);
    validate_pin(pass);
    if(check_admin(username, pass) == FAILURE) {
        printf("Admin Login Failed..!\n\n");
        return;
    }
    printf("Admin login Successfully\n\n");
    int op;
    do {
        printf("1. View Account count\n2. Search Account\n3. Delete Account\n4. Logout\nEnter your choice : ");
        scanf("%d",&op);
        switch(op) {
            case 1:
                view_acc_cnt(account);
                break;
            case 2:
                search_acc(account);
                break;
            case 3:
                delete_acc(account);
                break;
            case 4:
                return;
                break;
            default :
                printf("Invalide Choice..!");
                break;
        }

    }while(op != 4);
}
int view_acc_cnt(Accounts *account) {
    printf("Total Accounts = %d\n\n",account->account_count);
}
int search_acc(Accounts *account) {
    char name[20], acc_no[20];
    int op, flag = 0, i=0;
    printf("1. Search by name\n2. Search by Account number\n3. Exit\nEnter your choice : ");
    scanf("%d",&op);
    switch(op) {
        case 1:
            printf("Enter name to search : ");
            scanf(" %[^\n]",name);
            validate_name(name);
            for(i=0;i<account->account_count;i++) {
                if(strstr(account->details[i].name, name) != NULL) {
                    flag = 1;
                    printf("Name\t\t: %s\nAccount number\t: %s\n\n",account->details[i].name,account->details[i].account_no);
                }
            }
            if(flag == 0) {
                printf("Not found.\n");
            }
            break;
        case 2:
            printf("Enter Account number to search : ");
            scanf(" %[^\n]",acc_no);
            validate_account_no(acc_no);
            for(i=0;i<account->account_count;i++) {
                if(strcmp(account->details[i].account_no, acc_no) == 0) {
                    flag = 1;
                    printf("Name\t\t: %s\nAccount number\t: %s\n\n",account->details[i].name,account->details[i].account_no);
                }
            }
            if(flag == 0) {
                printf("Account not found.\n");
            }
            break;
        case 3:
            return FAILURE;
            break;
        default :
            printf("Invalide choice..!\n");
            break;
    }
}
int delete_acc(Accounts *account) {
    char acc[20], ch;
    int flag= 0;
    printf("Enter the Account number to delete : ");
    scanf(" %[^\n]",acc);
    for(int i=0;i<account->account_count;i++){
        if(strcmp(account->details[i].account_no,acc)==0){
            flag = 1;
            printf("Name\t\t: %s\nAccount number\t: %s\n",account->details[i].name, account->details[i].account_no);
            break;
        }
    }
    if(flag == 1) {
        printf("Do you want to delete the Account.\t\t(Y/N) : ");
        scanf(" %c",&ch);
        if(ch == 'Y' || ch == 'y') {
            for(int i=0;i<account->account_count;i++){
                if(strcmp(account->details[i].account_no,acc) == 0){
                    for(int j=i;j<account->account_count;j++){
                        account->details[j] = account->details[j+1];
                    }
                    account->account_count--;
                    break;
                }
            }
            printf("Account Deleted Successfully..!\n");
            save_details(account);
        }
        else if(ch == 'N' || ch == 'n') {
            printf("Account not Deleted..!\n\n");
            return FAILURE;
        }
        else {
            printf("Invalide input..!\n");
            return FAILURE;
        }
    }
    else {
        printf("Account not found..!\n");
        return FAILURE;
    }
    return SUCCESS;
}