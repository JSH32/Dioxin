cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(dioxin)

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(VENDOR_DIR ${CMAKE_CURRENT_LIST_DIR}/vendor)

file(GLOB_RECURSE SRC ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.h)

add_executable(dioxin ${SRC})
target_include_directories(dioxin PUBLIC ${SOURCE_DIR})

# Resources
include(${VENDOR_DIR}/cmrc/CMakeRC.cmake)
file(GLOB_RECURSE CONTENT_FILES ${SOURCE_DIR}/content/*)
cmrc_add_resource_library(content WHENCE ${SOURCE_DIR}/content ${CONTENT_FILES})
target_link_libraries(dioxin PRIVATE content)

# Dependencies
add_subdirectory(${VENDOR_DIR}/SFML)
target_link_libraries(dioxin PUBLIC sfml-graphics)

add_subdirectory(${VENDOR_DIR}/json)
target_link_libraries(dioxin PUBLIC nlohmann_json::nlohmann_json)