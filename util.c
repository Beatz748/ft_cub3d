#include "cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void			param_init(t_param *p)
{
	p->x = 90;
	p->y = 90;
	p->dir = PI/2;
}

void    making_mapa(t_list **mapa, int size, t_param *p)
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
    ft_draw(map, p);
}