#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code


#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef	struct		t_pl
{
	int x;
	int y;

}		t_pl;

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

int				key_press(int keycode, t_pl *param, void *mlx)
{
	static int a = 0;

	if (keycode == KEY_W)
		param->x += 50;
	else if (keycode == KEY_Q)
		param->x -= 50;
	printf("%d", param->x);
	return (0);
}

int main()
{
	t_pl gg;
	gg.x = 50;

	gg.y = 50;
	void *mlx = NULL;
    void *win = NULL;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "test");
	//		mlx_hook(win,X_EVENT_KEY_PRESS,0, &key_press,  &gg);
	//	ft_scaled(mlx, win, gg.x, gg.y);
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &gg);
	mlx_loop(mlx);
}
