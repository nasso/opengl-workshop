cmake_minimum_required(VERSION 3.8)

project(workshop_opengl)
include(CheckLibraryExists)

add_subdirectory(workshop)
add_subdirectory(src)

set_target_properties(main
    PROPERTIES
        RUNTIME_OUTPUT_NAME "main"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}
        RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}
)
