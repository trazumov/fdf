#include "../include/fdf.h"

static void set_map(t_map *myMap, char *text)
{
    int i; int j;

    i = 0; j = 0;
    printf("COLUMNES: %d(19) LINES: %d(11)", myMap->x_len, myMap->y_len);
    while (i < myMap->y_len)
    {
        j = 0;
        while (j < myMap->x_len)
        {
            j++;
        }
        i++;
    }
}

static void countxy_map(t_map *myMap, char *text)
{
    int i;

    i = 0;
    myMap->y_len = 0;
    myMap->x_len = 1;
    while (text[i] != '\0')
    {
        if (text[i] == '\n')
            myMap->y_len++;
        i++;
    }
    i = 0;
    while (text[i] != '\n')
    {
        if (text[i] == ' ' && ft_isdigit(text[i + 1]))
            myMap->x_len++;
        i++;
    }
}

static void init_map(t_map *myMap)
{
    myMap->x_len = 0;
    myMap->y_len = 0;
    myMap->vals = NULL;
    myMap->color = COLOR_WHITE;
    myMap->zoom = 20;
}

int read_file(int fd, t_map *myMap)
{
    int read_line = 0;
    int read_buf;
    char buf[BUFFER_SIZE + 1];

    read_buf = read(fd, buf, BUFFER_SIZE);
    buf[read_buf] = '\0';

//    printf("%s\n", buf);

    init_map(myMap);
    countxy_map(myMap, buf);
//   set_map(&myMap, buf);

    return 0;
}