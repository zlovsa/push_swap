/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 03:08:20 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/11 17:31:38 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# define M_ASCENDING 0
# define M_SEQUENTIAL 1

void	exec_op(char op, t_stack *a, t_stack *b, int save);
void	rotate(t_stack *a, t_stack *b, int aidx, int bidx);
void	seq_print(char *seq, int len);

void	seq_init(char *seq, int len);
void	seq_apply(t_stack *a, t_stack *b, char *seq, int len);
void	seq_next(char *seq);
int		brute(t_stack *o);

int		min_idx(t_stack *st);
int		max_idx(t_stack *st);
int		elem_idx(t_stack *st, int elm);

int		sorted_chain_len(t_stack *a, int from, int method);
int		idx_max_sorted_chain(t_stack *a, int method);
int		mark_to_move(t_stack *a, int from, int method);
void	check_sa_helps(t_stack *a, t_stack *b, int from, int method);
int		next_idx_to_move(t_stack *a, t_stack *b, int from, int method);

int		rotates_to_merge(t_stack *a, t_stack *b, int bidx);
int		aidx_to_merge(t_stack *a, int elm);
int		bidx_to_merge(t_stack *a, t_stack *b);

void	move_to_b(t_stack *a, t_stack *b, int method);
void	merge(t_stack *a, t_stack *b);
void	st_sort(t_stack *a, int method);

#endif
