/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 03:04:07 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/10 02:35:18 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	st_swap(t_stack *st)
{
	int t;

	if (st->count < 2)
		return (1);
	t = st->stack[st->start];
	st->stack[st->start] = st->stack[(st->start + 1) % ST_LEN];
	st->stack[(st->start + 1) % ST_LEN] = t;
	return (1);
}

int	st_push(t_stack *a, t_stack *b)
{
	if (!b->count)
		return (1);
	a->start = (a->start - 1 + ST_LEN) % ST_LEN;
	a->stack[a->start] = b->stack[b->start];
	a->count++;
	b->start = (b->start + 1) % ST_LEN;
	b->count--;
	return (1);
}

int	st_rotate(t_stack *st)
{
	if (st->count < 2)
		return (1);
	st->stack[(st->start + st->count) % ST_LEN] = st->stack[st->start];
	st->start = (st->start + 1) % ST_LEN;
	return (1);
}

int	st_reverse_rotate(t_stack *st)
{
	if (st->count < 2)
		return (1);
	st->start = (st->start - 1 + ST_LEN) % ST_LEN;
	st->stack[st->start] = st->stack[(st->start + st->count) % ST_LEN];
	return (1);
}
