/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:25:49 by abartell          #+#    #+#             */
/*   Updated: 2022/11/25 08:11:26 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	check_eat_times(t_status *status, t_philo *philo, int *count)
{
	if (status->num_of_eat == 0)
		return (false);
	if (philo->eat_times == status->num_of_eat)
		(*count)++;
	if (*count == status->num_of_philo && status->num_of_philo != 1)
		return (true);
	return (false);
}

void	*grim_reaper(void *arg)
{
	int				i;
	int				count;
	t_status		*status;
	size_t			now;

	status = (t_status *)arg;
	while (1)
	{
		count = 0;
		i = -1;
		while (++i < status->num_of_philo)
		{
			now = get_timestamp();
			if (now > status->philo[i].last_eat_time
				&& now - status->philo[i].last_eat_time > status->time_to_die)
			{
				print_act(DIE, &status->philo[i], status);
				status->flagbreak = true;
				return (NULL);
			}
			if (check_eat_times(status, &status->philo[i], &count))
				return (NULL);
		}
	}
	return (NULL);
}
