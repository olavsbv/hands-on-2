cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

#Project name
project(ho2_imc)

#Source files
include_directories("${PROJECT_SOURCE_DIR}")

#List sources related with CPP IMC bindings
file(GLOB_RECURSE IMC_SOURCES "${PROJECT_SOURCE_DIR}/IMC/*.cpp")
file(GLOB_RECURSE IMC_HEADERS "${PROJECT_SOURCE_DIR}/IMC/*.hpp")

# Create a (static by default) library using all of IMC sources / headers
add_library(imc ${IMC_HEADERS} ${IMC_SOURCES})

add_executable(ho2 ho2.cpp)

target_link_libraries(ho2 imc)
