a.out: main.o create_account.o user_login.o admin_login.o validation.o load_save.o
	gcc -o a.out main.o create_account.o user_login.o admin_login.o validation.o load_save.o
main.o: main.c
	gcc -c main.c
create_account.o: create_account.c
	gcc -c create_account.c
user_login.o: user_login.c
	gcc -c user_login.c
admin_login.o: admin_login.c
	gcc -c admin_login.c
validation.o: validation.c
	gcc -c validation.c
load_save.o: load_save.c
	gcc -c load_save.c
clear:
	rm *.out *.o