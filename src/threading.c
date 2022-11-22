/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:33:16 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 13:17:51 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// creating a thread for the number of philos
// that are sitting at the table. 
bool	thread_nb_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		if (pthread_create(&info->philo[i].thr, NULL, \
				&daily_life, &info->philo[i]))
			return (false);
		info->philo[i].last_dinnertime = get_timestamp();
		i++;
	}
	return (true);
}

// initializing a mutex for the number of
// forks the philos are going to use
bool	mutex_nb_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (false) ;
		i++;
	}
	if (pthread_mutex_init(&info->print, NULL))
		return (false);
	return (true);
}

// initializing a mutex, if its not our
// fork mutex it returns false, otherwise true
bool	initialize_mutex(t_info *info)
{
	if (!mutex_nb_forks(info))
		return (false);
	return (true);
}
