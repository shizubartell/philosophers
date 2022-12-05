/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:24:54 by abartell          #+#    #+#             */
/*   Updated: 2022/12/05 10:42:47 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// using atoi to convert the information strings into
// integers to be used for the input
// giving an error if wrong input is given (like - values)
int	setup_info(t_info *info, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (print_error("Error!\nArgc is not 5, 6!\n"));
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (info->num_philo < 1 || info->time_to_die < 1 || \
			info->time_to_eat < 1 || info->time_to_sleep < 1)
		return (print_error("Error!\nWrong Input!\n"));
	if (ac == 6)
	{
		info->num_must_eat = ft_atoi(av[5]);
		if (info->num_must_eat < 1)
			return (print_error("Error!\nWrong Input!\n"));
	}
	else
		info->num_must_eat = -1;
	info->finish = 0;
	return (0);
}

// mallocing the memory for the philo and fork usage
// adding a timestamp and in general setting up the
// philosophers info with id, forks, meal count, info
// and last time they have eaten
// returns an error if the memory cant be allocated
int	setup_philos(t_info *info)
{
	int	i;

	i = -1;
	info->philo = malloc(sizeof(t_philo) * info->num_philo);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	info->start_time = get_timestamp();
	if (!info->philo || !info->fork)
		return (print_error("Error!\nPhilo Malloc!\n"));
	while (++i < info->num_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->num_philo;
		info->philo[i].meal_count = 0;
		info->philo[i].last_eat_time = info->start_time;
		info->philo[i].info = info;
	}
	return (0);
}

// error returns if the setup for the
// different mutexes is wrong
int	setup_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (print_error("Error!\nNo init forks!\n"));
	}
	if (pthread_mutex_init(&info->print_mutex, NULL))
		return (print_error("Error!\nNo init printmute!\n"));
	if (pthread_mutex_init(&info->eat_mutex, NULL))
		return (print_error("Error!\nNo init eatmute!\n"));
	if (pthread_mutex_init(&info->finish_mutex, NULL))
		return (print_error("Error!\nNo init finishmute!\n"));
	return (0);
}

// function to overall create the philo thread 
int	create_philos(t_info *info)
{
	int	i;

	i = -1;
	if (info->num_philo == 1)
	{
		print_status(&info->philo[0], "has taken a fork");
		sleeping(&info->philo[0], info->time_to_die);
		print_status(&info->philo[0], "died");
		check_finish(&info->philo[0], 1);
		return (0);
	}
	while (++i < info->num_philo)
	{
		if (pthread_create(&info->philo[i].thread, NULL, philostarter, \
			&(info->philo[i])))
			return (print_error("Error!\nNo threadcreating!\n"));
	}
	return (0);
}
