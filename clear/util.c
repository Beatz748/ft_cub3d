#include "cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	y;
	size_t	i;
	char	*str;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	return (str);
}

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

int		ft_intlen(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					minus;
	unsigned long long	number;

	number = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number < 9223372036854775807)
			number = number * 10 + str[i++] - 48;
		if (number > 9223372036854775807 && minus < 0)
			return (0);
		else if (number > 9223372036854775807)
			return (-1);
	}
	return ((int)(number * minus));
}