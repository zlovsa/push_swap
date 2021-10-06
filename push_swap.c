/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:59:52 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/11 18:05:12 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack *a, t_stack *b, int method)
{
	int idx;
	int from;

	idx = idx_max_sorted_chain(a, method);
	from = mark_to_move(a, idx, method);
	while ((idx = next_idx_to_move(a, b, from, method)) > -1)
	{
		rotate(a, b, idx, 0);
		a->stack[a->start] -= ST_LEN;
		exec_op(OP_PB, a, b, 1);
	}
}

void	merge(t_stack *a, t_stack *b)
{
	int bidx;
	int aidx;

	while (b->count)
	{
		bidx = bidx_to_merge(a, b);
		aidx = aidx_to_merge(a, elem(b, bidx));
		rotate(a, b, aidx, bidx);
		exec_op(OP_PA, a, b, 1);
	}
}

void	st_sort(t_stack *a, int method)
{
	t_stack b;

	st_init(&b);
	move_to_b(a, &b, method);
	merge(a, &b);
	rotate(a, &b, min_idx(a), 0);
}

int		main(int argc, char *argv[])
{
	t_stack a;
	t_stack c;
	t_stack *o;

	if (!st_read(&a, argc, argv))
		return (error());
	st_index(&a);
	o = &a;
	if (brute(&a) < 0)
	{
		a.method > 0 ? st_copy(&c, &a) : (void)c;
		a.method == 0 || a.method == 2 ? st_sort(&a, M_ASCENDING) : (void)a;
		a.method > 0 ? st_sort(&c, M_SEQUENTIAL) : (void)c;
		if (a.method == 2)
			o = a.ccnt < c.ccnt ? &a : &c;
		else if (a.method == 1)
			o = &c;
	}
	seq_print(o->commands, o->ccnt);
	return (0);
}
