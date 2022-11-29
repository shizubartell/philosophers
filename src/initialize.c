/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:24:54 by abartell          #+#    #+#             */
/*   Updated: 2022/11/25 08:22:23 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// allocating memory for the information from our
// philos and freeing parts of it in the process
// as well
// if specific "wrong" conditions are met, it will go
// to the error function and throw a specific defined
// error according to the situation
bool	allocate_mem_to_status(t_status *status)
{
	status->fork = malloc(sizeof(pthread_mutex_t) * (status->num_of_philo + 1));
	if (status->fork == NULL)
		return (error_thrower(3));
	status->philo = malloc(sizeof(t_philo) * status->num_of_philo);
	if (status->philo == NULL)
	{
		free(status->fork);
		return (error_thrower(3));
	}
	return (true);
}

// using atoi to convert our string input to integers to
// be able to get a value out of them and use it to iterate
// through the arguments
void	store_args_in_status(int len, char *args[], t_status *status)
{
	int	i;

	i = 0;
	status->num_of_philo = ft_atoi(args[i++]);
	status->time_to_die = ft_atoi(args[i++]);
	status->time_to_eat = ft_atoi(args[i++]);
	status->time_to_sleep = ft_atoi(args[i++]);
	status->flagbreak = false;
	status->num_of_eat = 0;
	if (len == 6)
		status->num_of_eat = ft_atoi(args[i]);
}

// using the dot (.) syntax to access the
// members of our dinner structure and initiliase
// our dinnertable with values
// since strings cant be passed as input its important to
// pass only integers (as strings are an array of characters
// and its not possible to pass it via such a struct)
void	init_struct_philo(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_of_philo)
	{
		status->philo[i].id = i + 1;
		if (i == 0)
			status->philo[i].right_fork = status->num_of_philo - 1;
		else
			status->philo[i].right_fork = i - 1;
		status->philo[i].left_fork = i;
		status->philo[i].eat_times = 0;
		status->philo[i].info = status;
		i++;
	}
}

// setting up our structure in general, allocating
// memory for our information that we need to store for
// our philos
bool	init_struct(int argc, char *argv[], t_status *status)
{
	store_args_in_status(argc, argv, status);
	if (!allocate_mem_to_status(status))
		return (false);
	init_struct_philo(status);
	if (!init_mutex(status))
	{
		be_free(status);
		return (error_thrower(4));
	}
	return (true);
}
