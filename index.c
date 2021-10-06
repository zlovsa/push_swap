/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 01:55:11 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/11 17:33:25 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min_idx(t_stack *st)
{
	int j;
	int min;

	j = 0;
	min = 0;
	while (++j < st->count)
		min = elem(st, j) < elem(st, min) ? j : min;
	return (min);
}

int		max_idx(t_stack *st)
{
	int j;
	int max;

	j = 0;
	max = 0;
	while (++j < st->count)
		max = elem(st, j) > elem(st, max) ? j : max;
	return (max);
}

int		elem_idx(t_stack *st, int elm)
{
	int i;

	i = 0;
	while (i < st->count && elem(st, i) != elm)
		i++;
	return (i == st->count ? -1 : i);
}
