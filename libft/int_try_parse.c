/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_try_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <mcarolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:13:03 by mcarolee          #+#    #+#             */
/*   Updated: 2021/03/12 00:13:09 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_try_parse(char *str, int *out)
{
	long sign;
	long rv;

	if (!str)
		return (0);
	rv = 0;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '+' || *str == '-') ? 1 : 0;
	while ('0' <= *str && *str <= '9')
		rv = rv * 10 + sign * (*str++ - '0');
	if (*str || rv != (int)rv)
		return (0);
	*out = rv;
	return (1);
}

int	int_min(int a, int b)
{
	return (a < b ? a : b);
}

int	int_max(int a, int b)
{
	return (a > b ? a : b);
}
