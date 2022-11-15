/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:13:04 by abartell          #+#    #+#             */
/*   Updated: 2022/11/15 11:49:57 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// using to represent the time using the struct timeval
// which represents an elapsed time
// with tv_sec for number of whole seconds of elapsed time
// and tv_usec number of microseconds of rest of elapsed time minus tv_sec
size_t	get_timestamp(void)
{
	size_t	timestamp;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	timestamp = tv.tv_sec * 10000 + tv.tv_usec * 1000;
	return (timestamp);
}

// function thats pulling the current time with our
// get_timestamp function using usleep (from the unistd)
// which suspends execution of the called thread
// for "usec" microseconds
void	sleep_to_time(size_t time)
{
	size_t	start;

	start = get_timestamp();
	while (get_timestamp() - start < time)
		usleep(10);
}

// isnum from our libft for later usage to go through the
// input of arguements and to be able to check them 
int	ft_isnum(char const *str)
{
	if (*str == '-' || *str == '+')
		str++;
	else if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}