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

int rowCrossed(char board[][SIDE]) { 
	for (int i = 0; i < SIDE; i++) { 
		if (board[i][0] == board[i][1] 
			&& board[i][1] == board[i][2] 
			&& board[i][0] != ' ') 
			return 1; 
	} 
	return 0; 
} 

int columnCrossed(char board[][SIDE]) { 
	for (int i = 0; i < SIDE; i++) { 
		if (board[0][i] == board[1][i] 
			&& board[1][i] == board[2][i] 
			&& board[0][i] != ' ') 
			return 1; 
	} 
	return 0; 
} 

int diagonalCrossed(char board[][SIDE]) { 
	if ((board[0][0] == board[1][1] 
		&& board[1][1] == board[2][2] 
		&& board[0][0] != ' ') 
		|| (board[0][2] == board[1][1] 
			&& board[1][1] == board[2][0] 
			&& board[0][2] != ' ')) 
		return 1; 
	return 0; 
} 

void playTicTacToe(int whoseTurn) { 
	char board[SIDE][SIDE]; 
	int moves[SIDE * SIDE]; 

	initialise(board, moves); 
	showInstructions(); 
	int moveIndex = 0, x, y; 

	while (!gameOver(board) && moveIndex != SIDE * SIDE) { 
		if (whoseTurn == COMPUTER) { 

			char tempBoard[3][3]; 
			for (int i = 0; i < 3; i++) { 
				for (int j = 0; j < 3; j++) { 
					if (board[i][j] == 'X') { 
						tempBoard[i][j] = 'x'; 
					} 
					else if (board[i][j] == 'O') { 
						tempBoard[i][j] = 'o'; 
					} 
					else { 
						tempBoard[i][j] = '_'; 
					} 
				} 
			} 
			struct Move thisMove = findBestMove(tempBoard); 
			x = thisMove.row; 
			y = thisMove.col; 

			board[x][y] = COMPUTERMOVE; 
			printf("COMPUTER has put a %c in cell %d %d\n", COMPUTERMOVE, x, y); 
			showBoard(board); 
			moveIndex++; 
			whoseTurn = HUMAN; 
		} 
		else if (whoseTurn == HUMAN) { 
			int move; 
			printf("Enter your move (1-9): "); 
			scanf("%d", &move); 
			if (move < 1 || move > 9) { 
				printf("Invalid input! Please enter a number between 1 and 9.\n"); 
				continue; 
			} 
			x = (move - 1) / SIDE; 
			y = (move - 1) % SIDE; 
			if (board[x][y] == ' ') { 
				board[x][y] = HUMANMOVE; 
				showBoard(board); 
				moveIndex++; 
				if (gameOver(board)) { 
					declareWinner(HUMAN); 
					return; 
				} 
				whoseTurn = COMPUTER; 
			} 
			else { 
				printf("Cell %d is already occupied. Try again.\n", move); 
			} 
		} 
	} 

	if (!gameOver(board) && moveIndex == SIDE * SIDE) 
		printf("It's a draw\n"); 
	else { 
		if (whoseTurn == COMPUTER) 
			whoseTurn = HUMAN; 
		else if (whoseTurn == HUMAN) 
			whoseTurn = COMPUTER; 
		declareWinner(whoseTurn); 
	} 
} 

int main() { 
	playTicTacToe(COMPUTER); 
	return 0; 
}