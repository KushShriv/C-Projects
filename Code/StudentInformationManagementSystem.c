#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

struct sinfo {
	char fname[50];
	char lname[50];
	int roll;
	float cgpa;
	int cid[10];
} st[55];

void main(){
	int choice, count;
	while (i = 1) {
		printf("The Task that you want to perform\n");
		printf("1. Add the Student Details\n");
		printf("2. Find the Student Details by Roll Number\n");
		printf("3. Find the Student Details by First Name\n");
		printf("4. Find the Student Details by Course Id\n");
		printf("5. Find the Total number of Students\n");
		printf("6. Delete the Students Details by Roll Number\n");
		printf("7. Update the Students Details by Roll Number\n");
		printf("8. To Exit\n");
		printf("Enter your choice to find the task\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			add_student();
			break;
		case 2:
			find_rl();
			break;
		case 3:
			find_fn();
			break;
		case 4:
			find_c();
			break;
		case 5:
			tot_s();
			break;
		case 6:
			del_s();
			break;
		case 7:
			up_s();
			break;
		case 8:
			exit(0);
			break;
		}
	}
}
