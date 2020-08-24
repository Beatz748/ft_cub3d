# include "get_next_line.h"
# include "minilibx/mlx.h"

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *str)
{
    ft_putstr_fd(str, 1);
}

void	ft_putendl(char const *s)
{
    ft_putstr((char *)s);
    ft_putchar('\n');
}

typedef struct		t_mlx
{
    void			*win;
    void	        *mlx;
}					t_mlx;

void    ft_scaled(void *mlx, void *win, int i, int j)
{
    int x = 0;
    int y = 0;
    i *= 25;
    j *= 25;
    while (x++ < 25)
    {
        y = 0;
        while (y++ < 25)
            mlx_pixel_put(mlx, win, j + x, i + y, 0xFFFFFF);
    }
}

void ft_draw(char **map)
{
    void *mlx = NULL;
    void *win = NULL;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "test");
    int i = 0;
    int j = 0;
    int y = 0;
    int c = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                ft_scaled(mlx, win, i, j);
            j++;
        }
        printf("%s", map[i]);
        i++;
    }
    mlx_loop(mlx);
}
void    making_mapa(t_list **mapa, int size)
{
    char **map = calloc(size + 1, sizeof(char *));
    int i;
    i = -1;
    t_list *tmp = *mapa;
    while(tmp)
    {
        map[++i] = tmp->content;
        tmp = tmp->next;
    }
    i  = -1;
    while (map[++i])
    {
        ft_putendl(map[i]);
    }
    ft_draw(map);
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *line = NULL;
    t_list *mapa = NULL;
    int ret = 0;
    while (get_next_line(fd, &line))
    {
        ft_lstadd_back(&mapa, ft_lstnew(line));
        ret++;
    }
    ret++;
    ft_lstadd_back(&mapa, ft_lstnew(line));
    making_mapa(&mapa, ret);
}