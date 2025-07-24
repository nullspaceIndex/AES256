
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "raylib.h"
#include "clay_renderer_raylib.c"
#include "AES.h"
//#include <stdio.h>
#define BLUE_C (Clay_Color){50, 76, 168,255}
#define GREEN_C (Clay_Color){62, 168, 50,255}
#define GREY_C (Clay_Color){100, 93, 105, 255}
#define WHITE_C (Clay_Color){255, 255, 255, 255}
#define RED_C (Clay_Color){255, 0, 0, 255}

int main (void){
    const Font defaultFont = GetFontDefault();
    SetTargetFPS(60);



    Clay_Raylib_Initialize(1024, 768, "Test",FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    u_int64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayArena = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));
    

    Clay_Initialize(clayArena, (Clay_Dimensions){1024,768}, (Clay_ErrorHandler){Clay__ErrorHandlerFunctionDefault, .userData = NULL});
    
    int i = 0;
    while(!WindowShouldClose()){
    Clay_SetLayoutDimensions((Clay_Dimensions) {GetScreenHeight(), GetScreenWidth()});
    if(i > 60){
        printf("%d, %d \n", GetScreenHeight(), GetScreenWidth());
        i = 0;
    }

    i++;

    
    

    

    Vector2 MouseVector = GetMousePosition();
    Clay_SetPointerState((Clay_Vector2) { MouseVector.x, MouseVector.y}, IsMouseButtonDown(MOUSE_BUTTON_LEFT));

    Clay_BeginLayout();
    


    CLAY({
        .id = CLAY_ID("OuterContainer"), 
        .layout = {
        .layoutDirection = CLAY_TOP_TO_BOTTOM, 
        .sizing = { .width = CLAY_SIZING_PERCENT(1), .height = CLAY_SIZING_PERCENT(1) }, 
        .padding = {.left = 16, .right = 16, .top = 8, .bottom = 8}, 
        .childGap = 16 },
                
        .backgroundColor = BLUE_C
    
        }) {

        CLAY({
            .id = CLAY_ID("Title"),
            .layout = {
            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_TOP },
            .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_FIXED(70) }, 
            .padding = CLAY_PADDING_ALL(16), 
            .childGap = 16 },
                
            .cornerRadius = CLAY_CORNER_RADIUS(10),
            .backgroundColor = WHITE_C
        }){
            CLAY_TEXT(CLAY_STRING("Clay - UI Library"), CLAY_TEXT_CONFIG({ .fontSize = 24, .textColor = RED_C}));}
        
        CLAY({
                .id = CLAY_ID("Header"),
                .layout = {
                .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_FIXED(70) }, 
                .padding = CLAY_PADDING_ALL(16), 
                .childGap = 16 },
                
                .cornerRadius = CLAY_CORNER_RADIUS(10),
                .backgroundColor = RED_C
            }) {
                CLAY({
                    .id = CLAY_ID("EncryptButton"),

                }){}
                CLAY({

                }){}
                CLAY({

                }){}    
            }
        
        CLAY({
            .id = CLAY_ID("Password"),
            .layout = {
            .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_FIXED(70) }, 
            .padding = CLAY_PADDING_ALL(16), 
            .childGap = 16 },
                
            .cornerRadius = CLAY_CORNER_RADIUS(10),
            .backgroundColor = GREEN_C
        }){}
        
        CLAY({
            .id = CLAY_ID("InputField"),
            .layout = {
            .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_FIXED(70) }, 
            .padding = CLAY_PADDING_ALL(16), 
            .childGap = 16 },
                
            .cornerRadius = CLAY_CORNER_RADIUS(10),
            .backgroundColor = GREEN_C
        }){}
        CLAY({
            .id = CLAY_ID("EncryptedText"),
            .layout = {
            .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_FIXED(70) }, 
            .padding = CLAY_PADDING_ALL(16), 
            .childGap = 16 },
                
            .cornerRadius = CLAY_CORNER_RADIUS(10),
            .backgroundColor = WHITE_C
        }){}
    }




    Clay_RenderCommandArray clay_RenderCommands = Clay_EndLayout();
    
    
    BeginDrawing();
    ClearBackground(BLACK);
    Clay_Raylib_Render(clay_RenderCommands, (Font *) &defaultFont);

    
    EndDrawing();
    
    

};


Clay_Raylib_Close();

return 0;    
}


void calculateAES256(){

}