/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:24:54 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 11:43:39 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// allocating memory for the information from our
// philos and freeing parts of it in the process
// as well
// if specific "wrong" conditions are met, it will go
// to the error function and throw a specific defined
// error according to the situation
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

// using atoi to convert our string input to integers to
// be able to get a value out of them and use it to iterate
// through the arguments
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

// using the dot (.) syntax to access the
// members of our dinner structure and initiliase
// our dinnertable with values
// since strings cant be passed as input its important to
// pass only integers (as strings are an array of characters
// and its not possible to pass it via such a struct)
void	set_dinnertable(t_info *info)
{
	int	i;

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

// setting up our structure in general, allocating
// memory for our information that we need to store for
// our philos
bool	struct_initializer(int argc, char *argv[], t_info *info)
{
	args_put_to_info(argc, argv, info);
	if (!mem_for_infos(info))
		return (false);
	set_dinnertable(info);
	return (true);
}
