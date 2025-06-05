cmake_minimum_required(VERSION 3.10)
project(Arkanoid)

find_package(SFML REQUIRED COMPONENTS audio graphics window system)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/images" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
add_executable(arkanoid main.cpp)

target_link_libraries(arkanoid PRIVATE 
    SFML::System
    SFML::Window
    SFML::Graphics
    SFML::Audio
)
