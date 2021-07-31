#include "get_next_line.h"

static void	ft_free_null(char **s)
{
	free(*s);
	*s = NULL;
}

static int	read_error_check(int fd, char **line)
{
	int		a;
	char	zero_buf[1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (1);
	a = read(fd, zero_buf, 0);
	if (a == -1)
		return (1);
	return (0);
}

/* return ptr to NL in remainder or NULL */
static char	*check_remainder(char **line, char **remainder)
{
	char	*ptr_n;
	char	*tmp;

	ptr_n = NULL;
	if (!(*remainder))
	{
		*line = f_strdup("");
		return (NULL);
	}
	ptr_n = f_strchr(*remainder, '\n');
	if (ptr_n == NULL)
	{
		*line = f_strdup(*remainder);
		ft_free_null(remainder);
	}
	else
	{
		*ptr_n = '\0';
		*line = f_strdup(*remainder);
		tmp = *remainder;
		*remainder = f_strdup(++ptr_n);
		free(tmp);
		tmp = NULL;
	}
	return (ptr_n);
}

static void	gnl_strjoin(char **line, char *buf)
{
	char	*tmp;

	tmp = f_strdup(*line);
	ft_free_null(line);
	*line = f_strjoin(tmp, buf);
	ft_free_null(&tmp);
}

int	get_next_line(int fd, char **line)
{
	static char		*remainder;
	char			buf[BUFFER_SIZE + 1];
	int				read_buf;
	char			*ptr_n;

	if (read_error_check(fd, line))
		return (READ_ERROR);
	ptr_n = check_remainder(line, &remainder);
	read_buf = 1;
	while (!ptr_n && read_buf)
	{
		read_buf = read(fd, buf, BUFFER_SIZE);
		buf[read_buf] = '\0';
		ptr_n = f_strchr(buf, '\n');
		if (ptr_n)
		{
			*ptr_n = '\0';
			if (*(ptr_n + 1) != '\0')
				remainder = f_strdup(++ptr_n);
		}
		gnl_strjoin(line, buf);
	}
	if (!read_buf && !ptr_n)
		return (READ_EOF);
	return (READ_SUCCESS);
}
