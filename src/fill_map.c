#include "../include/fdf.h"

static void print_vals(t_map *map)
{
    int i = 0;
    int j = 0;

    while (i < map->y_len)
    {
        j = 0;
        while (j <= map->x_len)
        {
            printf("%3d", map->vals[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void fill_matrix(int *val, char *line)
{
    char **nums;
    int i = 0;

    nums = ft_split(line, ' ');
    while (nums[i])
    {
        val[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
}

void fill_map(int fd, t_map *myMap)
{
    int i = 0;
    char *line;

    myMap->vals = (int**) malloc(sizeof(int*) * (myMap->y_len + 1));
    while (i <= myMap->y_len)
        myMap->vals[i++] = (int*) malloc(sizeof(int) * (myMap->x_len + 1));
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_matrix(myMap->vals[i], line);
        free(line);
        i++;
    }
    printf("myMap->x_len = %d; myMap->y_len = %d\n", myMap->x_len, myMap->y_len);
    print_vals(myMap);
}