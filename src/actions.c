/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:57:13 by abartell          #+#    #+#             */
/*   Updated: 2022/11/14 13:05:27 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// boolean data type includes everything that
// is either true or false
// similar to binary (two states)
// so 0 for false and 1 for true
// to be able to use it you need the proper library for it
// <stdbool.h> and is working with the boolean logic

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
