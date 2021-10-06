/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:16:53 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/11 17:33:22 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft/libft.h"
# include "limits.h"
# define ST_LEN ARG_MAX
# define OP_SA 0
# define OP_PA 1
# define OP_PB 2
# define OP_RA 3
# define OP_RRA 4
# define OP_SB 5
# define OP_RB 6
# define OP_RRB 7
# define OP_SS 8
# define OP_RR 9
# define OP_RRR 10

typedef struct	s_stack
{
	int		stack[ST_LEN];
	int		start;
	int		count;
	char	commands[ST_LEN];
	int		ccnt;
	int		verbose;
	int		color;
	int		method;
	int		pauselen;
	int		max;
}				t_stack;

void			st_init(t_stack *st);
int				st_read(t_stack *st, int argc, char *argv[]);
int				elem(t_stack *st, int idx);
void			set_elem(t_stack *st, int idx, int value);
void			st_copy(t_stack *dst, t_stack *src);

int				st_swap(t_stack *st);
int				st_push(t_stack *a, t_stack *b);
int				st_rotate(t_stack *st);
int				st_reverse_rotate(t_stack *st);

int				st_swap2(t_stack *a, t_stack *b);
int				st_rotate2(t_stack *a, t_stack *b);
int				st_reverse_rotate2(t_stack *a, t_stack *b);

int				error();
void			st_index(t_stack *st);
int				st_is_sorted(t_stack *a, t_stack *b);
char			**parse_flags(t_stack *st, int *argc, char *argv[]);

#endif
