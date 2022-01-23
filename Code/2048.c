#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h> 

#define MAXRANDOMVALUE 3 
#define MAXPREV 500 

int arr[4][4] = { 0 }, c[4] = { 0 }, temp = 0, len = 0, score = 0, highscore = 0, count = 0, ch = 0; 

int findlen(int n); 

void print(); 
void movevalue(int k); 
void addrandomno(); 
void rupdate(); 
void createprev(int*** p); 
void updatearrtoprev(int*** p); 
void resetgame(); 

int findlen(int n) { 
    int len = 0; 
    while (n) { 
        len++; 
        n /= 10; 
    } 
    return len; 
} 

void movevalue(int k) {
    for (int i = k; i < 3; i++) { 
        if (c[i] == 0) { 
            c[i] = c[i + 1]; 
            c[i + 1] = 0; 
        } 
    } 
} 

void rupdate() { 
    for (int i = 3; i > 0; i--) { 
        if (c[i] == c[i - 1] && c[i] != 0) { 
            c[i] += c[i - 1]; 
            score += c[i]; 
            c[i - 1] = 0; 
        } 
    } 
    movevalue(0); 
} 

int main(){ 
    char choise, reschk; 
    int*** p = (int***)malloc(sizeof(int*) * MAXPREV); 
    for (int i = 0; i < MAXPREV; i++) { 
        p[i] = (int**)malloc(sizeof(int*) * 4); 
        for (int j = 0; j < 4; j++) { 
            p[i][j] = (int*)malloc(sizeof(int) * 4); 
        } 
    } 

    FILE* ptr = fopen("highscore.txt", "r"); 
    if (ptr != NULL) { 
        fscanf(ptr, "%d", &highscore); 
        fclose(ptr); 
    } 
    ptr = fopen("hstr.txt", "w"); 
    fclose(ptr); 
    addrandomno(); 
    print(); 
    return 0; 
} 
