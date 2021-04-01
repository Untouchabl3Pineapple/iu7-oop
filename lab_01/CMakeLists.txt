cmake_minimum_required(VERSION 3.5)

project(lab_01 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_PREFIX_PATH /usr/local/opt/qt5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCE_DIR src)
set(INCLUDE_DIR include)
set(UI_DIR ui)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_DIR}/${UI_DIR})

add_definitions(-Wall -Wextra)

set(PROJECT_SOURCES
        ${SOURCE_DIR}/main.cpp

        ${SOURCE_DIR}/${UI_DIR}/mainwindow.cpp
        ${SOURCE_DIR}/${UI_DIR}/mainwindow.ui
        ${SOURCE_DIR}/${UI_DIR}/mainwindow.h
        ${SOURCE_DIR}/${UI_DIR}/draw.cpp
        ${SOURCE_DIR}/${UI_DIR}/draw.h

        ${SOURCE_DIR}/memory.cpp
        ${SOURCE_DIR}/model.cpp
        ${SOURCE_DIR}/handlers.cpp
        ${SOURCE_DIR}/points.cpp

        ${INCLUDE_DIR}/memory.h
        ${INCLUDE_DIR}/model.h
        ${INCLUDE_DIR}/handlers.h
        ${INCLUDE_DIR}/model_struc.h
        ${INCLUDE_DIR}/points.h
        ${INCLUDE_DIR}/ret_codes.h
)

add_executable(lab_01 ${PROJECT_SOURCES})

target_link_libraries(lab_01 Qt5::Widgets)