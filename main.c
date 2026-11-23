#include "include/raylib.h"


typedef struct{
    int x;
    int y;
    float radius;
}Circle;


int main(void){

    const int screenWidth = 800;
    const int screenHeight = 600;
    bool pause = true;
    float gravity = 5.6f;

    Circle player = {
        .x = 10, .y = 10, .radius = 10
    };
    
    InitWindow(screenWidth, screenHeight, "Flopped bird");
    
    SetTargetFPS(60);


    while (!WindowShouldClose()) {

        //Update
        if (IsKeyDown(KEY_ENTER)){
            if (pause) {
                pause = false; 
            }
            else {
                pause = true;
            }
        } 
        
        if (!pause) {
            player.y += gravity; 
            if (IsKeyDown(KEY_SPACE)) player.y -= 11.2f;
        }


        //draw 
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(player.x, player.y, player.radius, BLUE);

            for (int i = 0; i < 100; i++){
                DrawRectangle(i, 100, 10,100, GREEN);
        }

        EndDrawing();
    }

    return 0;
}
