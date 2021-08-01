#include "include/fdf.h"

int main(int argc, char **argv) {
    t_map   myMap;
    int     fd;
    void *mlx;
    void *window;

   // if (argc < 2)
	//	return (-1);
	//fd = open("/home/svirgil/Desktop/minilibx_0/maps/42.fdf", O_RDONLY);
	fd = open("maps/42.fdf", O_RDONLY);
    if (fd > 0)
        read_file(fd, &myMap);
    else
	{
		printf("Cannot open file\n");
		return (-1);
	}
    close(fd);

    //fd = open("/home/svirgil/Desktop/minilibx_0//maps/42.fdf", O_RDONLY);
	fd = open("maps/42.fdf", O_RDONLY);
    if (fd > 0)
        fill_map(fd, &myMap);
    else
	{
		printf("Cannot open file\n");
		return (-1);
	}
    close(fd);

    myCreateWindow(mlx, window, &myMap);
	//mlx_key_hook(myMap.window, deal_key, &myMap);

    return 0;
}
