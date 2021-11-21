#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 17
#define HEIGHT 10

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;
int x, y, score;

char map[HEIGHT][WIDTH] = {
    "################",
    "#..............#",
    "#.####.#####.#.#",
    "#.#........#.#.#",
    "#.#.######.#.#.#",
    "#.#.#....#.#.#.#",
    "#.#.#.##.#.#.#.#",
    "#.#.#.##.#.#.#.#",
    "#..............#",
    "################"
};

void setup() {
    dir = STOP;
    x = 1;
    y = 1;
    score = 0;
}

void draw() {
    system("cls");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == y && j == x) {
                printf("P");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
            case 'A':
            case 75:
                dir = LEFT;
                break;
            case 'd':
            case 'D':
            case 77:
                dir = RIGHT;
                break;
            case 'w':
            case 'W':
            case 72:
                dir = UP;
                break;
            case 's':
            case 'S':
            case 80:
                dir = DOWN;
                break;
            case 'x':
            case 'X':
                exit(0);
        }
    }
}

void logic() {
    int nextX = x;
    int nextY = y;

    switch (dir) {
        case LEFT:
            nextX--;
            break;
        case RIGHT:
            nextX++;
            break;
        case UP:
            nextY--;
            break;
        case DOWN:
            nextY++;
            break;
        default:
            break;
    }

    if (map[nextY][nextX] != '#') { 
        x = nextX;
        y = nextY;
        if (map[y][x] == '.') {
            score += 10;
            map[y][x] = ' ';
        }
    }
}

int main() {
    setup();

    while (1) {
        draw();
        input();
        logic();
        Sleep(100);
    }

    return 0;
}
