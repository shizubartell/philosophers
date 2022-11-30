/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:06 by abartell          #+#    #+#             */
/*   Updated: 2022/11/30 20:21:08 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

//*********************************************************//
//**                DEFINES                             **//

// #if FUN == 1
// # define FORK "%lu %d has taken a chopstick.\n"
// # define SLEEP "%lu %d is taking a nap.\n"
// # define DINNER "%lu %d is eating a bite.\n"
// # define THINK "%lu %d is using his braincells.\n"
// # define DIE "%lu %d forgot how chopsticks work and starved to death.\n"

// #else

// # define FORK "%lu %d has taken a fork.\n"
// # define SLEEP "%lu %d is sleeping.\n"
// # define DINNER "%lu %d is eating.\n"
// # define THINK "%lu %d is thinking.\n"
// # define DIE "%lu %d died.\n"

// # endif

//*********************************************************//
//**                STRUCTURES                          **//

typedef struct s_philo
{
	int					id;
	int					right_fork;
	int					left_fork;
	int					eat_times;
	size_t				last_eat_time;
	pthread_t			thread;
	struct s_status		*status;
}	t_philo;

typedef struct s_status
{
	int				num_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_of_eat;
	int				full_philos;
	int				finish;
	long long		starttime;
	t_philo			*philo;
	pthread_mutex_t	print_mute;
	pthread_mutex_t	*fork;
	pthread_mutex_t	finish_mute;
	pthread_mutex_t	eat_mute;
}	t_status;

//*********************************************************//
//**                FUNCTIONS                           **//
//*******************************************************//

//**** PRINTING.C ****//

int		print_error(char *str);
void	print_status(t_philo *philo, const char *str);

//**** UTILS.C ****//

int		atoi(const char *nptr);
size_t	get_timestamp(void);
void	sleeptimer(t_philo *philo, long long ms);

//**** ACTIONS.C ****//

int		grim_reaper(t_philo *philo);
int		finished(t_philo *philo, int y);

//**** SEARCH_AND_DESTROY.C ****//

int		be_free(t_status *status);
int		mutex_destroyer(t_status *status);
void	join_destroyer(t_status *status);
void	destroyer(t_status *status);

#endif