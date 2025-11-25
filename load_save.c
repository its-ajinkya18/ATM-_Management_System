#include "main.h"
void load_details(Accounts *account) {
    FILE *fptr = fopen("Info.csv","r");
    if(fptr==NULL) {
        printf("Error, file not found!\n");
        return ;
    }
    fscanf(fptr,"#%d\n",&(account->account_count));
    for(int i=0;i<account->account_count;i++)
        fscanf(fptr,"%[^,],%[^,],%f,%[^\n]\n",account->details[i].name,account->details[i].account_no,&account->details[i].balance,account->details[i].pin);
    fclose(fptr);
}

void save_details(Accounts *account) {
    FILE *fptr = fopen("Info.csv","w");
    if(fptr==NULL) {
        printf("Error, file not found!\n");
        return ;
    }
    fprintf(fptr,"#%d\n",account->account_count);
    for(int i=0;i<account->account_count;i++)
        fprintf(fptr,"%s,%s,%f,%s\n",account->details[i].name,account->details[i].account_no,account->details[i].balance,account->details[i].pin);
    fclose(fptr);
}