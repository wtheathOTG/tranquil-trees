add_library(engine
        src/core/InputMan.cpp
        include/engine/core/InputMan.h
        include/engine/core/Window.h
        src/core/Window.cpp
        include/engine/core/Renderer.h
        src/core/Renderer.cpp
        include/engine/core/Engine.h
        src/core/Engine.cpp
)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(engine PUBLIC SDL2::SDL2main SDL2::SDL2)
