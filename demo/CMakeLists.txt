cmake_minimum_required(VERSION 3.2)
project(MyQCustomPlotDemo)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
  add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  add_link_options("$<$<AND:$<STREQUAL:$<CXX_COMPILER_ID>,MSVC>,$<STREQUAL:$<CONFIG>,Release>>:/SUBSYSTEM:windows;/ENTRY:mainCRTStartup>")
  add_link_options("$<$<AND:$<STREQUAL:$<CXX_COMPILER_ID>,GNU>,$<STREQUAL:$<CONFIG>,Release>>:-mwindows>")
endif()

find_package(Qt6 COMPONENTS Core Widgets UiTools QUIET)

if (NOT Qt6_FOUND)
  find_package(Qt5 COMPONENTS Core Widgets UiTools REQUIRED)
endif (NOT Qt6_FOUND)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CXX_STANDARD 11)

aux_source_directory(. DEMO_SOURCE)

if (Qt6_FOUND)
  qt_add_executable(${PROJECT_NAME} ${DEMO_SOURCE} )
else()
  add_executable(${PROJECT_NAME} ${DEMO_SOURCE})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC MyQCustomPlot)
                        
target_link_libraries(${PROJECT_NAME} PUBLIC MyQCustomPlot)