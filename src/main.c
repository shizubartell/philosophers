/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:21 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 10:07:01 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
