cmake_minimum_required(VERSION 3.10)  
project(AES256)
add_compile_options( -v)
#-fsanitize=address source/clay_renderer_raylib.c -Wall -Wextra
set(CMAKE_C_STANDARD 99)           
set(CMAKE_OSX_ARCHITECTURES "x86_64")


#Raylib
add_library(raylib STATIC lib/raylib/clay_renderer_raylib.c)



add_executable(AES256 src/main.c )

#src/multi-compilation-unit.c


target_include_directories(AES256
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    PUBLIC ${CMAKE_SOURCE_DIR}/lib/clay
    )
target_include_directories(raylib
    PUBLIC ${CMAKE_SOURCE_DIR}/lib/raylib
    PUBLIC ${CMAKE_SOURCE_DIR}/lib/clay
)
find_library(COCOA_FRAMEWORK Cocoa)
find_library(OpenGL_FRAMEWORK OpenGL)
find_library(IOKIT_FRAMEWORK IOKit)
find_library(COREVIDEO_FRAMEWORK CoreVideo)

target_compile_definitions(AES256 PUBLIC ${CMAKE_SOURCE_DIR}/lib/clay)
target_link_libraries(${PROJECT_NAME}
    PUBLIC raylib
    ${CMAKE_SOURCE_DIR}/lib/raylib/libraylib.a
    ${COCOA_FRAMEWORK}
    ${OpenGL_FRAMEWORK}
    ${IOKIT_FRAMEWORK}
    ${COREVIDEO_FRAMEWORK}
    )


