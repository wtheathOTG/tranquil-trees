cmake_minimum_required(VERSION 3.20)
project(tranquil_trees CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(engine)
add_subdirectory(game)

# Point CMake at your SDL2 root so it finds SDL2Config.cmake
# (or pass -DCMAKE_PREFIX_PATH="C:/Libraries/SDL2/SDL2-devel-.../x86_64-w64-mingw32")
list(APPEND CMAKE_PREFIX_PATH "C:/Libraries/SDL2/SDL2-devel-2.32.8-mingw/SDL2-2.32.8/x86_64-w64-mingw32")

find_package(SDL2 CONFIG REQUIRED)  # provides SDL2::SDL2 and SDL2::SDL2main

add_executable(tranquil_trees game/main.cpp
        engine/include/engine/core/InputMan.h
        engine/src/core/InputMan.cpp
)
target_link_libraries(tranquil_trees PRIVATE SDL2::SDL2main SDL2::SDL2)

# Copy SDL2.dll next to the exe
add_custom_command(TARGET tranquil_trees POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:SDL2::SDL2>"
        $<TARGET_FILE_DIR:tranquil_trees>)
