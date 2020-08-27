#include <stdio.h>
#include <stdlib.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <math.h>
#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code
#define PI 3.14159265358979323846
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param{
	float		x;
	float		y;
	float	    dir;
	void	    *mlx;
	void	    *win;
	char	    str[3];
}				t_param;

void			param_init(t_param *p)
{
	p->x = 90;
	p->y = 90;
	p->dir = PI/2;
	p->str[0] = 'a';
	p->str[1] = 'b';
	p->str[2] = '\0';

}

void    ft_scaled(void *mlx, void *win, int i, int j, int color)
{
    int x = 0;
    int y = 0;
    i *= 15;
    j *= 15;
    while (x++ < 15)
    {
        y = 0;
        while (y++ < 15)
            mlx_pixel_put(mlx, win, j + x, i + y, color);
    }
}

void	ft_ray4ikr(t_param *p)
{
    float c = 0;
    c = 0;
    while (c < 50)
    {
        float x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir + x1)), (p->y + c * sin(p->dir + x1)), 0x000000);
            x1 += PI/100;
        }
        x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir - x1)), (p->y + c * sin(p->dir - x1)), 0x000000);
            x1 += PI/100;
        }
        c += 0.1;
    }
    c = 0;
    p->dir -= 0.5;
    while (c < 50)
    {
        float x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir + x1)), (p->y + c * sin(p->dir + x1)), 0xFFFFFF);
            x1 += PI/100;
        }
        x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir - x1)), (p->y + c * sin(p->dir - x1)), 0xFFFFFF);
            x1 += PI/100;
        }
        c += 0.1;
    }
}

void	ft_ray4ikl(t_param *p)
{
    float c = 0;
    c = 0;
    while (c < 50)
    {
        float x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir + x1)), (p->y + c * sin(p->dir + x1)), 0x000000);
            x1 += PI/100;
        }
        x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir - x1)), (p->y + c * sin(p->dir - x1)), 0x000000);
            x1 += PI/100;
        }
        c += 0.1;
    }
    c = 0;
    p->dir += 0.5;
    while (c < 50)
    {
        float x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir + x1)), (p->y + c * sin(p->dir + x1)), 0xFFFFFF);
            x1 += PI/100;
        }
        x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir - x1)), (p->y + c * sin(p->dir - x1)), 0xFFFFFF);
            x1 += PI/100;
        }
        c += 0.1;
    }
}

void	ft_ray4ikp(t_param *p)
{
    float c = 0;
    c = 0;
    while (c < 50)
    {
        float x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir + x1)), (p->y + c * sin(p->dir + x1)), 0x000000);
            x1 += PI/100;
        }
        x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir - x1)), (p->y + c * sin(p->dir - x1)), 0x000000);
            x1 += PI/100;
        }
        c += 0.1;
    }
    c = 0;
    p->x = p->x - 5 * cos(p->dir);
    p->y = p->y - 5 * sin(p->dir);
    while (c < 50)
    {
        float x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir + x1)), (p->y + c * sin(p->dir + x1)), 0xFFFFFF);
            x1 += PI/100;
        }
        x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir - x1)), (p->y + c * sin(p->dir - x1)), 0xFFFFFF);
            x1 += PI/100;
        }
        c += 0.1;
    }
}

void	ft_ray4ikz(t_param *p)
{
    float c = 0;
    c = 0;
    while (c < 50)
    {
        float x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir + x1)), (p->y + c * sin(p->dir + x1)), 0x000000);
            x1 += PI/100;
        }
        x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir - x1)), (p->y + c * sin(p->dir - x1)), 0x000000);
            x1 += PI/100;
        }
        c += 0.1;
    }
    c = 0;
    p->x = p->x + 5 * cos(p->dir);
    p->y = p->y + 5 * sin(p->dir);
    while (c < 50)
    {
        float x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir + x1)), (p->y + c * sin(p->dir + x1)), 0xFFFFFF);
            x1 += PI/100;
        }
        x1 = 0;
        while (x1 < PI/4)
        {
            mlx_pixel_put(p->mlx, p->win, (p->x + c * cos(p->dir - x1)), (p->y + c * sin(p->dir - x1)), 0xFFFFFF);
            x1 += PI/100;
        }
        c += 0.1;
    }
}

int				key_press(int keycode, t_param *p)
{
	static int a = 0;

	if (keycode == KEY_D)
	{
		ft_ray4ikl(p);
	}
	else if (keycode == KEY_S)
	{
        ft_ray4ikp(p);
	}
	else if (keycode == KEY_A)
	{
        ft_ray4ikr(p);
	}
	else if (keycode == KEY_W)
	{
        ft_ray4ikz(p);
	}
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void ft_draw(char **map, t_param *p)
{
    int i = 0;
    int j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                ft_scaled(p->mlx, p->win, i, j, 0xFF00FF);
            j++;
        }
        printf("%s", map[i]);
        i++;
    }
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

int			main(void)
{
	t_param		p;

	param_init(&p);
    p.mlx = mlx_init();
    p.win = mlx_new_window(p.mlx, 1920, 1080, "mlx_project");
    int fd = open("txt.txt", O_RDONLY);
    char *line = NULL;
    t_list *mapa = NULL;
    int ret = 0;
    while (get_next_line(fd, &line))
    {
        ft_lstadd_back(&mapa, ft_lstnew(line));
        printf("%s", mapa->content);
        ret++;
    }
    ret++;
    ft_lstadd_back(&mapa, ft_lstnew(line));
    making_mapa(&mapa, ret, &p);
	mlx_key_hook(p.win, key_press, &p);
	mlx_loop(p.mlx);
}
