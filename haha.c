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
	void	*mlx;
	void	*win;
	char	str[3];
}				t_param;

void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
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

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_D)//Action when W key pressed
	{
		param->x += 1;
		ft_scaled(param->mlx, param->win, param->x, param->y, 0x11cff);
		ft_scaled(param->mlx, param->win, param->x - 1, param->y, 0x000000);
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		param->y += 1;
		ft_scaled(param->mlx, param->win, param->x, param->y, 0x11cff);
		ft_scaled(param->mlx, param->win, param->x, param->y - 1, 0x000000);
	}
	else if (keycode == KEY_A) //Action when S key pressed
	{
		param->x -= 1;
		ft_scaled(param->mlx, param->win, param->x, param->y, 0x11cff);
		ft_scaled(param->mlx, param->win, param->x + 1, param->y, 0x000000);
	}
	else if (keycode == KEY_W) //Action when S key pressed
	{
		param->y -= 1;
		ft_scaled(param->mlx, param->win, param->x, param->y, 0x11cff);
		ft_scaled(param->mlx, param->win, param->x, param->y + 1, 0x000000);
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	return (0);
}

int			main(void)
{
	t_param		param;

	param_init(&param);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx_project");
	mlx_key_hook(param.win, key_press, &param);
	mlx_loop(param.mlx);
}
