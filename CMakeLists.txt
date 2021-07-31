cmake_minimum_required(VERSION 3.19)
project(minilibx_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(minilibx_0 main.c
        libft/ft_atoi.c
        libft/ft_split.c
        src/get_next_line.c
        src/get_next_line_utils.c
        src/CreateWindow.c
        src/readmap.c
        src/draw.c
        src/fill_map.c
        )

add_library(mlx_Linux STATIC main.c)
add_library(ft STATIC main.c)

include_directories(/usr/include/X11)
include_directories(/usr/include/Xext)
include_directories(/usr/include/m)


find_library(MLX_LIB mlx_Linux minilibx)
find_library(FT_LIB ft libft)
target_link_libraries(minilibx_0 LINK_PUBLIC ${MLX_LIB} ${FT_LIB} X11 m Xext)