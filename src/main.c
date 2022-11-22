/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:21 by abartell          #+#    #+#             */
/*   Updated: 2022/11/22 11:33:10 by abartell         ###   ########.fr       */
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
	return (true);
}

// at the moment only testing if the
// fun mode is enabled or nah
int	main(int argc, char **argv)
{
    #if FUN == 1
        printf("Fun mode enabled\n");
    #else
        printf("Serious mode enabled\n");
    #endif
}
