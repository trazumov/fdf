#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define READ_SUCCESS 1
# define READ_EOF 0
# define READ_ERROR -1

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);

char			*f_strdup(char *s);
size_t			f_strlen(char *s);
char			*f_strjoin(char *s1, char *s2);
char			*f_strchr(char *s, int c);

#endif
