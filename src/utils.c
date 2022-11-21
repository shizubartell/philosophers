/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:13:04 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 11:47:49 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// using to represent the time using the struct timeval
// which represents an elapsed time
// with tv_sec for number of whole seconds of elapsed time
// and tv_usec number of microseconds of rest of elapsed time minus tv_sec
size_t	get_timestamp(void)
{
	size_t			timestamp;
	struct timeval	tv;

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

// simple function to see if our input is a
// digit or not
int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
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

// basic atoi function from our libft to be able to
// return the converted integral number as an int
// value
int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	neg;

	neg = 1;
	i = 0;
	result = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '+' || neg == -1)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * neg);
}
