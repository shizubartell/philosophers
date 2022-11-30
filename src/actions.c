/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:57:13 by abartell          #+#    #+#             */
/*   Updated: 2022/11/30 20:17:09 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	grim_reaper(t_philo *philo)
{
	pthread_mutex_lock(&philo->status->eat_mute);
	if ((get_time() - philo->last_eat_time) >= philo->status->time_to_die)
	{
		print_status(philo, "died");
		finished(philo, 1);
		pthread_mutex_unlock(&philo->status->eat_mute);
		return (1);
	}
	else if (philo->status->num_of_eat > 0 && philo->eat_times >= \
			philo->status->num_of_eat)
	{
		philo->status->full_philos++;
		if (philo->status->full_philos >= philo->status->num_of_philo)
		{
			finished(philo, 1);
			print_status(philo, "f");
			pthread_mutex_unlock(&philo->status->eat_mute);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->status->eat_mute);
	return (0);
}

int	finished(t_philo *philo, int y)
{
	pthread_mutex_lock(&philo->status->finish_mute);
	if (y)
	{
		philo->status->finish = 1;
		pthread_mutex_unlock(&philo->status->finish_mute);
		return (1);
	}
	if (philo->status->finish)
	{
		pthread_mutex_unlock(&philo->status->finish_mute);
		return (1);
	}
	pthread_mutex_unlock(&philo->status->finish_mute);
	return (0);
}
