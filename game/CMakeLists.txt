add_executable(tranquil_trees main.cpp)
target_link_libraries(tranquil_trees PRIVATE engine)

# now this works because SDL2::SDL2 exists
add_custom_command(TARGET tranquil_trees POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:SDL2::SDL2>"
        $<TARGET_FILE_DIR:tranquil_trees>)
