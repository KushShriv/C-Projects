#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void checkbalance(char*);
void transfermoney(void);
void display(char*);
void person(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);

void gotoxy(int x, int y){
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct pass {
	char username[50];
	int date, month, year;
	char pnumber[15];
	char adharnum[20];
	char fname[20];
	char lname[20];
	char fathname[20];
	char mothname[20];
	char address[50];
	char typeaccount[20];
};

struct money {
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
};

struct userpass {
	char password[50];
};

int main(){
	int i, a, b, choice;
	int passwordlength;

	gotoxy(20, 3);
	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");

	gotoxy(18, 5);
	printf("**********************************");

	gotoxy(25, 7);
	printf("DEVELOPER-Naman kumar");

	gotoxy(20, 10);
	printf("1.... CREATE A BANK ACCOUNT");

	gotoxy(20, 12);
	printf("2.... ALREADY A USER? SIGN IN");

	gotoxy(20, 14);
	printf("3.... EXIT\n\n");

	printf("\n\nENTER YOUR CHOICE..");

	scanf("%d", &choice);

	switch (choice) {
	case 1:
		system("cls");
		printf("\n\n USERNAME 50 CHARACTERS MAX!!");
		printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
		account();
		break;

	case 2:
		login();
		break;

	case 3:
		exit(0);
		break;

		getch();
	}
}

void login(void){
	system("cls");

	char username[50];
	char password[50];

	int i, j, k;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass u2;

	fp = fopen("username.txt",
			"rb");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	gotoxy(34, 2);
	printf(" ACCOUNT LOGIN ");
	gotoxy(7, 5);
	printf("***********************************************"
		"********************************");

	gotoxy(35, 10);
	printf("==== LOG IN ====");

	gotoxy(35, 12);
	printf("USERNAME.. ");
	scanf("%s", &username);

	gotoxy(35, 14);
	printf("PASSWORD..");

	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
			break;
	}

	while (fread(&u1, sizeof(u1), 1, fp)) {
		if (strcmp(username, u1.username)== 0) {
			loginsu();
			display(username);
		}
	}

	fclose(fp);
}

void loginsu(void){
	int i;
	FILE* fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0, 20);
	printf("Press enter to continue");

	getch();
}

void logout(void){
	int i, j;
	system("cls");
	printf("please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");

	getch();
}
