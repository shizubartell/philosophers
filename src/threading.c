/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:33:16 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 12:22:29 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
