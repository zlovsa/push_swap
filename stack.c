/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 03:02:13 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/11 18:07:20 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	st_init(t_stack *st)
{
	st->count = 0;
	st->start = 0;
	st->ccnt = 0;
	st->pauselen = 100;
	st->verbose = 0;
	st->color = 0;
	st->method = 2;
}

int		st_read(t_stack *st, int argc, char *argv[])
{
	int		i;
	int		j;
	char	**args;

	st_init(st);
	args = parse_flags(st, &argc, argv);
	args = argc == 2 ? ft_split(args[1], ' ') : &args[1];
	i = -1;
	while (argc == 2 ? (args[++i] != NULL) : (++i + 1 < argc))
	{
		if (!int_try_parse(args[i], &(st->stack[i])))
			return (argc == 2 ? free_split(args) : 0);
		j = -1;
		while (++j < i)
			if (st->stack[j] == st->stack[i])
				return (argc == 2 ? free_split(args) : 0);
	}
	st->count = i;
	st->max = i;
	return (1 + (argc == 2 ? free_split(args) : 0));
}

int		elem(t_stack *st, int idx)
{
	return (st->stack[(st->start + (idx + st->count) % st->count) % ST_LEN]);
}

void	set_elem(t_stack *st, int idx, int value)
{
	st->stack[(st->start + (idx + st->count) % st->count) % ST_LEN] = value;
}

void	st_copy(t_stack *dst, t_stack *src)
{
	int i;

	dst->start = 0;
	dst->count = src->count;
	i = -1;
	while (++i < src->count)
		dst->stack[i] = src->stack[i];
}
