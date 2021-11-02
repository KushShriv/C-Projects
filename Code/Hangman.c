#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

struct WordWithHint {
	char word[MAX_WORD_LENGTH];
	char hint[MAX_WORD_LENGTH];
};

void displayWord(const char word[], const bool guessed[]);
void drawHangman(int tries);

int main()
{
	srand(time(NULL));
    struct WordWithHint wordList[] = {
        { "Programming", "Computer coding" },
        { "elephant", "A large mammal with a trunk" },
        { "pizza", "A popular Italian dish" },
        { "beach", "Sandy shore by the sea" },
        { "python", "A popular programming language" },
        { "guitar", "A stringed musical instrument" },
        { "chocolate", "A sweet treat made from cocoa" },
        { "mountain", "A large natural elevation of the earth's surface" },
        { "umbrella", "Used to protect from rain" },
        { "volcano", "A mountain with a crater that erupts" },
        { "pyramid", "An ancient monumental structure in Egypt" },
        { "butterfly", "An insect with colorful wings" },
        { "astronaut", "A person who travels to space" },
        { "coffee", "A popular caffeinated drink" },
        { "tiger", "A large wild cat with stripes" },
        { "library", "A place with a collection of books" },
        { "sunflower", "A tall plant with a large yellow flower" },
        { "diamond", "A precious gemstone" },
        { "kangaroo", "A hopping marsupial from Australia" },
        { "river", "A large natural stream of water" },
        { "robot", "A machine capable of carrying out complex tasks" },
        { "sushi", "A Japanese dish made with rice and fish" },
        { "desert", "A dry, barren area of land" },
        { "violin", "A small stringed instrument played with a bow" },
        { "castle", "A large fortified building" }
    };


	// Select a random word from the list
	int wordIndex = rand() % 25;

	const char* secretWord = wordList[wordIndex].word;
	const char* hint = wordList[wordIndex].hint;

	int wordLength = strlen(secretWord);
	char guessedWord[MAX_WORD_LENGTH] = { 0 };
	bool guessedLetters[26] = { false };

	printf("Welcome to Hangman!\n");
	printf("Hint: %s\n", hint);

	int tries = 0;

	while (tries < MAX_TRIES) {
		printf("\n");
		displayWord(guessedWord, guessedLetters);
		drawHangman(tries);

		char guess;
		printf("Enter a letter: ");
		scanf(" %c", &guess);
		guess = tolower(guess);

		if (guessedLetters[guess - 'a']) {
			printf("You've already guessed that letter. Try again.\n");
			continue;
		}

		guessedLetters[guess - 'a'] = true;

		bool found = false;
		for (int i = 0; i < wordLength; i++) {
			if (secretWord[i] == guess) {
				found = true;
				guessedWord[i] = guess;
			}
		}

		if (found) {
			printf("Good guess!\n");
		}
		else {
			printf("Sorry, the letter '%c' is not in the word.\n", guess);
			tries++;
		}

		if (strcmp(secretWord, guessedWord) == 0) {
			printf("\nCongratulations! You've guessed the word: %s\n", secretWord);
			break;
		}
	}

	if (tries >= MAX_TRIES) {
		printf("\nSorry, you've run out of tries. The word was: %s\n", secretWord);
	}

	return 0;
}

void displayWord(const char word[], const bool guessed[])
{
	printf("Word: ");
	for (int i = 0; word[i] != '\0'; i++) {
		if (guessed[word[i] - 'a']) {
			printf("%c ", word[i]);
		}
		else {
			printf("_ ");
		}
	}
	printf("\n");
}

void drawHangman(int tries)
{
	const char* hangmanParts[]
		= { "	 _________", " |		 |",
			" |		 O", " |	 /|\\",
			" |	 / \\", " |" };

	printf("\n");
	for (int i = 0; i <= tries; i++) {
		printf("%s\n", hangmanParts[i]);
	}
}
