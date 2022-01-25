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

    while (1) { 
        if (score > highscore) { 
            ptr = fopen("highscore.txt", "w"); 
            fprintf(ptr, "%d", score); 
            fclose(ptr); 
        } 
        choise = getchar(); 
        while (getchar() != '\n'); 

        if (choise == 'D' || choise == 'd') { 
            count++; 
            ch++; 
            createprev(p); 
            for (int i = 0; i < 4; i++) { 
                for (int j = 3; j >= 0; j--) { 
                    c[j] = arr[i][j]; 
                } 
                rupdate(); 
                for (int j = 0; j < 4; j++) { 
                    arr[i][j] = c[j]; 
                } 
            } 
        } 
        else if (choise == 'A' || choise == 'a') { 
            count++; 
            ch++; 
            createprev(p); 
            for (int i = 0; i < 4; i++) { 
                for (int j = 0; j < 4; j++) { 
                    c[j] = arr[i][j]; 
                } 
                rupdate(); 
                for (int j = 0; j < 4; j++) { 
                    arr[i][j] = c[j]; 
                } 
            } 
        } 
        else if (choise == 'S' || choise == 's') { 
            count++; 
            ch++; 
            createprev(p); 
            for (int i = 0; i < 4; i++) { 
                for (int j = 0; j < 4; j++) { 
                    c[j] = arr[j][i]; 
                } 
                rupdate(); 
                for (int j = 0; j < 4; j++) { 
                    arr[j][i] = c[j]; 
                } 
            } 
        } 
        else if (choise == 'W' || choise == 'w') { 
            count++; 
            ch++; 
            createprev(p); 
            for (int i = 0; i < 4; i++) { 
                for (int j = 3; j >= 0; j--) { 
                    c[j] = arr[j][i]; 
                } 
                rupdate(); 
                for (int j = 0; j < 4; j++) { 
                    arr[j][i] = c[j]; 
                } 
            } 
        } 
        else if (choise == 'P' || choise == 'p') { 
            ch++; 
            system("cls"); 
            updatearrtoprev(p); 
        } 
        else if (choise == 'R' || choise == 'r') { 
            ch++; 
            printf("\n******************DO YOU WANT TO RESTART -> Y or N ******************\n"); 
            reschk = getchar(); 
            while (getchar() != '\n'); 

            if (reschk == 'Y' || reschk == 'y') { 
                resetgame(); 
            } 
            else { 
                system("cls"); 
                print(); 
            } 
        } 
        else if (choise == 'U' || choise == 'u') { 
            printf("\n\t\t\t\t\tYOUR TOTAL SCORE=%d\n", score); 
            printf("\t\t\t\t\t---------------------------------\n"); 
            printf("\t\t\t\t\tTOTAL STEPS MOVED=%d\n", ch); 
            printf("\t\t\t\t\t---------------------------------\n"); 
            printf("\t\t\t\t\tQUITTING"); 
            for (int i = 0; i < 5; i++) { 
                Sleep(500); 
                printf("."); 
            } 
            exit(0); 
        } 
        else { 
            printf("\nENTER A VALID CHOICE\n"); 
            system("cls"); 
            print(); 
            continue; 
        }
        addrandomno(); 
        system("cls"); 
        print(); 
    } 
    return 0; 
} 
