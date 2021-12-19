#include <stdio.h> 
#include <string.h> 

#define MAX_C 11 

typedef struct Candidate { 
	char name[50]; 
	int votes; 
	char symbol; 
} Candidate; 

Candidate allCandidates[MAX_C]; 
int candidateCount = 0; 
char symbols[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '~', '+' }; 
int symbolTaken[11]; 

void fillCandidate(int); 
void displayAllCandidates(); 
void getVotes(int); 
void getResults(); 

int main() { 
	for (int i = 0; i < 11; i++) { 
		symbolTaken[i] = 0; 
	} 

	printf("Enter the number of candidates: "); 
	scanf("%d", &candidateCount); 
	if (candidateCount >= MAX_C) { 
		printf("Number of candidates cannot be greater than 10.\n Terminating the program\n\n"); 
		return 0; 
	} 

	for (int i = 0; i < candidateCount; i++) { 
		fillCandidate(i); 
	} 

	int numVoters; 
	printf("Enter the number of voters: "); 
	scanf("%d", &numVoters); 

	for (int i = 0; i < numVoters; i++) { 
		getVotes(i); 
	} 

	getResults(); 
	return 0; 
} 