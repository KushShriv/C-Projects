#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h> 

#define MAXRANDOMVALUE 3 
#define MAXPREV 500 

int findlen(int n); 

void print(); 
void movevalue(int k); 
void addrandomno(); 
void rupdate(); 
void resetgame(); 

int findlen(int n) { 
    int len = 0; 
    while (n) { 
        len++; 
        n /= 10; 
    } 
    return len; 
} 