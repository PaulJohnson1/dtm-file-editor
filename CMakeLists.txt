cmake_minimum_required(VERSION 3.5.0)
project(TAS-Input-GUI)

set(SRCS
    src/DTM/BinaryFormat/File.cc
    src/DTM/BinaryFormat/Header.cc
    src/DTM/Reader.cc
    src/DTM/Writer.cc
    src/GUI/MainWindow.cc
    src/main.cc)

include_directories(include)

set(CMAKE_INCLUE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(CMAKE_AUTOMOC ON)

add_executable(TAS-Input-GUI ${SRCS})

target_link_libraries(TAS-Input-GUI Qt5::Widgets)
target_link_libraries(TAS-Input-GUI Qt5::Gui)
target_link_libraries(TAS-Input-GUI Qt5::Core)
