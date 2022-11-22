/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:25:49 by abartell          #+#    #+#             */
/*   Updated: 2022/11/22 11:08:17 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	check_dinnertime(t_info *info, t_dinner *philo, int *count)
{
	if (info->nb_eaten == 0)
		return (false);
	if (philo->nb_meals == info->nb_eaten)
		(*count)++;
	if (*count == info->nb_philos && info->nb_philos != 1)
		return (true);
	return (false);	
}

void	death_counter(void *arg)
{
	int			i;
	int			count;
	t_info		*info;
	size_t		now;

	info = (t_info *)arg;
	while (1)
	{
		count = 0;
		i = -1;
		while (++i < info->nb_philos)
		{
			now = get_timestamp();
			if (now > info->philo[i].last_dinnertime && \
				now - info->philo[i].last_dinnertime > info->time_to_die)
			{
				print_act(DIE, &info->philo[i], info);
				info->flagbreak = true;
				return (NULL);
			}
			if (check_dinnertime(info, &info->philo[i], &count))
				return (NULL);
		}
	}
	return (NULL);
}