/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:23:53 by kshantel          #+#    #+#             */
/*   Updated: 2020/10/11 16:37:07 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_checking_all(t_info *p)
{
	if (p->tex[0].img && p->tex[1].img && p->tex[2].img\
	&& p->tex[3].img && p->tex[4].img\
	&& p->sch != -1 && p->scw != -1 && (int)(p->f) != -1 && (int)(p->c) != -1)
		return (1);
	return (0);
}

int		ft_parser(t_info *p, char *line)
{
	if (line[0] == 'R')
		ft_parse_resolution(p, line);
	else if (line[0] == 'F')
		ft_parse_floor(p, line);
	else if (line[0] == 'C')
		ft_parse_ceil(p, line);
	else if (line[0] == 'N' && line[1] == 'O')
		ft_parse_no(p, line);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_parse_so(p, line);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_parse_we(p, line);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_parse_ea(p, line);
	else if (line[0] == 'S' && line[1] == ' ')
		ft_parse_sp(p, line);
	return (0);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	while (*lst)
	{
		list = *lst;
		*lst = (*lst)->next;
		if (del)
			del(list->content);
		free(list);
	}
	*lst = NULL;
}

void	ft_start_parsing(int fd, t_info *p)
{
	char	*line;
	t_list	*map;

	ft_initialization(p);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!(ft_checking_all(p)))
		{
			ft_parser(p, line);
			free(line);
		}
		else
			ft_lstadd_back(&map, ft_lstnew(line));
	}
	free(line);
	if ((get_next_line(fd, &line)) < 1 && !(ft_checking_all(p)))
		ft_error(2);
	free(line);
	p->map = making_map(map, p);
	ft_lstclear(&map, *free);
}
