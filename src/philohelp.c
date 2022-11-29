/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philohelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:22:35 by abartell          #+#    #+#             */
/*   Updated: 2022/11/29 10:23:06 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

size_t	get_timestamp(void)
{
	size_t			timestamp;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (timestamp);
}

void	sleep_to_time(size_t time)
{
	size_t	start;

	start = get_timestamp();
	while (get_timestamp() - start < time)
		usleep(10);
}
