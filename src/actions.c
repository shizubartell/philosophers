/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:57:13 by abartell          #+#    #+#             */
/*   Updated: 2022/12/05 10:36:07 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// death-timer, comparing the time from the last time they have
// eaten to the time they can survive without food
// and returning the "died" status if they starved to death
// incrementing the number of finished philos under
// certain conditions
int	grim_reaper(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_mutex);
	if ((get_timestamp() - philo->last_eat_time) >= philo->info->time_to_die)
	{
		print_status(philo, "died");
		check_finish(philo, 1);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return (1);
	}
	else if (philo->info->num_must_eat > 0 && philo->meal_count >= \
			philo->info->num_must_eat)
	{
		philo->info->num_full_philo++;
		if (philo->info->num_full_philo >= philo->info->num_philo)
		{
			check_finish(philo, 1);
			print_status(philo, "f");
			pthread_mutex_unlock(&philo->info->eat_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->info->eat_mutex);
	return (0);
}

// locking the mutexes for the forks so the philo can eat
// after finishing eating the meal count will increase,
// getting the timestamp after and then unlocking the
// mutexes for another philo to use
static void	dinnertime(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	sleeping(philo, philo->info->time_to_eat);
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->meal_count += 1;
	philo->last_eat_time = get_timestamp();
	pthread_mutex_unlock(&philo->info->eat_mutex);
	pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
}

// checking if a philo is done with eating
int	check_finish(t_philo *philo, int yes)
{
	pthread_mutex_lock(&philo->info->finish_mutex);
	if (yes)
	{
		philo->info->finish = 1;
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return (1);
	}
	if (philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->finish_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->finish_mutex);
	return (0);
}

// starting up the philosophers routine,
// checking if the philos are already finished
// with eating and initiating the sleeping and
// thinking phases
void	*philostarter(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 1000);
	while (42)
	{
		if (check_finish(philo, 0))
			return (0);
		dinnertime(philo);
		print_status(philo, "is sleeping");
		sleeping(philo, philo->info->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (0);
}
