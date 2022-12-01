/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:24:54 by abartell          #+#    #+#             */
/*   Updated: 2022/12/01 08:06:22 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	setup_philo(t_status *status)
{
	int	i;

	i = -1;
	status->philo = malloc(sizeof(t_philo) * status->num_of_philo);
	status->fork = malloc(sizeof(pthread_mutex_t) * status->num_of_philo);
	status->starttime = get_time();
	if (!status->philo || !status->fork)
		return (print_error("Error!\nNo setup malloc!\n"));
	while (++i < status->num_of_philo)
	{
		status->philo[i].id = i + 1;
		status->philo[i].left_fork = i;
		status->philo[i].right_fork = (i + 1) % status->num_of_philo;
		status->philo[i].eat_times = 0;
		status->philo[i].last_eat_time = status->starttime;
		status->philo[i].status = status;
	}
	return (0);
}

int	init_status(t_status *status, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (print_error("Error!\nArgc is not 5, 6\n"));
	status->num_of_philo = ft_atoi(argv[1]);
	status->time_to_die = ft_atoi(argv[2]);
	status->time_to_eat = ft_atoi(argv[3]);
	status->time_to_sleep = ft_atoi(argv[4]);
	if (status->num_of_philo < 1 || status->time_to_die < 1 || \
			status->time_to_eat < 1 || status->time_to_sleep < 1)
		return (print_error("Error!\nWrong Input!\n"));
	if (argc == 6)
	{
		status->num_of_eat = ft_atoi(argv[5]);
		if (status->num_of_eat < 1)
			return (print_error("Error!\nWrong Input!\n"));
	}
	else
		status->num_of_eat = -1;
	status->finish = 0;
	return (0);
}

int	initmutex(t_status *status)
{
	int	i;

	i = -1;
	while (++i < status->num_of_philo)
	{
		if (pthread_mutex_init(&status->fork[i], NULL))
			return (print_error("Error!\nFork mutex!\n"));
	}
	if (pthread_mutex_init(&status->print_mute, NULL))
		return (print_error("Error!\nPrint mutex!\n"));
	if (pthread_mutex_init(&status->eat_mute, NULL))
		return (print_error("Error!\nEat mutex!\n"));
	if (pthread_mutex_init(&status->finish_mute, NULL))
		return (print_error("Error!\nFinish mutex!\n"));
	return (0);
}
