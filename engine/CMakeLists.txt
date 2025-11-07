add_library(engine
        src/core/InputMan.cpp
)

# Make headers available to anything linking against engine
target_include_directories(engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# (Optional) Link SDL2 or other libs here
# find_package(SDL2 CONFIG REQUIRED)
# target_link_libraries(engine PUBLIC SDL2::SDL2 SDL2::SDL2main)