/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiliaze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:24:54 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 08:43:03 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	mem_for_infos(t_info *info)
{
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nb_philos + 1);
	if (info->fork == NULL)
		return (error_thrower(3));
	info->philo = malloc(sizeof(t_dinner) * info->nb_philos);
	if (info->philo == NULL)
	{
		free(info->fork);
		return (error_thrower(1));
	}
	return (true);
}

void	args_put_to_info(int len, char *args[], t_info *info)
{
	int	i;

	i = 0;
	info->nb_philos = ft_atoi(args[i++]);
	info->time_to_die = ft_atoi(args[i++]);
	info->time_to_sleep = ft_atoi(args[i++]);
	info->time_to_eat = ft_atoi(args[i++]);
	info->flagbreak = false;
	info->nb_eaten = 0;
	if (len == 6)
		info->nb_eaten = ft_atoi(args[i]);
}

void	set_dinner(t_info *info)
{
	int i;

	i = 0;
	while (i < info->nb_philos)
	{
		info->philo[i].id = i - 1;
		if (i == 0)
			info->philo[i].right_fork = info->nb_philos - 1;
		else
			info->philo[i].right_fork = i -1;
		info->philo[i].left_fork = i;
		info->philo[i].nb_meals = 0;
		info->philo[i].info = info;
		i++;
	}
}	