
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "raylib.h"
#include "clay_renderer_raylib.c"
//#include <stdio.h>



int main (void){

    const Font defaultFont = GetFontDefault();

    Clay_Raylib_Initialize(1024, 768, "Test",FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    u_int64_t clayRequiredMemory = Clay_MinMemorySize();
    Clay_Arena clayMemory = (Clay_Arena){
        .memory = malloc(clayRequiredMemory),
        .capacity = clayRequiredMemory
    };

    Clay_Initialize(clayMemory, (Clay_Dimensions){ 1024,768}, (Clay_ErrorHandler){Clay__ErrorHandlerFunctionDefault});


    while(!WindowShouldClose()){

    Clay_BeginLayout();



    Clay_RenderCommandArray clay_RenderCommands = Clay_EndLayout();
    

    BeginDrawing();
    ClearBackground(BLACK);
    Clay_Raylib_Render(clay_RenderCommands, &defaultFont);

    
    EndDrawing();
    

    

};
Clay_Raylib_Close();

return 0;

    
}
