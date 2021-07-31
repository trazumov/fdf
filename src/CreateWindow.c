#include "../include/fdf.h"

static void draw_fdf(void *mlx, void *win, t_map *myMap)
{
    int x = 0;
    int y = 0;

    while (y < myMap->y_len)
    {
        x = 0;
        while (x < myMap->x_len)
        {
            if (x < myMap->x_len - 1)
                draw_line(x, y, x + 1, y, mlx, win, myMap);
            if (y < myMap->y_len - 1)
                draw_line(x, y, x, y + 1, mlx, win, myMap);
            x++;
        }
        y++;
    }
}

myCreateWindow(void *mlx, void *win, t_map *myMap)
{
    printf(" => Connection ...");
    if (!(mlx = mlx_init()))
    {
        printf(" !! KO !!\n"); return(1);
    }
    printf(" => Window1 %dx%d \"Title 1\" ...",WIN1_SX,WIN1_SY);
    if (!(win = mlx_new_window(mlx,WIN1_SX,WIN1_SY,"Title1")))
    {
        printf(" !! KO !!\n"); return (1);
    }
//    mlx_pixel_put(mlx, win, 250, 250, COLOR_RED);
//    draw_line(0, 0, 100, 100, mlx, win, myMap);

    draw_fdf(mlx, win, myMap);
    //sleep(5);
    mlx_loop(mlx);
}