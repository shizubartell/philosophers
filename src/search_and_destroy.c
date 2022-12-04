/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:56:52 by abartell          #+#    #+#             */
/*   Updated: 2022/12/04 21:31:02 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	be_free(t_info *info)
{
	free(info->philo);
	free(info->fork);
	return (0);
}

int	mutex_destroyer(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_mutex_destroy(&info->fork[i]);
	be_free(info);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	pthread_mutex_destroy(&info->finish_mutex);
	return (0);
}

void	join_free_destroy(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
		pthread_join(info->philo[i].thread, NULL);
	mutex_destroyer(info);
}

void	destroyer(t_info *info)
{
	int	i;
	int	yes;

	yes = 1;
	while (yes)
	{
		i = -1;
		info->num_full_philo = 0;
		while (++i < info->num_philo)
		{
			if (yes && grim_reaper(&info->philo[i]))
				yes = 0;
		}
		usleep(10);
	}
	join_free_destroy(info);
}
