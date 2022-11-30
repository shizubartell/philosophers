/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:56:52 by abartell          #+#    #+#             */
/*   Updated: 2022/11/30 20:10:05 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	be_free(t_status *status)
{
	free(status->philo);
	free(status->fork);
	return (0);
}

int	mutex_destroyer(t_status *status)
{
	int i;

	i = -1;
	while (++i < status->num_of_philo)
		pthread_mutex_destroy(&status->fork[i]);
	be_free(status);
	pthread_mutex_destroy(&status->print_mute);
	pthread_mutex_destroy(&status->eat_mute);
	pthread_mutex_destroy(&status->finish_mute);
	return (0);
}

void	join_destroyer(t_status *status)
{
	int	i;

	i = -1;
	while (++i < status->num_of_philo)
		pthread_join(status->philo[i].thread, NULL);
	mutex_destroyer(status);
}

void	destroyer(t_status *status)
{
	int	i;
	int	yes;

	yes = 1;
	while (yes)
	{
		i = -1;
		status->num_of_philo = 0;
		while (++i < status->num_of_philo)
		{
			if (yes && check_dead(&status->philo[i]))
				yes = 0;
		}
		usleep(10);
	}
	join_destroyer(status);
}
