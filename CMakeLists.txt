cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE  Debug)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set(LIBFT_INCLUDE_DIR libft)
set(FILLIT_INCLUDE_DIR includes/)
project(fillit)
add_subdirectory(libft)
include_directories(${LIBFT_INCLUDE_DIR})
include_directories(${FILLIT_INCLUDE_DIR})
add_executable(fillit
        src/main.c
        src/normalize
        src/solver.c
        src/map.c
        src/tetramino.c
        src/validator.c src/piece.c includes/piece.h src/cleaner.c includes/cleaner.h)
target_link_libraries(fillit libft)
ADD_DEPENDENCIES(fillit libft)
