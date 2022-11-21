/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:21 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 12:58:24 by abartell         ###   ########.fr       */
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
