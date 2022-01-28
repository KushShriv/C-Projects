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

void print() { 
    int i, j, k, len1; 

    printf("\n\t\t\t\t\t===============2048==============\n"); 
    printf("\t\t\t\t\tYOUR SCORE=%d\n", score); 
    if (score < highscore) { 
        printf("\t\t\t\t\tHIGH SCORE=%d\n", highscore); 
    } 
    else { 
        highscore = score; 
        printf("\t\t\t\t\tHIGH SCORE=%d\n", highscore); 
    } 
    printf("\t\t\t\t\t---------------------------------\n"); 
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            if (j == 0) { 
                printf("\t\t\t\t\t|"); 
            } 
            if (arr[i][j] != 0) { 
                len1 = findlen(arr[i][j]); 
                for (k = 0; k < 4 - len1; k++) { 
                    printf(" "); 
                } 
                printf("%d", arr[i][j]); 
                for (k = 0; k < 4 - len1; k++) { 
                    printf(" "); 
                } 
                printf("|"); 
            } 
            else { 
                printf("    |"); 
            } 
        } 
        printf("\n"); 
        if (i != 3) { 
            printf("\t\t\t\t\t---------------------------------\n"); 
        } 
    } 
    printf("\t\t\t\t\t---------------------------------\n"); 
    printf("\t\t\t\t\tPREV-> P\t\tRESTART-> R\t\tEXIT-> U\n"); 
    printf("\t\t\t\t\tENTER YOUR CHOICE -> W,S,A,D\n"); 
} 

void movevalue(int k) {
    for (int i = k; i < 3; i++) { 
        if (c[i] == 0) { 
            c[i] = c[i + 1]; 
            c[i + 1] = 0; 
        } 
    } 
} 

void addrandomno() { 
    srand(time(NULL)); 
    int i, j; 
    do { 
        i = rand() % 4; 
        j = rand() % 4; 
    } while (arr[i][j] != 0); 
    arr[i][j] = (rand() % 10) == 0 ? 4 : 2; 
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

void createprev(int*** p) { 
    FILE* ptr = fopen("hstr.txt", "a"); 
    fprintf(ptr, "%d ", score); 
    fclose(ptr); 

    if (count == MAXPREV) { 
        for (int i = MAXPREV; i > 0; i--) { 
            for (int j = 0; j < 4; j++) { 
                for (int k = 0; k < 4; k++) { 
                    p[i][j][k] = p[i - 1][j][k]; 
                } 
            } 
        } 
    } 

    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            p[0][i][j] = arr[i][j]; 
        } 
    } 
    count++; 
} 

void updatearrtoprev(int*** p) {
    if (count == 0) { 
        printf("\n******FURTHER MORE PREV NOT POSSIBLE********\n"); 
        return; 
    } 

    FILE* ptr = fopen("hstr.txt", "r"); 
    int data; 
    for (int i = 0; i < count; i++) { 
        fscanf(ptr, "%d", &data); 
    } 
    score = data; 
    fclose(ptr); 

    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            arr[i][j] = p[0][i][j]; 
        } 
    } 

    for (int i = 0; i < MAXPREV - 1; i++) { 
        for (int j = 0; j < 4; j++) { 
            for (int k = 0; k < 4; k++) { 
                p[i][j][k] = p[i + 1][j][k]; 
            } 
        } 
    } 
    count--; 
} 

void resetgame() {
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            arr[i][j] = 0; 
        } 
    } 
    system("cls"); 
    score = 0; 
    addrandomno(); 
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
