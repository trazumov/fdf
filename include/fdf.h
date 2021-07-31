#ifndef FDF_H
#define FDF_H

#include <stdio.h> // debug
#include "../minilibx/mlx.h"
#include "../minilibx/mlx_int.h"
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "../src/get_next_line.h"
#include "../libft/libft.h"

#define	WIN1_SX     500
#define	WIN1_SY     500
#define BUFFER_SIZE 1000
#define COLOR_WHITE 0xffffff
#define COLOR_RED 0xe80c0c

typedef struct s_map
{
    int x_len;
    int y_len;
    int **vals;
    int color;
    int zoom;
}   t_map;

myCreateWindow(void *mlx, void *win, t_map *myMap);
int read_file(int fd, t_map *myMap);
void    draw_line(float x, float y, float x1, float y1, void *mlx, void *win, t_map *myMap);
void fill_map(int fd, t_map *myMap);

#endif