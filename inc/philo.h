/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:24:06 by abartell          #+#    #+#             */
/*   Updated: 2022/11/24 10:11:52 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

//*********************************************************//
//**                DEFINES                             **//

#if FUN == 1
# define FORK "%lu %d has taken a chopstick.\n"
# define SLEEP "%lu %d is taking a nap.\n"
# define DINNER "%lu %d is eating a bite.\n"
# define THINK "%lu %d is using his braincells.\n"
# define DIE "%lu %d forgot how chopsticks work and starved to death.\n"

#else

# define FORK "%lu %d has taken a fork.\n"
# define SLEEP "%lu %d is sleeping.\n"
# define DINNER "%lu %d is eating.\n"
# define THINK "%lu %d is thinking.\n"
# define DIE "%lu %d died.\n"

# endif

//*********************************************************//
//**                STRUCTURES                          **//

typedef struct s_dinner
{
	int					id;
	int					right_fork;
	int					left_fork;
	int					eat_times;
    size_t				last_dinnertime;
	pthread_t			thr;
	struct s_info		*info;
}			t_dinner;

typedef struct s_info
{
	int                 nb_philos;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eaten;
	bool				flagbreak;
	size_t				starttime;
	size_t				time_to_die;
	t_dinner			*philo;
	pthread_t			check;
	pthread_mutex_t		print;
	pthread_mutex_t		*fork;
}				t_info;

//*********************************************************//
//**                FUNCTIONS                           **//
//*******************************************************//

//*********************************************************//
//**                MAIN.C                              **//

int						main(int argc, char **argv);
void					mutex_destroyer(t_info *info);
bool					startup(t_info *info);
bool					arg_check(int argc, char *argv[]);

//*********************************************************//
//**                ACTIONS.C                           **//

bool					dinning(t_info *info, t_dinner *philo);
bool					take_forks(t_info *info, t_dinner *philo);
void					sleeping(t_info *info, t_dinner *philo);
void					thinking(t_info *info, t_dinner *philo);
void					*daily_life(void *arg);

//*********************************************************//
//**                PRINTING.C                          **//

void					print_act(char *mess, t_dinner *philo, t_info *info);

//*********************************************************//
//**                UTILS.C                             **//

size_t					get_timestamp(void);
void					sleep_to_time(size_t time);
int						ft_isnum(char const *str);
int						ft_isdigit(int c);
int						ft_atoi(const char *str);

//*********************************************************//
//**                INITIALIZE.C                        **//

bool					mem_for_infos(t_info *info);
void					args_put_to_info(int len, char *args[], t_info *info);
void					set_dinnertable(t_info *info);
bool					struct_initializer(int argc, char *argv[], \
						t_info *info);

//*********************************************************//
//**                ERRORERRORERROR.C                   **//

void					be_free(t_info *info);
bool					error_thrower(int input);

//*********************************************************//
//**                THREADING.C                         **//

bool					thread_nb_philos(t_info *info);
bool					mutex_nb_forks(t_info *info);
bool					initialize_mutex(t_info *info);

//*********************************************************//
//**                MONITORING.C                        **//

bool					check_dinnertime(t_info *info, t_dinner *philo, int *count);
void					*death_counter(void *arg);

#endif