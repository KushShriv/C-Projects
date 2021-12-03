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

void add_student(){
	printf("Add the Students Details\n");
	printf("-------------------------\n");
	
    printf("Enter the first name of student\n");
	
    scanf("%s", st[i].fname);
	printf("Enter the last name of student\n");
	
    scanf("%s", st[i].lname);
	printf("Enter the Roll Number\n");
	
    scanf("%d", &st[i].roll);
	printf("Enter the CGPA you obtained\n");
	
    scanf("%f", &st[i].cgpa);
	printf("Enter the course ID of each course\n");
	
    for (int j = 0; j < 5; j++) {
		scanf("%d", &st[i].cid[j]);
	}
	i = i + 1;
}

void up_s(){
	printf("Enter the roll number to update the entry : ");
	long int x;
	scanf("%ld", &x);
	for (int j = 0; j < i; j++) {
		if (st[j].roll == x) {
			printf("1. first name\n"
				"2. last name\n"
				"3. roll no.\n"
				"4. CGPA\n"
				"5. courses\n");
			int z;
			scanf("%d", &z);
			switch (z) {
			case 1:
				printf("Enter the new first name : \n");
				scanf("%s", st[j].fname);
				break;
			case 2:
				printf("Enter the new "
					"last name : \n");
				scanf("%s", st[j].lname);
				break;
			case 3:
				printf("Enter the new "
					"roll number : \n");
				scanf("%d", &st[j].roll);
				break;
			case 4:
				printf("Enter the new CGPA : \n");
				scanf("%f", &st[j].cgpa);
				break;
			case 5:
				printf("Enter the new courses \n");
				scanf(
					"%d%d%d%d%d", &st[j].cid[0],
					&st[j].cid[1], &st[j].cid[2],
					&st[j].cid[3], &st[j].cid[4]);
				break;
			}
			printf("UPDATED SUCCESSFULLY.\n");
		}
	}
}

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
