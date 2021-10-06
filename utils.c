/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:23:02 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/11 18:04:24 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	st_index(t_stack *st)
{
	int idx[ST_LEN];
	int i;
	int j;
	int imin;

	i = -1;
	while (++i < st->count)
		idx[i] = -1;
	i = -1;
	while (++i < st->count)
	{
		imin = -1;
		j = -1;
		while (++j < st->count)
			if (idx[j] < 0 && (imin < 0 || st->stack[j] < st->stack[imin]))
				imin = j;
		idx[imin] = i;
	}
	i = -1;
	while (++i < st->count)
		st->stack[i] = idx[i];
}

int		st_is_sorted(t_stack *a, t_stack *b)
{
	int i;

	if (b->count)
		return (0);
	i = 0;
	while (i + 1 < a->count && elem(a, i) < elem(a, i + 1))
		i++;
	return (i + 1 == a->count || a->count < 2);
}

int		error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
	return (1);
}

char	**parse_flags(t_stack *st, int *argc, char *argv[])
{
	int j;

	j = 0;
	while (++j < *argc)
		if (!ft_strcmp("-v", argv[j]))
			st->verbose = 1;
		else if (!ft_strcmp("-c", argv[j]))
			st->color = 1;
		else if (!ft_strcmp("-m0", argv[j]))
			st->method = 0;
		else if (!ft_strcmp("-m1", argv[j]))
			st->method = 1;
		else if (ft_str_starts_with(argv[j], "-p=")
			&& int_try_parse(argv[j] + 3, &st->pauselen))
			;
		else
			break ;
	*argc -= j - 1;
	return (&argv[j - 1]);
}
