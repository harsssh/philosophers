cmake_minimum_required(VERSION 3.25)
project(philo C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(philo ${SOURCES})
target_include_directories(philo PRIVATE src)