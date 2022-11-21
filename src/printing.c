/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:42:32 by abartell          #+#    #+#             */
/*   Updated: 2022/11/21 09:32:29 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// simply printing the output of a given action like eat,
// sleep, die into the terminal, locking it from each thread with its given
// mutex, output is the time and id as a message
void    print_act(char *mess, t_dinner *philo, t_info *info)
{
    if (info->flagbreak)
        return;
    pthread_mutex_lock(&info->print);
    printf(mess, get_timestamp() - info->starttime, philo->id);
    pthread_mutex_unlock(&info->print);
}