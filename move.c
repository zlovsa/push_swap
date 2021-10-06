/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 01:49:51 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/10 02:40:44 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sorted_chain_len(t_stack *a, int from, int method)
{
	int j;
	int last;
	int len;

	j = 0;
	last = from;
	len = 1;
	while (++j < a->count)
		if ((method == M_ASCENDING
			&& elem(a, from + j) % ST_LEN > elem(a, last) % ST_LEN)
			|| (method == M_SEQUENTIAL
			&& elem(a, from + j) % ST_LEN == elem(a, last) % ST_LEN + 1))
		{
			len++;
			last = from + j;
		}
	return (len);
}

int		idx_max_sorted_chain(t_stack *a, int method)
{
	int i;
	int max_idx;
	int max_len;
	int len;

	i = -1;
	max_len = -1;
	while (++i < a->count)
		if ((len = sorted_chain_len(a, i, method)) > max_len)
		{
			max_idx = i;
			max_len = len;
		}
	return (max_idx);
}

int		mark_to_move(t_stack *a, int from, int method)
{
	int j;
	int last;
	int elm;

	last = from;
	j = 0;
	while (++j < a->count)
	{
		elm = elem(a, from + j) % ST_LEN;
		elm += ((method == M_ASCENDING && elm < elem(a, last))
				|| (method == M_SEQUENTIAL && elm != elem(a, last) + 1))
				* ST_LEN;
		set_elem(a, from + j, elm);
		if (elm < ST_LEN)
			last = from + j;
	}
	return (elem(a, from));
}

void	check_sa_helps(t_stack *a, t_stack *b, int from, int method)
{
	int l0;
	int l1;
	int nidx;

	l0 = sorted_chain_len(a, elem_idx(a, from), method);
	exec_op(OP_SA, a, b, 0);
	nidx = elem_idx(a, from);
	l1 = sorted_chain_len(a, nidx, method);
	exec_op(OP_SA, a, b, 0);
	if (l1 > l0)
	{
		exec_op(OP_SA, a, b, 1);
		mark_to_move(a, nidx, method);
	}
}

int		next_idx_to_move(t_stack *a, t_stack *b, int from, int method)
{
	int top;
	int bottom;

	check_sa_helps(a, b, from, method);
	top = 0;
	while (top < a->count && elem(a, top) < ST_LEN)
		top++;
	if (top == a->count)
		return (-1);
	bottom = a->count - 1;
	while (bottom > -1 && elem(a, bottom) < ST_LEN)
		bottom--;
	if (int_min(top, a->count - top) > int_min(bottom, a->count - bottom))
		top = bottom;
	return (top);
}
