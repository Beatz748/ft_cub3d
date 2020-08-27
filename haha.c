#include <stdio.h>
#include <stdlib.h>
#include "minilibx/mlx.h"
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
	int		x;
	int		y;
	double	dir;
	void	*mlx;
	void	*win;
	char	str[3];
}				t_param;

void			param_init(t_param *p)
{
	p->x = 3;
	p->y = 4;
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
            mlx_pixel_put(mlx, win, i + x, j + y, color);
    }
}

void	ft_ray4ik(t_param *p)
{
	
}

int				key_press(int keycode, t_param *p)
{
	static int a = 0;

	if (keycode == KEY_D)
	{
		ft_ray4ik(p);
	}
	else if (keycode == KEY_S)
	{
	}
	else if (keycode == KEY_A)
	{
	}
	else if (keycode == KEY_W) 
	{
	}
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int			main(void)
{
	t_param		p;

	param_init(&p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, 500, 500, "mlx_project");
	mlx_key_hook(p.win, key_press, &p);
	mlx_loop(p.mlx);
}
