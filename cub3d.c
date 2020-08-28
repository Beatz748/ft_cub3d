#include "cub3d.h"


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
                ft_scaled(p->mlx, p->win, i, j);
            else if (map[i][j] == 'N')
            {
                p->x = i;
                p->y = j;
            }
            j++;
        }
        i++;
    }
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    t_param p;

    mlx = mlx_init();
    p.width = 640;
    p.height = 480;
    	param_init(&p);
    p.mlx = mlx_init();
    p.win = mlx_new_window(p.mlx, 640, 480, "mlx_project");
    int fd = open("txt.txt", O_RDONLY);
    char *line = NULL;
    t_list *mapa = NULL;
    int ret = 0;
    while (get_next_line(fd, &line))
    {
        ft_lstadd_back(&mapa, ft_lstnew(line));
    }
    ft_lstadd_back(&mapa, ft_lstnew(line));
    making_mapa(&mapa, ret, &p);
    // img.img = mlx_new_image(mlx, p.width, p.width);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                              &img.endian);
    // my_mlx_pixel_put(&img, 55, 55, 0x00FFFFFF);
    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}