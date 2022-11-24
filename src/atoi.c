/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:01:39 by abartell          #+#    #+#             */
/*   Updated: 2022/11/22 13:01:55 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_overflow(int minus)
{
	if (minus > 0)
		return ((int)LONG_MAX);
	return ((int)LONG_MIN);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				minus;
	long long		num;

	i = 0;
	num = 0;
	minus = 1;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (num > LONG_MAX / 10 || (num == (LONG_MAX / 10)
				&& str[i] - '0' > (LONG_MAX % 10)))
			return (ft_overflow(minus));
		num = 10 * num + (str[i] - '0');
		i++;
	}
	return ((int)num * minus);
}