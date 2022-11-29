/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:33:16 by abartell          #+#    #+#             */
/*   Updated: 2022/11/25 08:20:40 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// creating a thread for the number of philos
// that are sitting at the table. 
bool	thread_num_of_philo(t_status *status)
{
	int		i;

	i = 0;
	while (i < status->num_of_philo)
	{
		if (pthread_create(&status->philo[i].th, NULL,
				&daily_life, &status->philo[i]))
			return (false);
		status->philo[i].last_eat_time = get_timestamp();
		i++;
	}
	return (true);
}

// initializing a mutex for the number of
// forks the philos are going to use
bool	mutex_num_of_fork(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_of_philo)
	{
		if (pthread_mutex_init(&status->fork[i], NULL))
			return (false);
		i++;
	}
	if (pthread_mutex_init(&status->print, NULL))
		return (false);
	return (true);
}

// initializing a mutex, if its not our
// fork mutex it returns false, otherwise true
bool	init_mutex(t_status *status)
{
	if (!mutex_num_of_fork(status))
		return (false);
	return (true);
}
