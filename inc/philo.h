/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:06 by abartell          #+#    #+#             */
/*   Updated: 2022/12/04 21:30:23 by abartell         ###   ########.fr       */
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
//**                STRUCTURES                          **//

typedef struct s_philo
{
	int				id;
	int				meal_count;
	int				left_fork;
	int				right_fork;
	long long		last_eat_time;
	struct s_info	*info;
	pthread_t		thread;
}					t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				num_full_philo;
	int				finish;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	finish_mutex;
}					t_info;

//*********************************************************//
//**                FUNCTIONS                           **//
//*******************************************************//

//**** PRINTING.C ****//

int			print_error(char *message);
void		print_status(t_philo *philo, const char *message);

//**** UTILS.C ****//

int			ft_atoi(const char *nptr);
long long	get_timestamp(void);
void		sleeping(t_philo *philo, long long ms);

//**** ACTIONS.C ****//

int			grim_reaper(t_philo *philo);
int			check_finish(t_philo *philo, int yes);
void		*philostarter(void *arg);

//**** INITIALIZE.C ****//

int			setup_info(t_info *info, int ac, char **av);
int			setup_philos(t_info *info);
int			setup_mutex(t_info *info);
int			create_philos(t_info *info);

//**** SEARCH_AND_DESTROY.C ****//

int			be_free(t_info *info);
int			mutex_destroyer(t_info *info);
void		join_free_destroy(t_info *info);
void		destroyer(t_info *info);

#endif