cmake_minimum_required(VERSION 3.2)
project(MyQCustomPlot)

option(USE_OPENGL "Use OpenGL" off)
option(BUILD_DEMO "Build demo" off)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
  add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  add_link_options("$<$<AND:$<STREQUAL:$<CXX_COMPILER_ID>,MSVC>,$<STREQUAL:$<CONFIG>,Release>>:/SUBSYSTEM:windows;/ENTRY:mainCRTStartup>")
  add_link_options("$<$<AND:$<STREQUAL:$<CXX_COMPILER_ID>,GNU>,$<STREQUAL:$<CONFIG>,Release>>:-mwindows>")
endif()

find_package(Qt6 COMPONENTS Core Widgets PrintSupport QUIET)

if (NOT Qt6_FOUND)
  find_package(Qt5 COMPONENTS Core Widgets PrintSupport REQUIRED)
endif (NOT Qt6_FOUND)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CXX_STANDARD 11)

aux_source_directory(src CUSTOM_WIDGETS_SOURCE)

if (Qt6_FOUND)
    qt_add_library(${PROJECT_NAME} ${CUSTOM_WIDGETS_SOURCE})
else()
    add_library(${PROJECT_NAME} ${CUSTOM_WIDGETS_SOURCE})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC Qt::Core Qt::Widgets Qt::PrintSupport ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PUBLIC Qt::Core Qt::Widgets Qt::PrintSupport)

if (USE_OPENGL)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/freeglut)
    target_compile_definitions(${PROJECT_NAME} PUBLIC -DQCUSTOMPLOT_USE_OPENGL)
    target_link_libraries(${PROJECT_NAME} PUBLIC freeglut)
endif (USE_OPENGL)

if (BUILD_DEMO)
    add_subdirectory(demo)
endif(BUILD_DEMO)

