/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:57:13 by abartell          #+#    #+#             */
/*   Updated: 2022/11/29 12:03:05 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// function to put the philos to sleep
// and sending a msg using the SLEEP define
// adding their sleep time via a different function
void	sleeping(t_status *status, t_philo *philo)
{
	if (status->flagbreak)
		return ;
	print_act(SLEEP, philo, status);
	sleep_to_time(status->time_to_sleep);
}

void	thinking(t_status *status, t_philo *philo)
{
	if (status->flagbreak)
		return ;
	print_act(THINK, philo, status);
}

void	*daily_life(void *arg)
{
	t_status	*status;
	t_philo		*philo;

	philo = (t_philo *)arg;
	status = (t_status *)philo->info;
	if (philo->id % 2 == 0)
	{
		print_act(THINK, philo, status);
		usleep(50);
	}
	while (!status->flagbreak)
	{
		if (status->num_of_eat != 0
			&& philo->eat_times == status->num_of_eat)
			return (NULL);
		if (!take_fork(status, philo))
			break ;
		if (!dinning(status, philo))
			break ;
		sleeping(status, philo);
		thinking(status, philo);
	}
	pthread_mutex_unlock(&status->fork[philo->left_fork]);
	pthread_mutex_unlock(&status->fork[philo->right_fork]);
	return (NULL);
}
