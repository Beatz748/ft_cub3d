#include "cub3d.h"

t_list		*ft_lstnew(void *content)
{
    t_list	*new;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

void		ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list	*last;

    if (lst == NULL || new == NULL)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    last = ft_lstlast(*lst);
    new->next = last->next;
    last->next = new;
}

int		ft_lstsize(t_list *lst)
{
    int		count;

    count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
