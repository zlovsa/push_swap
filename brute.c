/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 01:43:13 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/10 02:41:48 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	seq_apply(t_stack *a, t_stack *b, char *seq, int len)
{
	int i;

	i = -1;
	while (++i < len)
		exec_op(seq[i], a, b, 0);
}

void	seq_init(char *seq, int len)
{
	int i;

	i = -1;
	while (++i <= len)
		seq[i] = 0;
}

void	seq_next(char *seq)
{
	int i;

	i = 0;
	seq[0]++;
	while (seq[i] == OP_SB)
	{
		seq[i] = OP_SA;
		seq[++i]++;
	}
}

int		brute(t_stack *o)
{
	t_stack a;
	t_stack b;

	o->ccnt = -1;
	while (++o->ccnt < 9)
	{
		seq_init(o->commands, o->ccnt);
		while (!o->commands[o->ccnt])
		{
			st_copy(&a, o);
			st_init(&b);
			seq_apply(&a, &b, o->commands, o->ccnt);
			if (st_is_sorted(&a, &b))
				return (o->ccnt);
			seq_next(o->commands);
		}
	}
	o->ccnt = 0;
	return (-1);
}
