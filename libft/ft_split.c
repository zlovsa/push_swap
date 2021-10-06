/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:01:20 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/07 21:47:25 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_alloc_for_split(const char *s, char c)
{
	int wcnt;

	if (!s)
		return (NULL);
	wcnt = 0;
	while (*s)
	{
		wcnt += (*s != c && (s[1] == c || !s[1]));
		s++;
	}
	return ((char **)malloc((wcnt + 1) * sizeof(char *)));
}

static void	*free_split_err(char **r, int wcnt)
{
	while (wcnt)
		free(r[--wcnt]);
	free(r);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		wcnt;
	int		pstate;
	char	*b;
	char	**r;

	if (!(r = ft_alloc_for_split(s, c)))
		return (r);
	wcnt = 0;
	pstate = 1;
	while (*s)
	{
		if (pstate && *s != c)
			b = (char *)s;
		else if (!pstate && *s == c)
			if (!(r[wcnt++] = ft_substr(b, 0, s - b)))
				return (free_split_err(r, wcnt));
		pstate = *s++ == c;
	}
	if (!pstate && !(r[wcnt++] = ft_substr(b, 0, s - b)))
		return (free_split_err(r, wcnt));
	r[wcnt] = NULL;
	return (r);
}

int			free_split(char **inf)
{
	int i;

	i = 0;
	while (inf[i])
		free(inf[i++]);
	free(inf);
	return (0);
}
