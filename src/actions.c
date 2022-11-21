/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:57:13 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 09:32:10 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// boolean data type includes everything that
// is either true or false
// similar to binary (two states)
// so 0 for false and 1 for true
// to be able to use it you need the proper library for it
// <stdbool.h> and is working with the boolean logic

// function for the philos to grab a fork and lock
// it for the philo who is using it so that another
// cant access it
// flagbreak is used to store the bool true or false
// value
bool	take_forks(t_info *info, t_dinner *philo)
{
	if (info->flagbreak)
		return (false);
	pthread_mutex_lock(&info->fork[philo->left_fork]);
	print_act(FORK, philo, info);
	if (info->nb_philos == 1)
	{
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
			return (false);
	}
	pthread_mutex_lock(&info->fork[philo->right_fork]);
	print_act(FORK, philo, info);
	return (true);
}

// function to put the philos to sleep
// and sending a msg using the SLEEP define
// adding their sleep time via a different function
void	sleeping(t_info *info, t_dinner *philo)
{
	if (info->flagbreak)
		return ;
	print_act(SLEEP, philo, info);
	sleep_to_time(info->time_to_sleep);
}

bool	dinning(t_info *info, t_dinner *philo)
{
	if (info->flagbreak)
		return (false);
	print_act(DINNER, philo, info);
	philo->last_dinnertime = get_timestamp();
	philo->nb_meals++;
	sleep_to_time(info->time_to_eat);
	pthread_mutex_unlock(&info->fork[philo->left_fork]);
	pthread_mutex_unlock(&info->fork[philo->right_fork]);
	return (true);
}

void	thinking(t_info *info, t_dinner *philo)
{
	if (info->flagbreak)
		return ;
	print_act(THINK, philo, info);
}
