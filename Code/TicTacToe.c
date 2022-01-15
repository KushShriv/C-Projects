#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define COMPUTER 1 
#define HUMAN 2 
#define SIDE 3 
#define COMPUTERMOVE 'O' 
#define HUMANMOVE 'X' 

struct Move { 
	int row, col; 
}; 

char player = 'x', opponent = 'o'; 

void showBoard(char board[][SIDE]) { 
	printf("\n\n"); 
	printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]); 
	printf("\t\t\t--------------\n"); 
	printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]); 
	printf("\t\t\t--------------\n"); 
	printf("\t\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]); 
} 

void initialise(char board[][SIDE], int moves[]) { 
	srand(time(NULL)); 
	for (int i = 0; i < SIDE; i++) { 
		for (int j = 0; j < SIDE; j++) 
			board[i][j] = ' '; 
	} 

	for (int i = 0; i < SIDE * SIDE; i++) 
		moves[i] = i; 

	for (int i = 0; i < SIDE * SIDE; i++) { 
		int randIndex = rand() % (SIDE * SIDE); 
		int temp = moves[i]; 
		moves[i] = moves[randIndex]; 
		moves[randIndex] = temp; 
	} 
} 

int main() { 
	playTicTacToe(COMPUTER); 
	return 0; 
}