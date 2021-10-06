/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 02:26:17 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/10 02:33:19 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	st_swap2(t_stack *a, t_stack *b)
{
	st_swap(a);
	st_swap(b);
	return (1);
}

int	st_rotate2(t_stack *a, t_stack *b)
{
	st_rotate(a);
	st_rotate(b);
	return (1);
}

int	st_reverse_rotate2(t_stack *a, t_stack *b)
{
	st_reverse_rotate(a);
	st_reverse_rotate(b);
	return (1);
}
