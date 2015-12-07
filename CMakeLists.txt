project(Super-MLG-Bros)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
include_directories(include)
add_executable(${PROJECT_NAME} ${SRC_LIST}
            include/MainMenu.h
            src/MainMenu.cpp
            src/main.cpp)
find_library(SFML_WINDOW libsfml-window.so /usr/lib)
find_library(SFML_SYSTEM libsfml-system.so /usr/lib)
find_library(SFML_GRAPHICS libsfml-graphics.so /usr/lib)
find_library(SFML_AUDIO libsfml-audio.so /usr/lib)
TARGET_LINK_LIBRARIES(Super-MLG-Bros ${SFML_WINDOW})
TARGET_LINK_LIBRARIES(Super-MLG-Bros ${SFML_SYSTEM})
TARGET_LINK_LIBRARIES(Super-MLG-Bros ${SFML_GRAPHICS})
TARGET_LINK_LIBRARIES(Super-MLG-Bros ${SFML_AUDIO})
file(COPY res DESTINATION .)
