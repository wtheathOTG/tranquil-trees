cmake_minimum_required(VERSION 3.20)
project(tranquil_trees LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# So subdirs can find SDL2
list(APPEND CMAKE_PREFIX_PATH
        "C:/Libraries/SDL2/SDL2-devel-2.32.8-mingw/SDL2-2.32.8/x86_64-w64-mingw32"
)

# <-- Move this here
find_package(SDL2 CONFIG REQUIRED)

add_subdirectory(engine)
add_subdirectory(game)
