/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorerrorerror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:39:51 by abartell          #+#    #+#             */
/*   Updated: 2022/11/19 10:45:28 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	be_free(t_info *info)
{
	free(info->fork);
	free(info->philo);
}

bool	error_thrower(int input)
{
	if (input == 1)
		printf("ERROR!\nToo few or many arguments!\n");
	else if (input == 2)
		printf("ERROR!\nInvalid argument!\n");
	else if (input == 3)
		printf("ERROR!\nFailed to allocate memory!\n");
	return (false);
}