cmake_minimum_required(VERSION 3.10)
project(AccountingApp)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header directory
include_directories(include)

# Automatically collect all .cpp source files
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(AccountingApp ${SOURCES})

