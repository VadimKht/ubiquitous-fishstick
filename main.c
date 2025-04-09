#include "raylib.h"
#include<stdio.h>
#include<math.h>
#include<cstring>

char currentText[256];
void AssignText(char* text){
    strncpy(currentText, text, sizeof currentText - 1);
}
int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    Camera3D camera = { 0 };
    SetTargetFPS(30);
    camera.position = (Vector3){ -10.0f, 0.0f, 0.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 70.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
    float speed = 0.1f;
    Vector3 cubePos = {
        (float)0,
        (float)0,
        (float)0
    };
    DisableCursor();
    Vector2 mp1 = GetMousePosition();
    Vector2 mp2 = GetMousePosition();
    Vector2 CameraRotation = {0.0f, 0.0f};
    typedef struct{
        Vector3 Position;
        float size;
    } Object;
    Object scene_Objects[3] = {{{0,0,0}, 10}, {{20,0,0}, 10}, {{0,0,20}, 10}};

    while (!WindowShouldClose())
    {
        // Find mouse position difference between current and previous frame
        mp2 = GetMousePosition();
        Vector2 difference = { mp2.x - mp1.x, mp2.y - mp1.y };
        mp1 = mp2;

        CameraRotation.x += difference.x*0.01;
        CameraRotation.y -= difference.y*0.01;
        
        Vector3 TargetTemp = {-sin(CameraRotation.x/10), 0.0, cos(CameraRotation.x/10)};
        float magn = sqrt(TargetTemp.x*TargetTemp.x+TargetTemp.y*TargetTemp.y+TargetTemp.z*TargetTemp.z);
        Vector3 NormTargetTemp = {TargetTemp.x/magn, TargetTemp.y/magn, TargetTemp.z/magn};
        if (IsKeyDown(KEY_W)){
            camera.position.x += NormTargetTemp.x * speed;
            camera.position.z += NormTargetTemp.z * speed;
        }
        if (IsKeyDown(KEY_S)){
            camera.position.x -= NormTargetTemp.x * speed;
            camera.position.z -= NormTargetTemp.z * speed;
        }
        if(IsKeyDown(KEY_D)){
            camera.position.z += NormTargetTemp.x * speed;
            camera.position.x -= NormTargetTemp.z * speed;
        }
        if (IsKeyDown(KEY_A)){
            camera.position.z -= NormTargetTemp.x * speed; 
            camera.position.x += NormTargetTemp.z * speed;
        }
        if (IsKeyDown(KEY_LEFT_SHIFT)){
            speed = 2.0f;
        }
        if (IsKeyUp(KEY_LEFT_SHIFT)){
            speed = 1.0f;
        }
        
        if (IsKeyDown(KEY_SPACE)){
            camera.position.y += 1.0f;
        }
        if (IsKeyUp(KEY_SPACE) && camera.position.y > 0.0){
            camera.position.y -= 0.4f;
        }
        if (IsKeyDown(KEY_E)){
            DrawText(currentText, 0, 0, 36, RED);
            //ShowCursor();
        }
        

        Vector3 aroundCamera = {camera.position.x+NormTargetTemp.x, 
            camera.position.y+NormTargetTemp.y,
            camera.position.z+NormTargetTemp.z};

        camera.target = aroundCamera;  

    
        BeginDrawing();
            ClearBackground(RAYWHITE);        
            BeginMode3D(camera);
                for(int i = 0; i < sizeof(scene_Objects)/sizeof(scene_Objects[0]); i++)
                {
                    const float size = scene_Objects[i].size;
                    DrawCube(scene_Objects[i].Position, size, size, size, RED);
                    float distance = sqrt(pow(camera.position.x-scene_Objects[i].Position.x, 2) + 
                                            pow(camera.position.y-scene_Objects[i].Position.y, 2) + 
                                            pow(camera.position.z-scene_Objects[i].Position.z, 2));
                    // why doesnt it work right
                    if(distance < 20) AssignText("Ah! you're inside object.");
                    else AssignText("no object");
                }

            EndMode3D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
