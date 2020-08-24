/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <marvin@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 22:38:14 by kshantel          #+#    #+#             */
/*   Updated: 2020/05/30 18:21:28 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	words_count(char const *s, char c)
{
	size_t	i;
	int		ans;

	i = 0;
	ans = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ans++;
		i++;
	}
	return (ans);
}

static void	*ft_free(void **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	int		len1;
	int		len2;
	char	**tab;

	if (!s)
		return (NULL);
	len1 = words_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (len1 + 1))))
		return (NULL);
	i = 0;
	while (len1-- > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		len2 = word(s, c);
		if (!(tab[i] = (char *)malloc((len2 + 1) * sizeof(char))))
			return (ft_free((void **)tab, i));
		tab[i] = ft_memcpy(tab[i], s, len2);
		tab[i][len2] = '\0';
		s += len2;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
