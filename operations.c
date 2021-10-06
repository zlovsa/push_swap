/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 02:01:43 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/10 02:42:35 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_op(char op, t_stack *a, t_stack *b, int save)
{
	op == OP_SA ? st_swap(a) : (void)op;
	op == OP_PA ? st_push(a, b) : (void)op;
	op == OP_PB ? st_push(b, a) : (void)op;
	op == OP_RA ? st_rotate(a) : (void)op;
	op == OP_RRA ? st_reverse_rotate(a) : (void)op;
	op == OP_SB ? st_swap(b) : (void)op;
	op == OP_RB ? st_rotate(b) : (void)op;
	op == OP_RRB ? st_reverse_rotate(b) : (void)op;
	op == OP_SS ? st_swap2(a, b) : (void)op;
	op == OP_RR ? st_rotate2(a, b) : (void)op;
	op == OP_RRR ? st_reverse_rotate2(a, b) : (void)op;
	if (save)
		a->commands[a->ccnt++] = op;
}

void	rotate(t_stack *a, t_stack *b, int aidx, int bidx)
{
	int ra;
	int rb;
	int rr;

	ra = int_min(aidx, a->count - aidx);
	rb = int_min(bidx, b->count - bidx);
	rr = (a->count - 2 * aidx) * (b->count - 2 * bidx) > 0
			? int_min(ra, rb) : 0;
	ra -= rr;
	rb -= rr;
	while (rr--)
		exec_op(aidx < a->count - aidx ? OP_RR : OP_RRR, a, b, 1);
	while (rb--)
		exec_op(bidx < b->count - bidx ? OP_RB : OP_RRB, a, b, 1);
	while (ra--)
		exec_op(aidx < a->count - aidx ? OP_RA : OP_RRA, a, b, 1);
}

void	seq_print(char *seq, int len)
{
	static char	*ins[] = {"sa", "pa", "pb", "ra", "rra",
						"sb", "rb", "rrb", "ss", "rr", "rrr"};
	int			i;

	i = -1;
	while (++i < len)
		ft_putendl_fd(ins[(int)seq[i]], 1);
}
