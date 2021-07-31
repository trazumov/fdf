#include "include/fdf.h"

int main() {
    void    *mlx;
    void    *win1;
    t_map   myMap;
    int     fd;

/*
    mlx_pixel_put(mlx, win1, 250, 250, COLOR_RED);
    draw_line(0, 0, 100, -100, mlx, win1);
    mlx_destroy_window(mlx, win1);
*/

    fd = open("/home/svirgil/Desktop/minilibx_0/maps/42.fdf", O_RDONLY);
    if (fd > 0)
        read_file(fd, &myMap);
    else
        printf("Cannot open file\n");
    close(fd);

    fd = open("/home/svirgil/Desktop/minilibx_0/maps/42.fdf", O_RDONLY);
    if (fd > 0)
    {
        printf("fill_map..\n");
        fill_map(fd, &myMap);
    }
    else
        printf("Cannot open file\n");
    close(fd);

    myCreateWindow(mlx, win1, &myMap);
    mlx_clear_window(mlx,win1);

    return 0;
}
