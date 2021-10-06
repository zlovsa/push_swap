/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:16:38 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/12 00:47:11 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_elem(t_stack *a, int elm)
{
	static char *colors[] = {"\e[44m", "\e[42m", "\e[45m", "\e[43m",
							"\e[41m", "\e[46m", "\e[47m"};
	int			colidx;

	colidx = (elm++ * 7) / a->max;
	a->color ? ft_putstr_fd(colors[colidx], 1) : (void)a;
	while (elm--)
		ft_putchar_fd(a->color ? ' ' : '*', 1);
	a->color ? ft_putstr_fd("\e[49m", 1) : (void)a;
	ft_putchar_fd('\n', 1);
}

void	show(char *instr, t_stack *a, t_stack *b)
{
	static int	ic;
	int 		j;

	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd("instruction ", 1);
	ft_putnbr_fd(ic++, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(instr, 1);
	ft_putendl_fd("v B bottom", 1);
	j = b->count;
	while (j--)
		print_elem(a, elem(b, j));
	ft_putendl_fd("----- operating device here -----", 1);
	j = -1;
	while (++j < a->count)
		print_elem(a, elem(a, j));
	ft_putendl_fd("^ A bottom", 1);
	usleep(a->pauselen * 1000);
}

int		exec(char *instr, t_stack *a, t_stack *b)
{
	int r;

	r = ft_strcmp(instr, "sa") ? 0 : st_swap(a);
	r += ft_strcmp(instr, "sb") ? 0 : st_swap(b);
	r += ft_strcmp(instr, "ss") ? 0 : st_swap2(a, b);
	r += ft_strcmp(instr, "pa") ? 0 : st_push(a, b);
	r += ft_strcmp(instr, "pb") ? 0 : st_push(b, a);
	r += ft_strcmp(instr, "ra") ? 0 : st_rotate(a);
	r += ft_strcmp(instr, "rb") ? 0 : st_rotate(b);
	r += ft_strcmp(instr, "rr") ? 0 : st_rotate2(a, b);
	r += ft_strcmp(instr, "rra") ? 0 : st_reverse_rotate(a);
	r += ft_strcmp(instr, "rrb") ? 0 : st_reverse_rotate(b);
	r += ft_strcmp(instr, "rrr") ? 0 : st_reverse_rotate2(a, b);
	if (r && a->verbose)
		show(instr, a, b);
	return (r);
}

void	process(t_stack *a, t_stack *b)
{
	int		gnl;
	char	*line;
	int		r;

	a->verbose ? show("start", a, b) : (void)a;
	while ((gnl = get_next_line(0, &line)) > -1)
	{
		if (!gnl)
		{
			r = !ft_strcmp(line, "");
			break ;
		}
		if (!(r = exec(line, a, b)))
			break ;
		free(line);
	}
	if (gnl > -1)
		free(line);
	if (!r)
		error();
}

int		main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (!st_read(&a, argc, argv))
		return (error());
	if (!a.count)
		return (0);
	if (a.verbose)
		st_index(&a);
	st_init(&b);
	process(&a, &b);
	ft_putstr_fd(st_is_sorted(&a, &b) ? "OK\n" : "KO\n", 1);
}
