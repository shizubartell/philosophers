/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorerrorerror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:39:51 by abartell          #+#    #+#             */
/*   Updated: 2022/11/22 11:40:48 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// freeing shit
void	be_free(t_info *info)
{
	free(info->fork);
	free(info->philo);
}

// printing an error message according to the
// triggered effect
bool	error_thrower(int input)
{
	if (input == 1)
		printf("ERROR!\nToo few or many arguments!\n");
	else if (input == 2)
		printf("ERROR!\nInvalid argument!\n");
	else if (input == 3)
		printf("ERROR!\nFailed to allocate memory!\n");
	else if (input == 4)
		printf("ERROR!\nFailed to create mutex!\n");
	else if (input == 5)
		printf("ERROR!\nFailed to create thread!\n");
	return (false);
}
