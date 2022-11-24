/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:21 by abartell          #+#    #+#             */
/*   Updated: 2022/11/24 09:36:17 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//destroying the mutex for the forks
void	mutex_destroyer(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
}

bool	arg_check(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]) || ft_atoi(argv[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

bool	startup(t_info *info)
{
	int			i;
	pthread_t	check;

	info->starttime = get_timestamp();
	if (!thread_nb_philos(info))
	{
		be_free(info);
		return (error_thrower(5));
	}
	pthread_create(&check, NULL, death_counter, info);
	pthread_mutex_unlock(&info->print);
	pthread_join(check, NULL);
	i = 0;
	while (i < info->nb_philos)
		pthread_join(info->philo[i++].thr, NULL);
	return (true);
}

// at the moment only testing if the
// fun mode is enabled or nah
// using memset to be able to copy the
// output of the n-th character to the string
// going through 
int	main(int argc, char **argv)
{
	t_info	info;
	
	memset(&info, 0, sizeof(t_info));
	if (argc != 5 && argc != 6)
		return (error_thrower(1));
	if (!arg_check(argc - 1, argv + 1))
		return (error_thrower(2));
	if (!struct_initializer(argc, argv + 1, &info))
		return (1);
	if (!startup(&info))
		return (1);
	mutex_destroyer(&info);
	be_free(&info);
	return (0);
}
