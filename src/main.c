/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:21 by abartell          #+#    #+#             */
/*   Updated: 2022/12/04 21:30:27 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (setup_info(&info, ac, av))
		return (0);
	if (setup_philos(&info))
		return (be_free(&info));
	if (setup_mutex(&info))
		return (mutex_destroyer(&info));
	if (create_philos(&info))
		return (0);
	destroyer(&info);
}
