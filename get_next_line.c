#include "get_next_line.h"
#include "libft/libft.h"


int get_next_line(int fd, char **line)
{
    char buf[2];
    int sr;
    char *tmp;

    sr = 0;
    buf[1] = '\0';
    if (!line)
        return (-1);
    if (!(*line = malloc(1)))
        return (-1);
    **line = 0;
    while ((sr = read(fd, buf, 1)))
    {
        if (*buf != '\n')
        {
            tmp = *line;
            *line = ft_strjoin(*line, buf);
            free(tmp);
        }
        else
            break;
    }
    if (sr == -1)
        return (-1);
    if (sr == 0)
        return (0);
    return (1);
}