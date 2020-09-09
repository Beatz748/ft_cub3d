#include "cub3d.h"

void  ft_parse_ceil(t_param *p, char *line)
{
	int R;
	int G;
	int B;

	line++;
	while (*line == ' ' || *line == ',')
		line++;
	R = ft_atoi(line);
	line += ft_intlen(R);
	while (*line == ' ' || *line == ',')
		line++;    
	G = ft_atoi(line);
	line += ft_intlen(G);
	while (*line == ' ' || *line == ',')
		line++;
	B = ft_atoi(line);
	p->C = mlx_get_color_value(p->mlx, R*65536+G*256+B);
}

void  ft_parse_floor(t_param *p, char *line)
{
	int R;
	int G;
	int B;

	line++;
	while (*line == ' ' || *line == ',')
		line++;
	R = ft_atoi(line);
	line += ft_intlen(R);
	while (*line == ' ' || *line == ',')
		line++;    
	G = ft_atoi(line);
	line += ft_intlen(G);
	while (*line == ' ' || *line == ',')
		line++;
	B = ft_atoi(line);
	p->F = mlx_get_color_value(p->mlx, R*65536+G*256+B);
}

void  ft_parse_resolution(t_param *p, char *line)
{
	line++;
	while (*line == ' ')
		line++;
	p->scW = ft_atoi(line);
	line += ft_intlen(p->scW);
	while (*line == ' ')
		line++;
	p->scH = ft_atoi(line);
}

int	ft_checking_all(t_param *p)
{
	if (p->NO.img && p->EA.img && p->WE.img && p->SO.img && p->scH != -1 && p->scW != -1 && p->F != -1 && p->C != -1)
		return (1);
	return (0);
}
int ft_parser(t_param *p, char *line)
{
	if (line[0] == 'R')
		ft_parse_resolution(p, line);
	else if (line[0] == 'F')
		ft_parse_floor(p, line);
	else if (line[0] == 'C')
		ft_parse_ceil(p, line);
	else if (line[0] == 'N' && line[1] == 'O')
		ft_parse_NO(p, line);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_parse_SO(p, line);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_parse_WE(p, line);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_parse_EA(p, line);
	else if (line[0] == 'S' && line[1] == ' ')
		ft_parse_SP(p, line);
	if	(ft_checking_all(p))
		return (1);
	return (0);
	
}