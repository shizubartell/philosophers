/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:42:32 by abartell          #+#    #+#             */
/*   Updated: 2022/12/05 10:40:00 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// printing an error message while
// interating through the string
int	print_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	return (1);
}

// using a mutex to lock the status message that is supposed to
// be printed and unlocking it again after the status was
// printed to the terminal
void	print_status(t_philo *philo, const char *str)
{
	long long	t;

	pthread_mutex_lock(&philo->info->print_mutex);
	if (!check_finish(philo, 0))
	{
		t = get_timestamp() - philo->info->start_time;
		printf("%lld %d %s\n", t, philo->id, str);
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
}
