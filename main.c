#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <raylib.h>
#include <stdbool.h>

typedef struct {
    bool flagged;
    bool isMine;
    bool hidden;
    int nearMines;
} Tile;

void initBoard(Tile (*board)[10][10]){
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++){
            (*board)[y][x] = (Tile) {false, false, false, 0};
        }
    }
}

void placeMines(Tile (*board)[10][10], int mineAmt){
    int x, y;
    
    if(mineAmt > 10*10)
        return;

    for (int i = 0; i < mineAmt; i++) {
        
        do{
            x = rand() % 10;
            y = rand() % 10;
            printf("x:%d y:%d\n", x, y);

        }while((*board)[y][x].isMine);
        
        (*board)[y][x].isMine = true;
    }
}

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 450;

    Tile gameBoard[10][10];

    InitWindow(screenWidth, screenHeight, "Minesweeper");

    SetTargetFPS(60);

    initBoard(&gameBoard);
    placeMines(&gameBoard, 5);

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (int y = 0; y < 10; y++) {
                for (int x = 0; x < 10; x++) {
                    if (gameBoard[y][x].isMine)
                        DrawRectangle(x*10, y*10, 10, 10, BLUE);
                }
            }


        EndDrawing();
    }

    CloseWindow();
}
