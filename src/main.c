
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "raylib.h"
#include "clay_renderer_raylib.c"
#include "AES.h"
//#include <stdio.h>
#define BLUE {50, 76, 168,255}
#define GREEN {62, 168, 50,255}
#define GREY {100, 93, 105, 255}
#define WHITE {255, 255, 255, 255}

int main (void){
    const Font defaultFont = GetFontDefault();

    Clay_Raylib_Initialize(1024, 768, "Test",FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    u_int64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayArena = Clay_CreateArenaWithCapacityAndMemory(clayRequiredMemory, malloc(clayRequiredMemory));
    

    Clay_Initialize(clayArena, (Clay_Dimensions){ 1024,768}, (Clay_ErrorHandler){Clay__ErrorHandlerFunctionDefault});

    while(!WindowShouldClose()){

    Clay_BeginLayout();

        
    CLAY({
        .id = CLAY_ID("OuterContainer"), 
        .layout = { .sizing = {CLAY_SIZING_GROW(0), CLAY_SIZING_GROW(0)}, 
        .padding = CLAY_PADDING_ALL(60)}, 
        .backgroundColor = BLUE }) {
        
        CLAY({
                .id = CLAY_ID("Header"),
                .layout = {
                .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_FIXED(60) }, 
                .padding = CLAY_PADDING_ALL(16), 
                .childGap = 16 },
                
                .cornerRadius = CLAY_CORNER_RADIUS(10),
                .backgroundColor = GREEN
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
            .layout = {.sizing = {CLAY_SIZING_FIT(0), CLAY_SIZING_PERCENT(10)}, },
            .backgroundColor = WHITE
        }){}
        
        CLAY({
            .id = CLAY_ID("InputField"),
            .layout = {.sizing = {CLAY_SIZING_FIT(0), CLAY_SIZING_PERCENT(10)}, CLAY_BORDER_ALL(10)},
            .backgroundColor = WHITE
        }){}
        CLAY({
            .id = CLAY_ID("EncryptedText"),
            .layout = {.sizing = {CLAY_SIZING_FIT(0), CLAY_SIZING_PERCENT(10)}, },
            .backgroundColor = WHITE
        }){}
    }




    Clay_RenderCommandArray clay_RenderCommands = Clay_EndLayout();
    
    
    BeginDrawing();
    ClearBackground(BLACK);
    Clay_Raylib_Render(clay_RenderCommands, &defaultFont);

    
    EndDrawing();
    
    

};


Clay_Raylib_Close();

return 0;    
}


void calculateAES256(){

}