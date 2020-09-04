#include "cub3d.h"

void  ft_init(t_param *p)
{
	p->posX = -1;
	p->posY = 0;
	p->mlx = mlx_init();
	p->win = 0;
	p->F = -1;
	p->C = -1;
	p->scW = -1;
	p->scH = -1;
  	p->planeX = 0;
  	p->planeY = 0.66;
}

void	ft_check_orientation(t_param *p, char *line)
{
	if ((ft_strchr(line, 'S')))
	{
		p->dirX = 1;
		p->planeY = -0.66;
	}
	if ((ft_strchr(line, 'E')))
	{
		p->dirX = 0;
		p->dirY = 1;
		p->planeX = 0.66;
		p->planeY = 0;
	}
	if ((ft_strchr(line, 'W')))
	{
		p->dirX = 0;
		p->dirY = -1;
		p->planeX = -0.66;
		p->planeY = 0;
	}
}

char   **making_mapa(t_list **mapa, int size, t_param *p)
{
    char **map = calloc(size + 1, sizeof(char *));
    int i;
    i = -1;
    t_list *tmp = *mapa;
    while(tmp)
    {
		ft_check_orientation(p, tmp->content);
        map[++i] = tmp->content;
        tmp = tmp->next;
    }
	return (map);
}
void	ft_image(t_param *p)
{
	int x;
	t_data img;

	x = 0;
      img.img = mlx_new_image(p->mlx, p->scW, p->scH);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
  while(x < p->scW)
  {
	p->camera = 2 * x / (double)p->scW - 1 ;
	p->rayDirX = p->dirX + p->planeX * p->camera;
	p->rayDirY = p->dirY + p->planeY * p->camera;
  }
}
int main()
{
	t_param p;
	char *line;
	int fd;
	t_list *mapa;
	char	**map;

	ft_init(&p);
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!(ft_checking_all(&p)))
		{
			ft_parser(&p, line);
			free(line);
		}
		else
			ft_lstadd_back(&mapa, ft_lstnew(line));
	}
	free(line);
	map = making_mapa(&mapa, ft_lstsize(mapa), &p);
	p.win = mlx_new_window(p.mlx, p.scW, p.scH, "cub3d");
    mlx_hook(p.win, X_EVENT_KEY_PRESS, 0, &ft_change_dir, &p);
  	mlx_loop_hook(p.mlx, &ft_render, &p);
    mlx_loop(p.mlx);
	return (0);
}
