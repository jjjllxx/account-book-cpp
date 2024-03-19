cmake_minimum_required(VERSION 3.21)
project(ABC)

find_package(SQLite3 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wno-pragmas -Wno-comment")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TARGET account)
set(SOURCES
    Initialisation.cpp
    main.cpp
)

set(LIBS 
    SQLite::SQLite3)

add_executable(${TARGET} ${SOURCES})

target_link_libraries(${TARGET} ${LIBS})

set_target_properties(${TARGET} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")