/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 01:46:17 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/10 02:34:55 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	aidx_to_merge(t_stack *a, int elm)
{
	int idx;

	if (a->count < 2)
		return (0);
	idx = 0;
	if (elm < elem(a, min_idx(a)) || elm > elem(a, max_idx(a)))
		idx = min_idx(a);
	else
		while (elem(a, idx - 1) > elm || elm > elem(a, idx))
			idx++;
	return (idx);
}

int	rotates_to_merge(t_stack *a, t_stack *b, int bidx)
{
	int aidx;
	int ra;
	int rb;

	aidx = aidx_to_merge(a, elem(b, bidx));
	ra = int_min(aidx, a->count - aidx);
	rb = int_min(bidx, b->count - bidx);
	if ((a->count - 2 * aidx) * (b->count - 2 * bidx) > 0)
		return (int_max(ra, rb));
	return (ra + rb);
}

int	bidx_to_merge(t_stack *a, t_stack *b)
{
	int i;
	int min_idx;
	int min_rotates;
	int rotates;

	min_rotates = a->count + b->count;
	i = -1;
	while (++i < b->count)
		if ((rotates = rotates_to_merge(a, b, i)) < min_rotates)
		{
			min_idx = i;
			min_rotates = rotates;
		}
	return (min_idx);
}
