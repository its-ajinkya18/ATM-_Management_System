#include "main.h"
void validate_name(char name[]) {
    int flag=0;
    for(int i=0;name[i]!='\0';i++) {
        if(isalpha(name[i]) || name[i]==' ')
            continue;
        else {
            flag=1;
            break;
        }
    }
    if(flag==1) {
        printf("Enter the valid Name: ");
        scanf(" %[^\n]",name);
        validate_name(name);
    }
}

void validate_account_no(char account_no[]) {
    int count=0,flag=0,num;
    for(int i=0;account_no[i]!='\0';i++){
        if(account_no[i]>='0' && account_no[i]<='9') {
            count++;
            continue;
        }
        else {
            flag=1;
            break;
        }
    }
    if(flag==1 || count!=10) {
        printf("Enter the valid Account number: ");
        scanf(" %[^\n]",account_no);
        validate_account_no(account_no);
    }
}

void validate_pin(char pin[]) {
    int count=0,flag=0,num;
    for(int i=0;pin[i]!='\0';i++) {
        if(pin[i]>='0' && pin[i]<='9') {
            count++;
            continue;
        }
        else {
            flag = 1;
            break;
        }
    }
    if(flag == 1 || count != 4) {
        printf("Enter the valid PIN : ");
        scanf(" %[^\n]",pin);
        validate_pin(pin);
    }
}

void  search_account_no(Accounts *account, char account_no[]) {
    int flag=0;
    for(int i=0;i<account->account_count;i++) {
        if(strcmp(account_no,account->details[i].account_no)==0) {
            flag=1;
            break;
        }
    }
    if(flag==0)
        return;
    else if(flag==1) {
        printf("Account number Already exists!\nEnter another Account number : ");
        scanf(" %[^\n]s",account_no);
        validate_account_no(account_no);
        search_account_no(account,account_no);
    }
}

Status check_pin(Accounts *account, char account_no[], char pin[], int *pos) {
    for(int i=0;i<account->account_count;i++) {
        if(strcmp(account->details[i].account_no, account_no) == 0 && strcmp(account->details[i].pin, pin) == 0) {
            *pos = i;
            return SUCCESS;
        }
    }
    return FAILURE;
}