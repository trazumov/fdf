#include "../include/fdf.h"

#define MAX(a, b) ( a > b ? a : b)
#define ABS(a) (a > 0 ? a : -a)

static void set_isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos (0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    draw_line(float x, float y, float x1, float y1, void *mlx, void *win, t_map *myMap)
{
    float   deltax;
    float   deltay;
    int     max;
    int     z;
    int     z1;

    z = myMap->vals[(int)y][(int )x];
    z1 = myMap->vals[(int)y1][(int )x1];

    x = x * myMap->zoom;
    y = y * myMap->zoom;
    x1 = x1 * myMap->zoom;
    y1 = y1 * myMap->zoom;

    if (z > 0 || z1 > 0)
        myMap->color = COLOR_RED;
    else
        myMap->color = COLOR_WHITE;

    set_isometric(&x, &y, z);
    set_isometric(&x1, &y1, z1);
    x += 150;
    x1 += 150;
    y += 150;
    y1 += 150;

    deltax = x1 - x;
    deltay = y1 - y;

    max = MAX(ABS(deltax), ABS(deltay));
    deltay /= max; deltax /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(mlx, win, x, y, myMap->color);
        x += deltax;
        y += deltay;
    }
}