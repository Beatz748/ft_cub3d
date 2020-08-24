#include "libft/libft.h"
#include "minilibx/mlx.h"

int main(void)
{
    void *mlx = NULL;
    void *win = NULL;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "DASHA LOH");
    mlx_loop(mlx);
}