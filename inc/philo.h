/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:06 by abartell          #+#    #+#             */
/*   Updated: 2022/11/14 13:01:49 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//*********************************************************//
//**                INCLUDES                            **//

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>

//*********************************************************//
//**                DEFINES                             **//

# define FORK "%lu %d has taken a forky.\n"

//*********************************************************//
//**                STRUCTURES                          **//

typedef struct s_dinner
{
    int                 id;
    int                 right_fork;
    int                 left_fork;
    int                 nb_meals;
    size_t              last_dinnertime;
    pthread_t           ph;
    struct s_info       *info;
	
}			t_dinner;

typedef struct s_info
{
    int                 nb_philos;
    int                 time_to_eat;
    int                 time_to_sleep;
    int                 nb_eaten;
    bool                flagbreak;
    size_t              starttime;
    t_dinner            *philo;
    pthread_mutex_t     print;
    pthread_mutex_t    *fork;
}           t_info;


//*********************************************************//
//**                FUNCTIONS                           **//
//*******************************************************//

//*********************************************************//
//**                MAIN.C                              **//

int			            main(int argc, char **argv);

//*********************************************************//
//**                ACTIONS.C                           **//

//*********************************************************//
//**                PRINTING.C                          **//

void                    print_act(char *mess, t_dinner *philo, t_info *info);

#endif