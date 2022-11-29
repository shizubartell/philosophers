/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:21 by abartell          #+#    #+#             */
/*   Updated: 2022/11/25 08:22:41 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//destroying the mutex for the forks
void	mutex_destroyer(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_of_philo)
	{
		pthread_mutex_destroy(&status->fork[i]);
		i++;
	}
}

bool	check_args(int argc, char *argv[])
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

bool	start_philo(t_status *status)
{
	int			i;
	pthread_t	check;

	status->start_time = get_timestamp();
	if (!thread_num_of_philo(status))
	{
		be_free(status);
		return (error_thrower(5));
	}
	pthread_create(&check, NULL, grim_reaper, status);
	pthread_mutex_unlock(&status->print);
	pthread_join(check, NULL);
	i = 0;
	while (i < status->num_of_philo)
		pthread_join(status->philo[i++].th, NULL);
	return (true);
}

// at the moment only testing if the
// fun mode is enabled or nah
// using memset to be able to copy the
// output of the n-th character to the string
// going through 
int	main(int argc, char *argv[])
{
	t_status	status;

	memset(&status, 0, sizeof(t_status));
	if (argc != 5 && argc != 6)
		return (error_thrower(1));
	if (!check_args(argc - 1, argv + 1))
		return (error_thrower(2));
	if (!init_struct(argc, argv + 1, &status))
		return (1);
	if (!start_philo(&status))
		return (1);
	mutex_destroyer(&status);
	be_free(&status);
	return (0);
}
